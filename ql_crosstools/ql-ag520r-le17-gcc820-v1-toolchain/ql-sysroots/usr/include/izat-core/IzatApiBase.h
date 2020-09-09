/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2013-2017 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
#ifndef IZAT_API_BASE_H
#define IZAT_API_BASE_H

#include <WiperData.h>
#include <LocApiBase.h>
#include <ContextBase.h>
#include <geofence.h>
#include <LBSApiBase.h>
#include "fused_location_extended.h"

#define GTP_LP_MAX_ALLOWED_APS 80
#define GTP_LP_QMI_VERSION 1

using namespace loc_core;
using namespace lbs_core;

typedef struct
{
  uint64_t macaddress_48b;
  float latitude;
  float longitude;
  float horUncCircular;
  uint8_t hepeValid;
  uint16_t hepe;
  int8_t apReliability;
} APInfo;

typedef struct
{
  uint8_t totalParts;
  uint8_t partNumber;
  uint8_t length;
  APInfo apnode[GTP_LP_MAX_ALLOWED_APS];
} APCacheData;

typedef struct
{
  uint64_t macaddress_48b;
} BlackListAPInfo;

typedef struct
{
  uint8_t totalParts;
  uint8_t partNumber;
  uint8_t length;
  BlackListAPInfo apnode[GTP_LP_MAX_ALLOWED_APS];
} APCacheBlacklistData;

namespace izat_core {

enum IzatApiReturnCode {
    IZAT_SUCCESS,
    IZAT_FAIL,
    IZAT_INVALID_ARGUMENTS,
    IZAT_GPS_LOCKED,
    IZAT_FAIL_UNSUPPORTED
};

enum XtraVersionCheck {
    XTRA_VERSION_CHECK_DISABLED = 0,
    XTRA_VERSION_CHECK_AUTO,
    XTRA_VERSION_CHECK_XTRA2,
    XTRA_VERSION_CHECK_XTRA3
};
#define XTRA_MP_CONFIG_DISABLE_AUDO_DOWNLOD_TIMER (0x00000001)
#define XTRA_INFO_MASK_ABS_AGE (0x00000001) /**<  How many hours that the current XTRA information is valid  */
#define XTRA_INFO_MASK_REL_AGE (0x00000002) /**<  Last XTRA data download time  */
#define XTRA_INFO_MASK_XTRA_SERVER (0x00000004) /**<  XTRA server URLs  */
#define XTRA_INFO_MASK_NTP_SERVER (0x00000008) /**<  Network Time Protocol(NTP) server URLs  */
#define XTRA_INFO_MASK_TIME_REQUEST (0x00000010) /**<  Network Time Protocol(NTP) server URLs  */
#define XTRA_INFO_MASK_PREF_VALID_AGE (0x00000020) /**<  Network Time Protocol(NTP) server URLs  */

class IzatAdapterBase;

class IzatApiBase {
    IzatAdapterBase* mIzatAdapters[MAX_ADAPTERS];
    static bool mIsXtraInitialized;

protected:
    LocApiProxyBase *mLocApiProxy;

public:

    IzatApiBase(LocApiProxyBase *locApiProxy);
    inline virtual ~IzatApiBase() {}

    void addAdapter(IzatAdapterBase* adapter);
    void removeAdapter(IzatAdapterBase* adapter);

    // Geofence
    void geofenceBreach(size_t count,
                        uint32_t* hwIds,
                        Location& location,
                        GeofenceBreachType breachType,
                        uint64_t timestamp);
    void geofenceStatus(GeofenceStatusAvailable available);
    virtual void addGeofence(uint32_t clientId,
                             const GeofenceOption& options,
                             const GeofenceInfo& info,
                             uint8_t confidence,
                             LocApiResponseData<LocApiGeofenceData>* adapterResponseData);
    virtual void removeGeofence(uint32_t hwId,
                                uint32_t clientId,
                                LocApiResponse* adapterResponse);
    virtual void pauseGeofence(uint32_t hwId,
                               uint32_t clientId,
                               LocApiResponse* adapterResponse);
    virtual void resumeGeofence(uint32_t hwId,
                                uint32_t clientId,
                                LocApiResponse* adapterResponse);
    virtual void modifyGeofence(uint32_t hwId,
                                uint32_t clientId,
                                const GeofenceOption& options,
                                LocApiResponse* adapterResponse);

