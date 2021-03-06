/* Copyright (c) 2011-2020, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation, nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LOC_API_V_0_2_H
#define LOC_API_V_0_2_H

#include <stdint.h>
#include <stdbool.h>
#include <LocApiBase.h>
#include <loc_api_v02_client.h>
#include <vector>
#include <functional>

#define LOC_SEND_SYNC_REQ(NAME, ID, REQ)  \
    int rv = true; \
    locClientStatusEnumType st; \
    locClientReqUnionType reqUnion; \
    qmiLoc##NAME##IndMsgT_v02 ind; \
\
    memset(&ind, 0, sizeof(ind)); \
    reqUnion.p##NAME##Req = &REQ; \
\
    st = locSyncSendReq(QMI_LOC_##ID##_REQ_V02,          \
                        reqUnion,                        \
                        LOC_ENGINE_SYNC_REQUEST_TIMEOUT, \
                        QMI_LOC_##ID##_IND_V02,          \
                        &ind);                           \
\
    if (st != eLOC_CLIENT_SUCCESS || \
        eQMI_LOC_SUCCESS_V02 != ind.status) { \
        LOC_LOGE ("%s:%d]: Error : st = %d, ind.status = %d", \
                  __func__, __LINE__,  st, ind.status); \
        rv = false; \
    }

using Resender = std::function<void()>;
using namespace loc_core;

/* This class derives from the LocApiBase class.
   The members of this class are responsible for converting
   the Loc API V02 data structures into Loc Adapter data structures.
   This class also implements some of the virtual functions that
   handle the requests from loc engine. */
class LocApiV02 : public LocApiBase {
protected:
  /* loc api v02 handle*/
  locClientHandleType clientHandle;

private:
  locClientEventMaskType mQmiMask;
  bool mInSession;
  GnssPowerMode mPowerMode;
  bool mEngineOn;
  bool mMeasurementsStarted;
  std::vector<Resender> mResenders;
  bool mMasterRegisterNotSupported;
  GnssSvMeasurementSet*  mSvMeasurementSet;
  bool mIsFirstFinalFixReported;
  bool mIsFirstStartFixReq;

  /* Convert event mask from loc eng to loc_api_v02 format */
  static locClientEventMaskType convertMask(LOC_API_ADAPTER_EVENT_MASK_T mask);

  /* Convert GPS LOCK from LocationAPI format to QMI format */
  static qmiLocLockEnumT_v02 convertGpsLockFromAPItoQMI(GnssConfigGpsLock lock);

  /* Convert GPS LOCK from QMI format to LocationAPI format */
  static GnssConfigGpsLock convertGpsLockFromQMItoAPI(qmiLocLockEnumT_v02 lock);

  /* Convert error from loc_api_v02 to loc eng format*/
  static enum loc_api_adapter_err convertErr(locClientStatusEnumType status);

  /* convert Ni Encoding type from QMI_LOC to loc eng format */
  static GnssNiEncodingType convertNiEncoding(
    qmiLocNiDataCodingSchemeEnumT_v02 loc_encoding);

  /*convert NI notify verify type from QMI LOC to loc eng format*/
  static bool convertNiNotifyVerifyType (GnssNiNotification *notif,
      qmiLocNiNotifyVerifyEnumT_v02 notif_priv);

  /*convert signal type to carrier frequency*/
  static float convertSignalTypeToCarrierFrequency(
      qmiLocGnssSignalTypeMaskT_v02 signalType,
      uint8_t gloFrequency);

  /*convert GnssMeasurement type from QMI LOC to loc eng format*/
  static bool convertGnssMeasurements (GnssMeasurementsData& measurementData,
      const qmiLocEventGnssSvMeasInfoIndMsgT_v02& gnss_measurement_report_ptr,
      int index);

  /* Convert APN Type mask */
  static qmiLocApnTypeMaskT_v02 convertLocApnTypeMask(LocApnTypeMask mask);
  static LocApnTypeMask convertQmiLocApnTypeMask(qmiLocApnTypeMaskT_v02 mask);

  /* Convert Get Constellation QMI Ind info to GnssSvTypeConfig */
  static void convertToGnssSvTypeConfig(
          const qmiLocGetConstellationConfigIndMsgT_v02& ind,
          GnssSvTypeConfig& config);

  /* Convert GnssPowerMode to QMI Loc Power Mode Enum */
  static qmiLocPowerModeEnumT_v02 convertPowerMode(GnssPowerMode powerMode);

