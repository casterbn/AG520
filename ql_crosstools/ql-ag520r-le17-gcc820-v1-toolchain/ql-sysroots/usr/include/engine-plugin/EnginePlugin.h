/******************************************************************************
    Copyright (c) 2018, 2020 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.
 *******************************************************************************/
#ifndef ENGINE_PLUGIN_H
#define ENGINE_PLUGIN_H

#include <string>
#include <map>
#include "LocIpc.h"
#include "gps_extended.h"
#include "msg_q.h"
#include <MsgTask.h>
#include <loc_pla.h>
#include <log_util.h>
#include "EngineHubMsg.h"
#include "EnginePluginImpl.h"
#include "EnginePluginMsgConverter.h"
#include "EnginePluginControll.h"
#include "EnginePluginLogImpl.h"
#include "EnginePluginDRStorage.h"
#include "EnginePluginQwesIface.h"
#include "NtripClientIntegrationApi.h"

using namespace std;
using namespace loc_util;

#define EP_SOCKET_FILE_NAME SOCKET_DIR_EHUB "ep.socket."
#define EP_IP_ADDR_ANY "0.0.0.0"
namespace engine_plugin {
#define EP_MAX_NONCE_BUFF_SIZE     (2*1024)  //2K

typedef uint32_t epInterface;
#define EP_INTERFACE         (1)
#define EP_IMPL_INTERFACE    (2)

typedef uint32_t epEngineType;
#define EP_ENGINE_TYPE_PPE (1)
#define EP_ENGINE_TYPE_DR  (2)
#define EP_ENGINE_TYPE_VPE (3)

typedef uint32_t epEngineProcessorType;
#define EP_ENGINE_PROCESSOR_TYPE_LOCAL  (1)
#define EP_ENGINE_PROCESSOR_TYPE_EXTERNAL (2)

typedef struct {
    char epVendorEngineType[124];
    epInterface interfaceType;
    epEngineType engineId;
} epModuleMapping;

// Map for storing details of msg counter of each sender.
typedef map<string, uint32_t> LastRcvMsgCounterMap;

class IpcListener;

typedef void (*startCorrectionDataStreaming)(CorrectionDataCb cb);
typedef void (*stopCorrectionDataStreaming)();


class EnginePlugin : public LocIpc {
    friend IpcListener;
public:
    void* mMainQ;
    EHubTechId mTechID;
    // singleton instance
    static EnginePlugin* getInstance();

    bool registerInterface(const EPInterface* pEPInterface);
    bool registerInterface(const EPImplInterface* pEPImplInterface);

