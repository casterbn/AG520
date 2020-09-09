/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2013-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#ifndef IZAT_API_V02_H
#define IZAT_API_V02_H

#include <LocApiV02.h>
#include <IzatApiBase.h>
#include <geofence.h>
#include <vector>

namespace lbs_core {
    class LocApiProxyV02;
};

using namespace loc_core;
using namespace lbs_core;

namespace izat_core {

class IzatApiV02 : public IzatApiBase {
    size_t mBatchSize, mDesiredBatchSize;
    size_t mTripBatchSize, mDesiredTripBatchSize;

    LocationError queryBatchBuffer(size_t desiredSize,
            size_t &allocatedSize, BatchingMode batchMode);
    LocationError releaseBatchBuffer(BatchingMode batchMode);
    void readModemLocations(FlpExtLocation* pLocationPiece, size_t count,
            BatchingMode batchingMode, size_t& numbOfEntries);
    void setOperationMode(GnssSuplMode mode);

    void fillGeneralAssistData(GnssAidingDataMask flags,
                               qmiLocDeleteAssistDataReqMsgT_v02 &req);
    void fillSvInfoAssistData(GnssAidingDataMask flags,
                              qmiLocDeleteAssistDataReqMsgT_v02 &req);
    bool needsNewTripBatchRestart(uint32_t newTripDistance, uint32_t newTripTBFInterval,
            uint32_t &accumulatedDistance, uint32_t &numOfBatchedPositions);
public:
    IzatApiV02(LocApiProxyV02* locApiProxy);
    inline virtual ~IzatApiV02() {}

    void sendMsg(const LocMsg* msg);

    inline virtual void* getSibling() { return (IzatApiBase*)this; }

    /* event callback registered with the loc_api v02 interface */
    virtual int eventCb(locClientHandleType client_handle,
                         uint32_t loc_event_id,
                         locClientEventIndUnionType loc_event_payload);

    // Tracking
    void startTimeBasedTracking(const TrackingOptions& options, LocApiResponse* adapterResponse);
    void stopTimeBasedTracking(LocApiResponse* adapterResponse);
    void startDistanceBasedTracking(uint32_t sessionId,
                                    const LocationOptions& options,
                                    LocApiResponse* adapterResponse);
    void stopDistanceBasedTracking(uint32_t sessionId, LocApiResponse* adapterResponse);

    // Batching
    void startBatching(uint32_t sessionId, const LocationOptions& options,
                       uint32_t accuracy, uint32_t timeout,
                       LocApiResponse* adapterResponse);
    void stopBatching(uint32_t sessionId, LocApiResponse* adapterResponse);
    LocationError startOutdoorTripBatchingSync(uint32_t tripDistance,
                                               uint32_t tripTbf,
                                               uint32_t timeout);
    void startOutdoorTripBatching(uint32_t tripDistance,
                                       uint32_t tripTbf,
                                       uint32_t timeout,
                                       LocApiResponse* adapterResponse);
    void reStartOutdoorTripBatching(uint32_t ongoingTripDistance,
                                         uint32_t ongoingTripInterval,
                                         uint32_t batchingTimeout,
                                         LocApiResponse* adapterResponse);
    LocationError stopOutdoorTripBatchingSync(bool deallocBatchBuffer = true);
    void stopOutdoorTripBatching(bool deallocBatchBuffer = true,
                                      LocApiResponse* adapterResponse = nullptr);
    LocationError getBatchedLocationsSync(size_t count);
    void getBatchedLocations(size_t count,
                                  LocApiResponse* adapterResponse);
    LocationError getBatchedTripLocationsSync(size_t count, uint32_t accumulatedDistance);
    void getBatchedTripLocations(size_t count, uint32_t accumulatedDistance,
                                      LocApiResponse* adapterResponse);
    virtual void setBatchSize(size_t size);
    virtual void setTripBatchSize(size_t size);
    LocationError queryAccumulatedTripDistanceSync(uint32_t &accumulatedTripDistance,
            uint32_t &numOfBatchedPositions);
    void queryAccumulatedTripDistance(
            LocApiResponseData<LocApiBatchData>* adapterResponseData);
    // Geofence
    virtual void addGeofence(uint32_t clientId,
                             const GeofenceOption& options,
                             const GeofenceInfo& info,
                             uint8_t confidence,
                             LocApiResponseData<LocApiGeofenceData>* adapterResponseData);
    virtual void removeGeofence(uint32_t hwId, uint32_t clientId, LocApiResponse* adapterResponse);
    virtual void pauseGeofence(uint32_t hwId, uint32_t clientId, LocApiResponse* adapterResponse);
    virtual void resumeGeofence(uint32_t hwId, uint32_t clientId, LocApiResponse* adapterResponse);
    virtual void modifyGeofence(uint32_t hwId, uint32_t clientId,
                                const GeofenceOption& options, LocApiResponse* adapterResponse);

    virtual void setInSession(bool inSession);
    virtual void setUserPref(bool user_pref);
    virtual void injectApCache(APCacheData data, LocApiResponse* adapterResponse);
    virtual void injectApCacheBlacklist(APCacheBlacklistData data, LocApiResponse* adapterResponse);
    virtual void sendBestAvailablePosReq(LocApiResponseData<LocGpsLocation>* adapterResponseData);
    virtual void sendBestAvailablePosReq(LocPosTechMask &tech_mask,
                                         LocApiResponseData<LocGpsLocation>* adapterResponseData);

