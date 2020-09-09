/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
 Engine Hub Manager

 This file contains the interface definition of engine hub manager. Engine
 hub serves as bridge between GNSS adatpter and engine hub plugins.

 Copyright (c) 2018, 2020 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
 =============================================================================*/
#ifndef __ENGINE_HUB_MGR_H__
#define __ENGINE_HUB_MGR_H__

#include <LocIpc.h>
#include <loc_pla.h>
#include <log_util.h>
#ifdef NO_UNORDERED_SET_OR_MAP
    #include <map>
#else
    #include <unordered_map>
#endif

#ifdef PROTOBUF_ENABLED
#include <EngineHubMsgConverter.h>

// Protobuff message headers
#include "EHMsg.pb.h"
#include "LocationDataTypes.pb.h"
#endif

#ifdef FEATURE_CDFW
// EHUB QDGnss interfacing
#include <EngineHubQDGnssInterface.h>
#endif

using std::unordered_map;
using namespace loc_util;

// Map for storing details of msg counter of each sender.
typedef unordered_map<string, uint32_t> LastRcvMsgCounterMap;

class EngineHubMgr;
class IpcListener;

class AggregatorTimer : public LocTimer {
public:
    AggregatorTimer(EngineHubMgr* engHubMgr, const MsgTask* msgTask);
    void timeOutCallback() override;

private:
    EngineHubMgr* mEngHubMgr;
    const MsgTask* mMsgTask;
};

class EngHubDataItemObserver : public izat_manager::IDataItemObserver {
public:
    EngHubDataItemObserver(EngineHubMgr* engHubMgr);
    virtual ~EngHubDataItemObserver();

    // IDataItemObserver overrides
    void getName(std :: string & name) override;
    void notify(const std::list<IDataItemCore *>& dlist) override;

private:
    EngineHubMgr* mEngHubMgr;
    const std::string mSelfName;
};

class EngineHubMgr {
    friend IpcListener;
public:
    EngineHubMgr(const MsgTask * msgTask,
                 loc_core::IOsObserver* osObserver,
                 loc_core::GnssAdapterReportEnginePositionsEventCb positionEventCb,
                 loc_core::GnssAdapterReportSvEventCb svEventCb,
                 loc_core::GnssAdapterReqAidingDataCb reqAidingDataCb,
                 loc_core::GnssAdapterUpdateNHzRequirementCb updateNHzRequirementCb);

    virtual ~EngineHubMgr();

    // return true if engine hub manager can be initialized properly
    bool init();

    // process session related command from GnssAdapter
    bool processGnssStart();
    bool processGnssStop();
    bool processGnssSetFixMode(const LocPosMode &params);
    bool processGnssDeleteAidingData(const GnssAidingData &aidingData);

    bool processGnssPositionReport(const UlpLocation &location,
                                   const GpsLocationExtended &locationExtended,
                                   enum loc_sess_status status);
    bool processGnssSvReport(const GnssSvNotification& svNotify);
    bool processGnssSvMeasurementReport(const GnssSvMeasurementSet& svMeasurementSet);
    bool processGnssSvPolynomialReport(const GnssSvPolynomial& svPolynomial);
    bool processGnssSvEphemerisReport(const GnssSvEphemerisReport &svEphemeris);
    bool processGnssSystemInfo(const LocationSystemInfo& systemInfo);
    bool processGnssKlobucharIonoModel(const GnssKlobucharIonoModel &ionoModel);
    bool processGnssAdditionalSystemInfo(const GnssAdditionalSystemInfo
            &additionalSystemInfo);
    bool processLeverArmConfig(const LeverArmConfigInfo& configInfo);
    bool processBodyToSensorMountParams(const BodyToSensorMountParams& b2sParams);

    // process system status from EngHubDataItemObserver
    void processSystemStatusUpdate(const std::list<IDataItemCore *>& dlist);

    // process timer expiry from AggregatorTimer that fires per fix interval
    // for position propagation and aggregation logic
    void processAggregatorTimerExpiry();

    // returns true if Protobuff format is enabled.
    inline bool getPbFormatEnabledStatus() {
        return mIsPbFormatEnabled;
    }