    virtual void setInSession(bool inSession);
    // set user preference
    virtual void setUserPref(bool user_pref);
    virtual void injectApCache(APCacheData data, LocApiResponse* adapterResponse);
    virtual void injectApCacheBlacklist(APCacheBlacklistData data, LocApiResponse* adapterResponse);
    virtual void sendBestAvailablePosReq(LocApiResponseData<LocGpsLocation>* adapterResponseData);
    virtual void sendBestAvailablePosReq(LocPosTechMask &tech_mask,
                                         LocApiResponseData<LocGpsLocation>* adapterResponseData);

    virtual void startTimeBasedTracking(const TrackingOptions& options,
                                        LocApiResponse* adapterResponse);
    virtual void stopTimeBasedTracking(LocApiResponse* adapterResponse);
    virtual void startDistanceBasedTracking(uint32_t sessionId,
                                            const LocationOptions& options,
                                            LocApiResponse* adapterResponse);
    virtual void stopDistanceBasedTracking(uint32_t sessionId,
                                           LocApiResponse* adapterResponse = nullptr);
    virtual void startBatching(uint32_t sessionId, const LocationOptions& options,
            uint32_t accuracy, uint32_t timeout, LocApiResponse* adapterResponse);
    virtual void stopBatching(uint32_t sessionId, LocApiResponse* adapterResponse);
    virtual LocationError startOutdoorTripBatchingSync(uint32_t tripDistance,
            uint32_t tripTbf, uint32_t timeout);
    virtual void startOutdoorTripBatching(uint32_t tripDistance,
            uint32_t tripTbf, uint32_t timeout, LocApiResponse* adapterResponse);
    virtual void reStartOutdoorTripBatching(uint32_t ongoingTripDistance,
                                                 uint32_t ongoingTripInterval,
                                                 uint32_t batchingTimeout,
                                                 LocApiResponse* adapterResponse);
    virtual LocationError stopOutdoorTripBatchingSync(bool deallocBatchBuffer = true);
    virtual void stopOutdoorTripBatching(bool deallocBatchBuffer = true,
                                              LocApiResponse* adapterResponse = nullptr);
    virtual LocationError getBatchedLocationsSync(size_t count);
    virtual void getBatchedLocations(size_t count,
                                          LocApiResponse* adapterResponse);
    virtual LocationError getBatchedTripLocationsSync(size_t count, uint32_t accumulatedDistance);
    virtual void getBatchedTripLocations(size_t count, uint32_t accumulatedDistance,
                                              LocApiResponse* adapterResponse);
    virtual LocationError queryAccumulatedTripDistanceSync(uint32_t &accumulated_trip_distance,
            uint32_t &numOfBatchedPositions);
    virtual void queryAccumulatedTripDistance(
            LocApiResponseData<LocApiBatchData>* adapterResponseData);
    virtual void setBatchSize(size_t size);
    virtual void setTripBatchSize(size_t size);
    void geofenceBreachLocation(FlpExtLocation &gpsLocation);
    void reportDBTPosition(UlpLocation &location,
                           GpsLocationExtended &locationExtended,
                           enum loc_sess_status status,
                           LocPosTechMask loc_technology_mask);
    void reportLocations(FlpExtLocation* locations, size_t count, BatchingMode batchingMode);
    void reportCompletedTrips(uint32_t accumulated_distance);

    // for TDP
    virtual void sendGtpEnhancedCellConfigBlocking(e_premium_mode mode,
                                                   LocApiResponse* adapterResponse);
    virtual void sendGtpCellConfigurationsBlocking(const char* data, uint32_t len,
                                                   LocApiResponse* adapterResponse);