    bool init(epEngineType engineId, epInterface ifaceType, const char* libName);
    bool init(epEngineType engineId, epInterface ifaceType,
            epEngineProcessorType processorType,
            const struct EPInterface* epIface,
            struct EPCallbacks** pEpCallbacks);
    bool init(epEngineType engineId, epInterface ifaceType,
            epEngineProcessorType processorType,
            const EPImplInterface* epImplIface,
            EPImplCallbacks** pEpImplCallbacks);
    void initCommon(epEngineType engineId, epInterface ifaceType,
            epEngineProcessorType processorType);
    bool versionCheck(uint16_t ePClientMajorVersion);
    eHubRegReportMask getGnssSubMask();
    void decodeFromRigidData(const char* data, uint32_t length, const char* rcvrName);
#ifdef PROTOBUF_ENABLED
    uint32_t pbGetGnssSubMask();
    void decodeFromPbData(const char* data, uint32_t length, const char* rcvrName);
    bool pbRegisterWithEHub();
#endif
    bool registerWithEHub();
    /* Reporting from EngineHub to EnginePLugin API's */
    void processRoutingTableUpdateCmd(const EHubMessageProtocolRoutingTableUpdate * msg);
    void getVersionInfo();
    void processRegistrationCmd();
    void processDeviceIdReqCmd();
    void provideConnectionStatus(bool isConnected);
    void sendDefaultConnectionStatus();
    void processStartFixCmd();
    void processStopFixCmd();
    void processFixModeCmd(const EHubMessageSessionSetFixMode * msg);
    void processDeleteAidingDataCmd(const EHubMessageSessionDeleteAidingData * msg);
    void processPositionRptCmd(const EHubMessageReportPosition * msg);
    void processSvMeasCmd(const EHubMessageReportSvMeas * msg);
    void processSvEphCmd(const EHubMessageReportSvEphemeris * msg);
    void processSvPolyCmd(const EHubMessageReportSvPolynomial * msg);
    void processSvInfoCmd(const EHubMessageReportSv * msg);
    void processLeverArmConfCmd(const EHubMessageStatusLeverArmConfig * msg);
#ifdef PROTOBUF_ENABLED
    void pbProcessRoutingTableUpdateCmd
    (
        const EHMessageProtocolRoutingTableUpdate * msg
    );
    void pbProcessRegistrationCmd();
    void pbProcessFixModeCmd(const EHMessageSessionSetFixMode * msg);
    void pbProcessDeleteAidingDataCmd(const EHMessageSessionDeleteAidingData * msg);
    void pbProcessPositionRptCmd(const EHMessageReportPosition * msg);
    void pbProcessSvMeasCmd(const EHMessageReportSvMeas *msg);
    void pbProcessSvEphCmd(const EHMessageReportSvEphemeris * msg);
    void pbProcessSvPolyCmd(const EHMessageReportSvPolynomial * msg);
    void pbProcessSvInfoCmd(const EHMessageReportSv * msg);
    void pbSendFixMode(const EHMessageSessionSetFixMode *pEhubFixMode);
    void pbSendDeleteAidingData(const EHMessageSessionDeleteAidingData *pEhubDeleteData);
    void pbProvidePosition(const EHMessageReportPosition *pEHubPosRpt);
    void pbProvideSvMeasurement(const EHMessageReportSvMeas *pEHubMsrRpt);
    void pbProvideSvEphemeris(const EHMessageReportSvEphemeris *pEHubEphRpt);
    void pbProvideSvPolynomial(const EHMessageReportSvPolynomial *pEhubSvPoly);
    void pbProvideSvInfo(const EHMessageReportSv *svRpt);
    void pbProcessLeverArmConfCmd(const EHMessageStatusLeverArmConfig * msg);
    void pbProvideLeverArmConfData
    (
        const EHMessageStatusLeverArmConfig *pEHubLeverArmConfRpt
    );
    void pbProcessB2SParamsCmd(const EHMessageStatusB2sMountParams *msg);
    void pbProvideB2SMountParamsData(const EHMessageStatusB2sMountParams *pEHubB2sInfo);
#endif
    void sendEPError(epError err);
    void sendErrorMsg(epError err);
    void processConnectionStatusCmd(bool isConnected);
    void sendStartFix();
    void sendStopFix();
    void sendFixMode(const EHubMessageSessionSetFixMode *pEhubFixMode);
    void sendDeleteAidingData(const EHubMessageSessionDeleteAidingData *pEhubDeleteData);
    void providePosition(const EHubMessageReportPosition *pEHubPosRpt);
    void provideSvMeasurement(const EHubMessageReportSvMeas *pEHubMsrRpt);
    void provideSvEphemeris(const EHubMessageReportSvEphemeris *pEHubEphRpt);
    void provideSvPolynomial(const EHubMessageReportSvPolynomial *pEHubSvPoly);
    void provideSvInfo(const EHubMessageReportSv *svRpt);
    void processCorrectionDataCmd(uint8_t *pCorrectionData, uint32_t lengthInBytes);
    void processAttestationStatementReq(unsigned char* nonce, size_t lengthOfNonce,
            uint8_t *data, uint32_t lengthOfData);
    void provideAttestationStatement();
    void processInstallLicenseReq(uint8_t *licenseBuffer,
            uint32_t lengthOfLicenseBuffer);
    void processInstallLicense(const uint8_t *licenseBuffer,
            uint32_t lengthOfLicenseBuffer);
    /* Reporting from EnginePLugin API's to EngineHUb */
    void updateRoutingTable(const EHubMessageProtocolRoutingTableUpdate * msg);
#ifdef PROTOBUF_ENABLED
    void pbUpdateRoutingTable(const EHMessageProtocolRoutingTableUpdate * msg);
#endif
    void handleReportPosition(const epPVTReport* msg,
            const struct timespec& bootTs);
    void handleImplReportPosition(const epImplPVTReport* msg,
        const struct timespec& bootTs);
    void handleReportSvInfo(const epGnssSvNotification* msg);
    void handleReportStatusResp(uint32_t status);
    void handleReportSubscriptionInfo(const epSubscriptionInfo* msg);
    bool reportPositionToEHub(const epImplPVTReport * pvtReport,
            const struct timespec& bootTs);
    bool reportSvStatusToEHub(const epGnssSvNotification* pEpSvReport);
    void reportStatusRespToDiag(uint32_t status);
    void updateReportSubscription(const epSubscriptionInfo* pEpSubInfo);
    void handleReportLogMessage(uint32_t moduleID, epLogLevelType logLevel,
            uint32_t logLength, const uint8_t* logMessage, epLogType logType);
    bool reportLogMsgToDiag(uint32_t moduleID, epLogLevelType logLevel,
            uint32_t logLength, const uint8_t* logMessage, epLogType logType);
    epPVTSourceType getPositionSource(EHubTechId sourceTechId);
    void provideLeverArmConfData
    (
        const EHubMessageStatusLeverArmConfig *pEHubLeverArmConfRpt
    );
#ifdef PROTOBUF_ENABLED
    epPVTSourceType pbGetPositionSource(EHTechId sourceTechId);
#endif
    void waitForSocketDir(const char *dirPath);