    // returns true if Gnss session is On, else false
    inline bool isInGnssSession() {
        return mGnssInSession;
    }

#ifdef FEATURE_CDFW
    // Function invoked from EHUB QDGnss interface to queue the correction
    // mask report to be processed by Engine Hub
    void queueDgnssReportLocMsg(eHubRegReportCorrectionMask reportType,
                                const EHubMessageHeader * msg,
                                int msgSize);
#endif

#ifdef PROTOBUF_ENABLED
    //EngineHub Message Converter helper
    EngineHubMsgConverter mEngHubMsgConverter;
#endif

private:
    // info passed from GnssAdapter, including the
    // msg task that engine hub can use to searialize its processing
    // and callbacks for engine hub to send back sv and postion event
    // received from plugins to GNSS adapter
    const MsgTask* mMsgTask;
    loc_core::GnssAdapterReportEnginePositionsEventCb mPositionEventCb;
    loc_core::GnssAdapterReportSvEventCb mSvEventCb;
    loc_core::GnssAdapterReqAidingDataCb mReqAidingDataCb;
    loc_core::GnssAdapterUpdateNHzRequirementCb mUpdateNHzRequirementCb;

    // routing table info
    uint32_t mRoutingTableNumEntries;
    EHubRoutingTableEntry mRoutingTable[MAX_E_HUB_ENTITY_COUNT];
    // send message counter for each EP
    uint32_t    mSendMsgCounter[MAX_E_HUB_ENTITY_COUNT];

    // Returns the counter to be used for msg to be send for the EP service.
    // index - of EP client in routing table array
    inline uint32_t incrementSendMsgCounter(int index) {
        return (index < MAX_E_HUB_ENTITY_COUNT) ? ++mSendMsgCounter[index] : 0;
    }

    inline uint32_t getSendMsgCounter(int index) {
        return (index < MAX_E_HUB_ENTITY_COUNT) ? mSendMsgCounter[index] : 0;;
    }

    inline uint32_t decrementSendMsgCounter(int index) {
        // Message is not being send to EP. Decrement counter.
        return (index < MAX_E_HUB_ENTITY_COUNT) ? --mSendMsgCounter[index] : 0;
    }

    // Msg sender is EHub - there will be only one instance of EHUB
    // print the send msg counter also
    inline void fillMsgCtrAndSenderName(int index, EHubMessageHeader *msgHdr,
            uint32_t msgCounter) {
        msgHdr->msgCounter = msgCounter;
        strlcpy(msgHdr->msgSenderName, IPC_MSGSENDER_ENGINE_HUB, sizeof(msgHdr->msgSenderName));
        LOC_LOGd("EHUB-Send idx:%d, MsgId: %d, Send_ctr:%d",
                index, msgHdr->msgId, getSendMsgCounter(index));
    }

#ifdef PROTOBUF_ENABLED
    inline void pbPrintSendMsgCounter(int index, EHMsgId msgId) {
        LOC_LOGd("EHUB-Send idx:%d, MsgId: %d, Send_ctr:%d",
                index, msgId, getSendMsgCounter(index));
    }
#endif

    // receive message counter map
    LastRcvMsgCounterMap mLastRcvMsgCounterMap;
    // Compare the current recevied msg counter to the last received
    // msg counter for comparison and update last rcvd msg counter.
    void compareToLastRcvdMsgCounter(const char* sendrName, const char* rcvrName,
            uint32_t msgID, uint32_t rcvMsgCounter);

    // LocIpcSender classes, each routing table entry (other than the engine hub)
    // has a corresponding LocIpcSender,
    // so number of valid entries in mIpcSenderTable matches with
    // mRoutingTableNumEntries.
    shared_ptr<LocIpcSender> mIpcSenderTable[MAX_E_HUB_ENTITY_COUNT];
    LocIpc mLocalIpc;
    LocIpc mInetIpc;

    // cached GNSS session and info
    // currently, GNSS session on/off, position mode and SV polynomial are cached.
    bool mGnssInSession;
    LocPosMode mLocPosMode;

    // Engine hub system status observer
    loc_core::IOsObserver* mOsObserver;
    EngHubDataItemObserver* mDataItemObserver;
    bool mConnectedReceived;
    bool mConnected;

    // GPS time alignment with boot time based on PPS method
    struct timespec mLatchedPpsSyncUserTs;
    bool mPpsAligned;
    struct timespec mPpsAlignedBootTimeTs;
    GPSTimeStruct mPpsAlignedGpsTime;

    // GPTP intialization
    bool mIsGptpInitialized;

    // nHz requirement
    bool mNHzNeeded;
    // nHz Meas Requirement
    bool mNHzMeasNeeded;

#ifdef FEATURE_CDFW
    // EHUB QDGnss interfacing
    EngineHubQDGnssInterface* mEhubQdgnssIface;