    // for TDP
    virtual void sendGtpEnhancedCellConfigBlocking(e_premium_mode mode,
                                                   LocApiResponse* adapterResponse);
    virtual void sendGtpCellConfigurationsBlocking(const char* data, uint32_t len,
                                                   LocApiResponse* adapterResponse);

    virtual void sendGdtUploadBeginResponse(int32_t service, int32_t session, int32_t status,
                                            LocApiResponse* adapterResponse);
    virtual void sendGdtUploadEndResponse(int32_t service, int32_t session, int32_t status,
                                          LocApiResponse* adapterResponse);

    virtual void sendGtpApStatus(int32_t gtpApDbStatus, uint64_t gtpApPcid64, int8_t gtpApPcid64_valid,
                                 const char* oemId, int8_t oemId_valid,
                                 const char* modelId, int8_t modelId_valid,
                                 LocApiResponse* adapterResponse);

    virtual void sendGdtDownloadBeginResponse(int32_t service, uint32_t session, int32_t status,
                                              const uint8_t* respLocInfo, int8_t respLocInfo_valid,
                                              uint32_t respLocInfo_len, uint32_t remainingThrottleTime,
                                              int8_t remainingThrottleTime_valid,
                                              LocApiResponse* adapterResponse);
    virtual void sendGdtDownloadReadyStatus(int32_t service, uint32_t session, int32_t status,
                                            const char* filePath,
                                            LocApiResponse* adapterResponse);
    virtual void sendGdtReceiveDoneResponse(int32_t service, uint32_t session, int32_t status,
                                            LocApiResponse* adapterResponse);
    virtual void sendGdtDownloadEndResponse(int32_t service, uint32_t session, int32_t status,
                                            LocApiResponse* adapterResponse);

    // for CSM
    virtual void sendCsmConfig(bool enable_cs_mask_valid, uint32_t enable_cs_mask,
                              bool source_mask_valid, uint32_t source_mask,
                              bool local_config_valid, bool on_demand_enabled, bool on_unsolicted_gnss_enabled,
                              bool battery_level_throttling_enabled, bool rtt_cs_enabled, bool rtt_3_cs_enabled,
                              int32_t rtt_signal_dbm_threshold, uint16_t max_data_transfer_format_ver_supported,
                              bool server_config_len_valid, uint32_t server_config_len, const char * server_config);

    virtual void readMpCsData();

    // XTRA Client 2.0
    virtual void setXtraVersionCheck(enum XtraVersionCheck check);
    virtual void injectIzatPcid(uint64_t pcid);
    virtual void injectXtraData_legacy(const char* data, uint32_t len);
    virtual void injectXtraData(const char* data, uint32_t len,
                                bool legacyRetry, LocApiResponse* adapterResponse);
    virtual void injectNtpTime(const int64_t time, const int64_t reference, const int64_t uncertainty);
    virtual void requestXtraServers(LocApiResponse* adapterResponse);
    virtual void requestXtraConfigInfo(const uint32_t configMask, const uint32_t configReqSource);

    virtual void addToCallQueue(LocApiResponse* adapterResponse);

private:
    void batchFullEvent(const qmiLocEventBatchFullIndMsgT_v02* batchFullInfo);
    void batchStatusEvent(const qmiLocEventBatchingStatusIndMsgT_v02* batchStatusInfo);
    void onDbtPosReportEvent(const qmiLocEventDbtPositionReportIndMsgT_v02* pDbtPosReport);
    void geofenceBreachEvent(const qmiLocEventGeofenceBreachIndMsgT_v02* breachInfo);
    void geofenceBreachEvent(const qmiLocEventGeofenceBatchedBreachIndMsgT_v02* batchedBreachInfo);
    void geofenceStatusEvent(const qmiLocEventGeofenceGenAlertIndMsgT_v02* alertInfo);
    void geofenceDwellEvent(const qmiLocEventGeofenceBatchedDwellIndMsgT_v02 *dwellEvent);
    void onGdtUploadBeginEvent(const qmiLocEventGdtUploadBeginStatusReqIndMsgT_v02* pInfo);
    void onGdtUploadEndEvent(const qmiLocEventGdtUploadEndReqIndMsgT_v02* pInfo);
    void onGdtDownloadBeginEvent(const qmiLocEventGdtDownloadBeginReqIndMsgT_v02* pInfo);
    void onGdtReceiveDoneEvent(const qmiLocEventGdtReceiveDoneIndMsgT_v02* pInfo);
    void onGdtDownloadEndEvent(const qmiLocEventGdtDownloadEndReqIndMsgT_v02* pInfo);
    void onCsmControlResp(const qmiLocCrowdSourceManagerControlIndMsgT_v02* pInfo);

    locClientStatusEnumType locSyncSendReq(uint32_t req_id, locClientReqUnionType req_payload,
            uint32_t timeout_msec, uint32_t ind_id, void* ind_payload_ptr);
    locClientStatusEnumType locClientSendReq(uint32_t req_id, locClientReqUnionType req_payload);

    // Utils
    static qmiLocPowerModeEnumT_v02 convertPowerMode(GnssPowerMode powerMode);
};

}  // namespace izat_core

#endif //IZAT_API_V02_H