    void destroy();
    static void epMsgFree(void* msg);
    int msgToMainQsend(void *pMsgObj);
    bool isExitMsgRecv();
    EHubTechId getEhubTechId(epEngineType engineId);
    int readNVMData(epNVStorageData* nvInfo);
    int writeNVMData(const epNVStorageData* nvInfo);
    int deleteNVMData(const epNVStorageData* nvInfo);
    void processFeatureStatusReq();
    epFeatureStatus getFeatureStatus();
    void updateFeatureStatus();
    void provideFeatureStatus();
    bool logLevelCheck(epLogLevelType logLevel);
    bool logTypeCheck(epLogType logType);
    void providecorrectionData(uint8_t *correctionData, uint32_t lengthInBytes);
    void processIonoCmd(const EHubMessageReportKlobucharIonoModel * msg);
    void provideSvIonoData(const EHubMessageReportKlobucharIonoModel *pEHubEphRpt);
    void processGloAddParamsCmd(const EHubMessageReportGlonassAdditionalParams * msg);
    void provideGloAddParamsData
    (
        const EHubMessageReportGlonassAdditionalParams *pEHubAddParamsRpt
    );
    void processB2SParamsCmd
    (
        const EHubMessageStatusB2sMountParams *msg
    );
    void provideB2SMountParamsData
    (
         const EHubMessageStatusB2sMountParams *pEHubB2sInfo
    );
#ifdef FEATURE_CDFW
    void processQDgnssReferenceStationCmd(const EHubMessageReportCdfwQDgnssReferenceStation *msg);
    void processQDgnssObservationCmd(const EHubMessageReportCdfwQDgnssObservation *msg);
    void provideQDgnssReferenceStationData
    (
        const EHubMessageReportCdfwQDgnssReferenceStation *pEHubQDgnssRefStationInfo
    );
    void provideQDgnssObservationData
    (
        const EHubMessageReportCdfwQDgnssObservation *pEHubQDgnssObserInfo
    );
#ifdef PROTOBUF_ENABLED
    void pbprocessQDgnssReferenceStationCmd(const EHMessageReportCdfwQDgnssReferenceStation *msg);
    void pbprocessQDgnssObservationCmd(const EHMessageReportCdfwQDgnssObservation *msg);
    void pbProvideQDgnssReferenceStationData(
        const EHMessageReportCdfwQDgnssReferenceStation *pEHubQDgnssRefStationInfo
    );
    void pbProvideQDgnssObservationData(
        const EHMessageReportCdfwQDgnssObservation *pEHubQDgnssObserInfo
    );
#endif //PROTOBUF_ENABLED
#endif //FEATURE_CDFW

#ifdef PROTOBUF_ENABLED
    void pbProcessIonoCmd(const EHMessageReportKlobucharIonoModel * msg);
    void pbProvideSvIonoData(const EHMessageReportKlobucharIonoModel *pEHubIonoRpt);
    void pbProcessGloAddParamsCmd(const EHMessageReportGlonassAdditionalParams * msg);
    void pbProvideGloAddParamsData
    (
        const EHMessageReportGlonassAdditionalParams *pEHubAddParamsRpt
    );
#endif
    void startCorrectionDataStreamReq();
    void stopCorrectionDataStreamReq();
    void startExternalCorrDataStreaming();
    void stopExternalCorrDataStreaming();
    inline bool isInternalStreamingUsed() { return mUseInternalCorrDataStreaming; }
    inline bool isSessionStarted() { return mSessionStarted;}
    void qwesSyncCb();
    void handleQwesSyncCb();
private:
    epEngineProcessorType  mEngineProcessorType;
    bool                mIsListenerReady;
    MsgTask*            mMsgTask;
    static EnginePlugin *mInstance;
    EnginePluginControl mEpCtrlInstance;
    pthread_t           mThreadId;
    EPImplInterface     mEPImplIface;
    EpMsgConverter      mMsgConverter;
    epSubscriptionInfo  mEpClientSubInfo;
    std::string         mSockName;
    epEngineServiceInfo mEngineServiceInfo;
    EPDiagLogMsg        mDiagObj;
    EPDRStorage         *mDRNVMStorage;
    EnginePluginQwesIface mQwesObj;
    int                 mFeatureID;
    bool                 mIsPbFormatEnabled;
    bool                 mLicenseInstalled;
    epFeatureStatus     mFeatureStatus;
    epLicenseType       mFeatureType;
    uint8_t             mNonce[EP_MAX_NONCE_BUFF_SIZE];
    uint32_t            mLengthOfNonce;
    uint8_t             mData[EP_MAX_NONCE_BUFF_SIZE];
    uint32_t            mLengthOfData;
    shared_ptr<LocIpcSender> mIpcSender;
    bool                mSessionStarted;

    // External or third-party correction data streaming related
    void*               mNtripClientLibHandle;
    startCorrectionDataStreaming mPtrFnStartCorrDataStreaming;
    stopCorrectionDataStreaming  mPtrFnStopCorrDataStreaming;
    bool                mUseInternalCorrDataStreaming;

    // receive message counter map
    LastRcvMsgCounterMap mLastRcvMsgCounterMap;
    // Compare the current recevied msg counter to the last received
    // msg counter for comparison and update last rcvd msg counter.
    void compareToLastRcvdMsgCounter(const char* sendrName, const char* rcvrName,
            uint32_t msgID, uint32_t rcvMsgCounter);
    bool                mIsGptpInitialized;

    char * getEngineIdName(epEngineType engineId);
    char * getSourceTechIDName(EHubTechId techId);
    void setFeatureId();
    void fillSubscriptionMask(eHubSubModifiers &subMods);
#ifdef PROTOBUF_ENABLED
    char * pbGetSourceTechIDName(EHTechId techId);
    void pbFillSubscriptionMask(EHSubModifiers *subMods);
#endif
    void handleVersionMisMatchErr();
    void featureForceSync();

    EnginePlugin();
    ~EnginePlugin();
};

}
#endif /*ENGINE_PLUGIN_H */