    // This method below is called for engine hub to process
    // CDFW reports that are synchronized on the loc msg queue.
    int processReportCdfwMsg(eHubRegReportCorrectionMask reportId,
                            const uint8_t * msg, size_t msgSize);
#endif

    // Position report aggregator
    EngineHubAggregator* mAggregator;
    AggregatorTimer* mAggregatorTimer;
    // The fix interval for the current timer
    uint32_t mCurrentTimerIntervalMsec;
    // The boot timer that the pending timer is expected to expire at
    uint64_t mCurrentTimerBootMsec;
    // Is protobuf format enabled
    bool  mIsPbFormatEnabled;

    // cached lever arm info
    LeverArmConfigInfo mLeverArmConfigInfo;
    bool mB2sMountParamsValid;
    BodyToSensorMountParams mB2sMountParams;

    // Generic message to print msgs being sent out from EHub
    void printMsgSendInfo(EHubMsgId msgId,
            const EHubRoutingTableEntry &routingTableEntry, size_t msgSize);
    void printReportSendInfo(eHubRegReportMask reportId,
            const EHubRoutingTableEntry &routingTableEntry, size_t msgSize);
    bool isEngHubSocketEntry(const EHubRoutingTableEntry &routingTableEntry);

    // All engine hub processing need to be synchronized using the
    // location message queue, this includes:
    // 1: command and report calls from GNSS adapter into engine hub
    // 2: messages sent by engine plugins to engine hub
    // Below two queue methods are used to achieve that.
    void queueRegisterLocMsg(const EHubMessageProtocolRegMsg* msg);
    void queueReportLocMsg(eHubRegReportMask reportType,
                           const EHubMessageHeader * msg,
                           int msgSize);

    // The three methods below are called for engine hub to process
    // GNSS session cmd that are synchronized on the loc msg queue.
    void processStartLocMsg();
    void processStopLocMsg();
    void processSetFixModeLocMsg(const LocPosMode &posMode);

    // This method below is called for engine hub to process
    // GNSS reports (position and sv) that are synchronized
    // on the loc msg queue.
    int processReportLocMsg(eHubRegReportMask reportId,
                            const uint8_t * msg, size_t msgSize);

    // This method below is called for engine hub to process
    // leap second info and leap second change event that are
    // synchronized on the loc msg queue.
    void processLeapSecondInfoLocMsg(GPSTimeStruct gpsTimestampLsChange,
                                     uint8_t leapSecBefore,
                                     uint8_t leapSecAfter,
                                     uint8_t leapSecCurrent);

    // This method is called for engine hub to process engine plugin
    // registration message that are synchronized on the loc msg queue.
    int processRegisterLocMsg(const EHubMessageProtocolRegMsg* msg);

    // This method is called for engine hub to process lever arm
    // configuration message that are synchronized on the loc msg queue.
    int processLeverArmConfigLocMsg(const LeverArmConfigInfo& configInfo);

    // This method is called for engine hub to process the body frame mount
    // info that are synchronized on the loc msg queue.
    int processBodyToSensorMountParamsLocMsg(
            const BodyToSensorMountParams& b2sParams);

    // Upon every engine hub boot up, this method is called for
    // engine hub to enumerate through the socket folder used solely
    // between engine hub and engine plugin, and send eng hub up msg
    // to every socket file (excludng eng hub socket). This is to inform
    // all plugins that are already up that engine hub is up running.
    int broadcastEngineHubUp();

    // this method is used to broadcast GNSS session related engine hub
    // messages to every plugin that has registered for GNSS reports.
    // We are pass msgId to this function as parameter, so that we can avoid the
    // extra step to deserialise the sending data in PB format just to get the
    // msgid and print to log. In case of rigid structure, we can easily get
    // it from the message itself, but not that easy for PB format.
    // eg:
    //      EHubMessageHeader *header = (EHubMessageHeader *)msg;
    //      header->msgId;
    int broadcastEhubGnssSessionMsg(EHubMsgId msgId, const uint8_t * msg, size_t msgSize);

    // this method is used to dispatch an engine hub status msg that need
    // to be sent to those plugins who register for the update,
    // e.g.: data connectivity status update
    // We are pass msgId to this function as parameter, so that we can avoid the
    // extra step to deserialise the sending data in PB format just to get the
    // msgid and print to log. In case of rigid structure, we can easily get
    // it from the message itself, but not that easy for PB format.
    // eg:
    //      EHubMessageHeader *header = (EHubMessageHeader *)msg;
    //      header->msgId;
    int dispatchEhubStatusMsg(EHubMsgId msgId, eHubRegStatusMask statusId,
                              const uint8_t * msg, size_t msgSize);

#ifdef PROTOBUF_ENABLED
    // Similar to broadcastEhubGnssSessionMsg, for protobuf enabled case
    int pbBroadcastEhubGnssSessionMsg(const string &ehMsgPayLoad, EHMsgId msgId);

