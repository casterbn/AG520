/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2018, 2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                  Engine Hub Proxy header file

GENERAL DESCRIPTION
  This file contains the data structure and variables used for handling requests
  and reports sent by GPS HAL. Engine hub will process those requests and reports
  and forward them to the registered engine plugins.
=============================================================================*/

#ifndef ENGINE_HUB_PROXY_H
#define ENGINE_HUB_PROXY_H

#include <EngineHubProxyBase.h>

namespace loc_core {

class EngineHubProxy : public EngineHubProxyBase {

public:
    EngineHubMgr* mEngHubMgr;

    inline EngineHubProxy(const MsgTask * msgTask,
                          IOsObserver* osObserver,
                          GnssAdapterReportEnginePositionsEventCb positionEventCb,
                          GnssAdapterReportSvEventCb svEventCb,
                          GnssAdapterReqAidingDataCb reqAidingDataCb,
                          GnssAdapterUpdateNHzRequirementCb updateNHzRequirementCb) {
        mEngHubMgr = new EngineHubMgr(msgTask, osObserver,
                positionEventCb, svEventCb, reqAidingDataCb, updateNHzRequirementCb);
    }

    inline ~EngineHubProxy() override {
        delete mEngHubMgr;
        mEngHubMgr = nullptr;
    }

    inline bool init() {
        bool retVal = false;

        if (mEngHubMgr != nullptr) {
            if (mEngHubMgr->init() == true) {
                retVal = true;
            } else {
                delete mEngHubMgr;
                mEngHubMgr = nullptr;
            }
        }
        return retVal;
    }

    // gnss session related functions
    inline bool gnssStartFix() override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssStart();
        }
    }

    inline bool gnssStopFix() override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssStop();
        }
    }

    inline bool gnssSetFixMode(const LocPosMode &posMode) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssSetFixMode(posMode);
        }
    }

    inline bool gnssDeleteAidingData(const GnssAidingData &aidingData) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssDeleteAidingData(aidingData);
        }
    }

    // GNSS reports
    inline bool gnssReportPosition(const UlpLocation &location,
                                   const GpsLocationExtended &locationExtended,
                                   enum loc_sess_status status) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssPositionReport(location, locationExtended, status);
        }
    }

    inline bool gnssReportSv(const GnssSvNotification& svNotify) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssSvReport(svNotify);
        }
    }

    inline bool gnssReportSvMeasurement(const GnssSvMeasurementSet& svMeasurementSet) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssSvMeasurementReport(svMeasurementSet);
        }
    }

    inline bool gnssReportSvPolynomial(const GnssSvPolynomial& svPolynomial) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssSvPolynomialReport(svPolynomial);
        }
    }

    inline bool gnssReportSvEphemeris(const GnssSvEphemerisReport& svEphemeris) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssSvEphemerisReport(svEphemeris);
        }
    }

    inline bool gnssReportSystemInfo(const LocationSystemInfo& systemInfo) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssSystemInfo(systemInfo);
        }
    }

    inline bool gnssReportKlobucharIonoModel(const GnssKlobucharIonoModel& ionoModel) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssKlobucharIonoModel(ionoModel);
        }
    }

    inline bool gnssReportAdditionalSystemInfo(
            const GnssAdditionalSystemInfo& additionalSystemInfo) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processGnssAdditionalSystemInfo(additionalSystemInfo);
        }
    }

    inline bool configLeverArm(const LeverArmConfigInfo& configInfo) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processLeverArmConfig(configInfo);
        }
    }

    inline bool configBodyToSensorMountParams(
            const BodyToSensorMountParams& b2sParams) override {
        if (mEngHubMgr == nullptr) {
            return false;
        } else {
            return mEngHubMgr->processBodyToSensorMountParams(b2sParams);
        }
    }
};

} // namespace loc_core

#endif // ENGINE_HUB_PROXY_H