  /*convert LocGnssClock type from QMI LOC to loc eng format*/
  int convertGnssClock (GnssMeasurementsClock& clock,
      const qmiLocEventGnssSvMeasInfoIndMsgT_v02& gnss_measurement_info);

  /* convert dgnss constellation mask from QMI loc to loc eng format */
  static void convertGnssConestellationMask (
            qmiLocGNSSConstellEnumT_v02 qmiConstellationEnum,
            GnssConstellationTypeMask& constellationMask);

  /* If Confidence value is less than 68%, then scale the accuracy value to 68%
     confidence.*/
  void scaleAccuracyTo68PercentConfidence(const uint8_t confidenceValue,
                                          LocGpsLocation &gpsLocation,
                                          const bool isCircularUnc);

  /* convert position report to loc eng format and send the converted
     position to loc eng */
  void reportPosition
    (const qmiLocEventPositionReportIndMsgT_v02 *location_report_ptr,
     bool unpropagatedPosition = false);

  /* convert satellite report to loc eng format and  send the converted
     report to loc eng */
  void reportSv (const qmiLocEventGnssSvInfoIndMsgT_v02 *gnss_report_ptr);

  void reportSvMeasurement (
          const qmiLocEventGnssSvMeasInfoIndMsgT_v02 *gnss_raw_measurement_ptr);

  void reportSvMeasurementInternal();

  void reportSvMeasurementSvLoop(
          const qmiLocEventGnssSvMeasInfoIndMsgT_v02 *gnss_sv_measurement_ptr,
          bool processExtSvMeas,
          bool validCarrierPhaseUnc,
          bool validDgnssSvMeas);

  inline void resetSvMeasurementReport(){
      memset(mSvMeasurementSet, 0, sizeof(GnssSvMeasurementSet));
      mSvMeasurementSet->size = sizeof(GnssSvMeasurementSet);
      mSvMeasurementSet->svMeasSetHeader.size = sizeof(GnssSvMeasurementHeader);
  }

  void  reportSvPolynomial (
  const qmiLocEventGnssSvPolyIndMsgT_v02 *gnss_sv_poly_ptr);

  void reportSvEphemeris (
  uint32_t eventId, const locClientEventIndUnionType &eventPayload);

  void populateGpsEphemeris(const qmiLocGpsEphemerisReportIndMsgT_v02 *,
          GnssSvEphemerisReport &);
  void populateGlonassEphemeris(const qmiLocGloEphemerisReportIndMsgT_v02 *,
          GnssSvEphemerisReport &);
  void populateBdsEphemeris(const qmiLocBdsEphemerisReportIndMsgT_v02 *,
          GnssSvEphemerisReport &);
  void populateGalEphemeris(const qmiLocGalEphemerisReportIndMsgT_v02 *,
          GnssSvEphemerisReport &);
  void populateQzssEphemeris(const qmiLocQzssEphemerisReportIndMsgT_v02 *,
          GnssSvEphemerisReport &);
  void populateCommonEphemeris(const qmiLocEphGnssDataStructT_v02 &, GnssEphCommon &);
  void populateGpsTimeOfReport(const qmiLocGnssTimeStructT_v02 &, GnssSystemTimeStructType &);

  void reportLocEvent(const qmiLocEventReportIndMsgT_v02 *event_report_ptr);
  /* convert system info to location api format and dispatch to
     the registered adapter */
  void reportSystemInfo(const qmiLocSystemInfoIndMsgT_v02* system_info_ptr);

  /* convert engine state report to loc eng format and send the converted
     report to loc eng */
  void reportEngineState (
    const qmiLocEventEngineStateIndMsgT_v02 *engine_state_ptr);

  /* convert fix session report to loc eng format and send the converted
     report to loc eng */
  void reportFixSessionState (
    const qmiLocEventFixSessionStateIndMsgT_v02 *fix_session_state_ptr);

  /* convert NMEA report to loc eng format and send the converted
     report to loc eng */
  void reportNmea (const qmiLocEventNmeaIndMsgT_v02 *nmea_report_ptr);

  /* convert and report an ATL request to loc engine */
  void reportAtlRequest(
    const qmiLocEventLocationServerConnectionReqIndMsgT_v02
    *server_request_ptr);

  /* convert and report NI request to loc eng */
  void reportNiRequest(
    const qmiLocEventNiNotifyVerifyReqIndMsgT_v02 *ni_req_ptr);

  /* report the xtra server info */
  void reportXtraServerUrl(
    const qmiLocEventInjectPredictedOrbitsReqIndMsgT_v02* server_request_ptr);