    // Similar to dispatchEhubStatusMsg, for protobuf enabled case
    int pbDispatchEhubStatusMsg(const string &ehMsgPayLoad, EHMsgId msgId,
                eHubRegStatusMask statusId);

    // To serialize status/session message etc to EHMsg and send in PBformat
    void serializeToEHMsgAndSend(const string &ehMsgPayLoad, EHMsgId msgId, int index);
#endif

    // timestamp of position report and SV measurement based on PPS method
    // and also record down the association between GPS timestamp and
    // AP boot time.
    void timestampPPS(GPSTimeStruct *gpsTime,
                      struct timespec *pktTimeStamp,
                      float *pktTimeUncMs);

    // set up the next aggregator timer based on fix interval and
    // PPS time synchronization method to align report on GPS integer second.
    bool setupAggregatorTimer();

    // This function returns true if the msg need to be sent. If the msg
    // content need to be changed due to the constellation based filtering,
    // the new content will be held in outMsg and the size of the outMsg
    // can be found at outMsgSize. After using the outMsg, the memory pointed
    // by outMsg need to be freed via free.
    //
    // If constellation based filtering is not needed, then the original
    // message and message size need to be sent out and outMsg will be nullptr.
    //
    // This function returns false if the message after filtering becomes empty.
    bool getMsgBasedOnSubModifiers(eHubRegReportMask reportId,
                                   const EHubRoutingTableEntry *regInfo,
                                   const  uint8_t * inMsg,
                                   uint8_t * &outMsg,
                                   size_t &outMsgSize,
                                   uint32_t msgCounter);

    // This function returns true if the SV meas msg need to be sent. If the msg
    // content need to be changed due to the constellation based filtering,
    // the new content will be held in outMsg and the size of the outMsg
    // can be found at outMsgSize. After using the outMsg, the memory pointed
    // by outMsg need to be freed via delete.
    //
    // If constellation based filtering is not needed, then the original
    // message and message size need to be sent out and outMsg will be nullptr.
    //
    // This function returns false if the message after filtering becomes empty.
    bool getSvMeasMsgBasedOnSubModifiers(eHubSubscriptionModifier subModifiers,
                                         const EHubMessageReportSvMeas * inMsg,
                                         uint8_t * &outMsg,
                                         size_t &outMsgSize);

#ifdef PROTOBUF_ENABLED
    // This function is similar to getSvMeasMsgBasedOnSubModifiers except that
    // outMsg will be PB format structure
    bool getPbSvMeasMsgBasedOnSubModifiers(eHubSubscriptionModifier subModifiers,
                                           const EHubMessageReportSvMeas * inMsg,
                                           uint8_t * &outMsg,
                                           size_t &outMsgSize,
                                           uint32_t msgCounter);
#endif

    // This function returns true if client does registers for the sv constellation
    // for this ephemeris.
    bool sendSvEphMsgBasedOnSubModifiers(eHubSubscriptionModifier subModifiers,
                                         const EHubMessageReportSvEphemeris * inMsg,
                                         uint8_t * &outMsg,
                                         size_t &outMsgSize);

#ifdef PROTOBUF_ENABLED
    // This function is similar to sendSvEphMsgBasedOnSubModifiers except that
    // outMsg will be PB format structure
    bool sendPbSvEphMsgBasedOnSubModifiers(eHubSubscriptionModifier subModifiers,
                                         const EHubMessageReportSvEphemeris * inMsg,
                                         uint8_t * &outMsg,
                                         size_t &outMsgSize,
                                         uint32_t msgCounter);
#endif

    // This function returns true if client does registers for the sv constellation
    // for this poly.
    bool sendSvPolyMsgBasedOnSubModifiers(eHubSubscriptionModifier subModifiers,
                                          const EHubMessageReportSvPolynomial * inMsg);

    bool svNeededBasedOnSvId(GnssConstellationTypeMask regConstellationMask,
                             uint16_t gnssSvId);

    bool svNeededBasedOnSvSystem(GnssConstellationTypeMask regConstellationMask,
                                 Gnss_LocSvSystemEnumType gnssSystem);
};

#endif // #ifndef __ENGINE_HUB_MGR_H__