    virtual void sendGdtUploadBeginResponse(int32_t service, int32_t session, int32_t status,
                                            LocApiResponse* adapterResponse);
    virtual void sendGdtUploadEndResponse(int32_t service, int32_t session, int32_t status,
                                          LocApiResponse* adapterResponse);

    virtual void sendGtpApStatus(int32_t gtpApDbStatus, uint64_t gtpApPcid64,
                                 int8_t gtpApPcid64_valid,
                                 const char* oemId, int8_t oemId_valid,
                                 const char* modelId, int8_t modelId_valid,
                                 LocApiResponse* adapterResponse);
    virtual void sendGdtDownloadBeginResponse(int32_t service, uint32_t session, int32_t status,
                                              const uint8_t* respLocInfo, int8_t respLocInfo_valid,
                                              uint32_t respLocInfo_len,
                                              uint32_t remainingThrottleTime,
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
    virtual void injectXtraData(const char* data, uint32_t len, bool legacyRetry,
                                LocApiResponse* adapterResponse);
    virtual void injectNtpTime(const int64_t time, const int64_t reference,
                               const int64_t uncertainty);
    virtual void requestXtraServers(LocApiResponse* adapterResponse);
    virtual void requestXtraConfigInfo(const uint32_t configMask,const uint32_t configReqSource);

    virtual void addToCallQueue(LocApiResponse* adapterResponse);

protected:
    void handleBatchStatusEvent(BatchingStatus batchStatus);
    void handleGdtUploadBeginEvent(int32_t service,
                                   int32_t session,
                                   const char* filePath,
                                   uint32_t filePath_len);
    void handleGdtUploadEndEvent(int32_t service, int32_t session, int32_t status);
    void handleGtpApStatusResp(int32_t status, uint16_t clientSwVer,
                               uint8_t asnMajVer, uint8_t asnMinVer, uint8_t asnPtVer);
    void handleGdtDownloadBeginEvent(int32_t service, uint32_t session, uint32_t respTimeoutInterval,
                                     const uint8_t* clientInfo, uint32_t clientInfo_len,
                                     const uint8_t* mobileStatusData, uint32_t mobileStatusData_len,
                                     const char* filePath, uint32_t filePath_len,
                                     uint32_t powerBudgetInfo, int8_t powerBudgetInfo_valid,
                                     uint32_t powerBudgetAllowance, int8_t powerBudgetAllowance_valid,
                                     uint32_t downloadRequestMask, int8_t downloadRequestMask_valid);
    void handleGdtReceiveDoneEvent(int32_t service, uint32_t session, int32_t status);
    void handleGdtDownloadEndEvent(int32_t service, uint32_t session, int32_t status);

    void handleCsmConfigResp(int32_t status, uint8_t supportedCrowdSourcingMask_valid,
                             uint32_t supportedCrowdSourcingMask, uint8_t wifiCrowdSourcingCapabaility_valid,
                             uint8_t onDemandCrowdSourcingSupported, uint8_t unsolicitedGnssCrowdSourcingSupported,
                             uint8_t majorVersionSupported, uint8_t minorVersionSupported,
                             uint16_t maxDataTransferFormatVersionSupported,
                             uint8_t modemClientInfo_valid,
                             uint32_t modemClientInfo_len,
                             const uint8_t* modemClientInfo);

    // XTRA Client 2.0
    void handleReceiveXtraServers(const char* server1, const char* server2, const char* server3);
    void handleRequestXtraData();
    void handleRequestNtpTime();
    void handleReceiveXtraConfigInfo(uint32_t status, uint32 configReqSource,
                                     uint32_t report_mask, uint16_t absAge,
                                     uint64_t relAge, uint8_t timereqValid,
                                     uint16_t prefValidAgeHrs,
                                     const char* ntpServer1, const char* ntpServer2,
                                     const char* ntpServer3, const char* xtraServer1,
                                     const char* xtraServer2, const char* xtraServer3);

   uint32_t getCarrierCapabilities();
};

}  // namespace izat_core

#endif //IZAT_API_BASE_H