  /* convert and report GNSS measurement data to loc eng */
  void reportGnssMeasurementData(
    const qmiLocEventGnssSvMeasInfoIndMsgT_v02& gnss_measurement_report_ptr);

  /* convert and report ODCPI request */
  void requestOdcpi(
    const qmiLocEventWifiReqIndMsgT_v02& odcpiReq);

  void registerEventMask(LOC_API_ADAPTER_EVENT_MASK_T adapterMask);
  bool sendRequestForAidingData(locClientEventMaskType qmiMask);
  locClientEventMaskType adjustMaskIfNoSession(locClientEventMaskType qmiMask);
  bool cacheGnssMeasurementSupport();
  void registerMasterClient();
  int getGpsLock(uint8_t subType);
  void getRobustLocationConfig(uint32_t sessionId, LocApiResponse* adapterResponse);
  void getMinGpsWeek(uint32_t sessionId, LocApiResponse* adapterResponse);

  /* Convert get blacklist sv info to GnssSvIdConfig */
  void reportGnssSvIdConfig
    (const qmiLocGetBlacklistSvIndMsgT_v02& getBlacklistSvIndMsg);

  /* Convert get constellation info to GnssSvTypeConfig */
  void reportGnssSvTypeConfig
    (const qmiLocGetConstellationConfigIndMsgT_v02& getConstellationConfigIndMsg);

  /* Inform ODCPI availability to Modem */
  void wifiStatusInformSync();

protected:
  virtual enum loc_api_adapter_err
    open(LOC_API_ADAPTER_EVENT_MASK_T mask);
  virtual enum loc_api_adapter_err
    close();

  LocApiV02(LOC_API_ADAPTER_EVENT_MASK_T exMask,
            ContextBase *context = NULL);
  virtual ~LocApiV02();

public:
  static LocApiBase* createLocApiV02(LOC_API_ADAPTER_EVENT_MASK_T exMask,
                                     ContextBase* context);
  /* event callback registered with the loc_api v02 interface */
  virtual void eventCb(locClientHandleType client_handle,
               uint32_t loc_event_id,
               locClientEventIndUnionType loc_event_payload);

  /* error callback, this function handles the  service unavailable
     error */
  void errorCb(locClientHandleType handle,
               locClientErrorEnumType errorId);

  virtual void startFix(const LocPosMode& posMode,
        LocApiResponse *adapterResponse);

  virtual void stopFix(LocApiResponse *adapterResponse);

  virtual void setPositionMode(const LocPosMode& mode);

  virtual void
    setTime(LocGpsUtcTime time, int64_t timeReference, int uncertainty);

  virtual void
    injectPosition(double latitude, double longitude, float accuracy);

  virtual void
    injectPosition(const Location& location, bool onDemandCpi);

  virtual void
    injectPosition(const GnssLocationInfoNotification &locationInfo, bool onDemandCpi);

  virtual void
    deleteAidingData(const GnssAidingData& data, LocApiResponse *adapterResponse);

  virtual void
    informNiResponse(GnssNiResponse userResponse, const void* passThroughData);

  virtual LocationError
    setServerSync(const char* url, int len, LocServerType type);
  virtual LocationError
    setServerSync(unsigned int ip, int port, LocServerType type);
  virtual enum loc_api_adapter_err
    setXtraData(char* data, int length);
  virtual enum loc_api_adapter_err
    requestXtraServer();
  virtual void
    atlOpenStatus(int handle, int is_succ, char* apn, uint32_t apnLen, AGpsBearerType bear,
                   LocAGpsType agpsType, LocApnTypeMask mask);
  virtual void atlCloseStatus(int handle, int is_succ);
  virtual LocationError setSUPLVersionSync(GnssConfigSuplVersion version);

  virtual enum loc_api_adapter_err setNMEATypesSync(uint32_t typesMask);

  virtual LocationError setLPPConfigSync(GnssConfigLppProfile profile);


  virtual enum loc_api_adapter_err
    setSensorPropertiesSync(bool gyroBiasVarianceRandomWalk_valid, float gyroBiasVarianceRandomWalk,
                            bool accelBiasVarianceRandomWalk_valid, float accelBiasVarianceRandomWalk,
                            bool angleBiasVarianceRandomWalk_valid, float angleBiasVarianceRandomWalk,
                            bool rateBiasVarianceRandomWalk_valid, float rateBiasVarianceRandomWalk,
                            bool velocityBiasVarianceRandomWalk_valid, float velocityBiasVarianceRandomWalk);

  virtual enum loc_api_adapter_err
    setSensorPerfControlConfigSync(int controlMode, int accelSamplesPerBatch,
            int accelBatchesPerSec, int gyroSamplesPerBatch, int gyroBatchesPerSec,
            int accelSamplesPerBatchHigh, int accelBatchesPerSecHigh,
            int gyroSamplesPerBatchHigh, int gyroBatchesPerSecHigh, int algorithmConfig);
  virtual LocationError
      setAGLONASSProtocolSync(GnssConfigAGlonassPositionProtocolMask aGlonassProtocol);
  virtual LocationError setLPPeProtocolCpSync(GnssConfigLppeControlPlaneMask lppeCP);
  virtual LocationError setLPPeProtocolUpSync(GnssConfigLppeUserPlaneMask lppeUP);
  virtual void getWwanZppFix();
  virtual void
      handleWwanZppFixIndication(const qmiLocGetAvailWwanPositionIndMsgT_v02 &zpp_ind);
  virtual void
      handleZppBestAvailableFixIndication(const qmiLocGetBestAvailablePositionIndMsgT_v02 &zpp_ind);
  virtual void getBestAvailableZppFix();
  virtual LocationError setGpsLockSync(GnssConfigGpsLock lock);
  virtual void setConstrainedTuncMode(bool enabled, float tuncConstraint, uint32_t powerBudget,
                                      LocApiResponse *adapterResponse=nullptr);
  virtual void setPositionAssistedClockEstimatorMode(bool enabled,
                                                     LocApiResponse *adapterResponse=nullptr);
  virtual LocationError getGnssEnergyConsumed();
  virtual void updatePowerState(PowerStateType powerState);
  virtual void requestForAidingData(GnssAidingDataSvMask svDataMask);
  virtual void configRobustLocation(bool enable, bool enableForE911,
                                    LocApiResponse *adapterResponse=nullptr);
  virtual void configMinGpsWeek(uint16_t minGpsWeek,
                                LocApiResponse *adapterResponse=nullptr);
  /*
  Returns
  Current value of GPS Lock on success
  -1 on failure
  */
  virtual int setSvMeasurementConstellation(const locClientEventMaskType mask);
  virtual LocationError setXtraVersionCheckSync(uint32_t check);
  virtual void installAGpsCert(const LocDerEncodedCertificate* pData,
                               size_t length,
                               uint32_t slotBitMask);

  inline virtual void setInSession(bool inSession) override {
      mInSession = inSession;
      registerEventMask(mMask);
  }

  virtual LocPosTechMask convertPosTechMask(qmiLocPosTechMaskT_v02 mask);
  virtual LocNavSolutionMask convertNavSolutionMask(qmiLocNavSolutionMaskT_v02 mask);
  virtual GnssConfigSuplVersion convertSuplVersion(const uint32_t suplVersion);
  virtual GnssConfigLppProfile convertLppProfile(const uint32_t lppProfile);
  virtual GnssConfigLppeControlPlaneMask convertLppeCp(const uint32_t lppeControlPlaneMask);
  virtual GnssConfigLppeUserPlaneMask convertLppeUp(const uint32_t lppeUserPlaneMask);
  virtual GnssSignalTypeMask convertQmiGnssSignalType(
        qmiLocGnssSignalTypeMaskT_v02 qmiGnssSignalType);

  /* Requests for SV/Constellation Control */
  virtual LocationError setBlacklistSvSync(const GnssSvIdConfig& config);
  virtual void setBlacklistSv(const GnssSvIdConfig& config);
  virtual void getBlacklistSv();
  virtual void setConstellationControl(const GnssSvTypeConfig& config,
                                       LocApiResponse *adapterResponse=nullptr);
  virtual void getConstellationControl();
  virtual void resetConstellationControl(LocApiResponse *adapterResponse=nullptr);

  locClientStatusEnumType locSyncSendReq(uint32_t req_id, locClientReqUnionType req_payload,
          uint32_t timeout_msec, uint32_t ind_id, void* ind_payload_ptr);

  inline locClientStatusEnumType locClientSendReq(uint32_t req_id,
          locClientReqUnionType req_payload) {
      return ::locClientSendReq(clientHandle, req_id, req_payload);
  }
};

extern "C" LocApiBase* getLocApi(LOC_API_ADAPTER_EVENT_MASK_T exMask,
                                 ContextBase *context);
#endif //LOC_API_V_0_2_H
