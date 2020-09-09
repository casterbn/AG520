/*
 *  Copyright (c) 2017-2020, The Linux Foundation. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above
 *      copyright notice, this list of conditions and the following
 *      disclaimer in the documentation and/or other materials provided
 *      with the distribution.
 *    * Neither the name of The Linux Foundation nor the names of its
 *      contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 *  WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 *  ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 *  BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 *  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 *  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file       LocationListener.hpp
 *
 * @brief      Interface for location service listener object. Client needs to
 * implement this
 *             interface to get location service notifications like location
 * update,
 *             satellite vehicle info etc.
 *             The methods in listener can be invoked from multiple threads.
 *             Client needs to make sure that implementation is thread-safe.
 *
 */

#ifndef LOCATIONLISTENER_HPP
#define LOCATIONLISTENER_HPP

#include "telux/loc/LocationDefines.hpp"
#include <memory>

namespace telux {

namespace loc {
// forward declarations
class ILocationInfoBase;
class ILocationInfoEx;
class IGnssSVInfo;

/** @addtogroup telematics_location
* @{ */

/**
 * @brief Listener class for getting location updates and satellite vehicle
 * information.
 *
 * The methods in listener can be invoked from multiple different
 * threads. Client needs to make sure that implementation is thread-safe.
 *
 */
class ILocationListener {
public:
/**
 * This function is called when device receives location update.
 *
 * @param [in] locationInfo - Location information  like latitude, longitude,
 * timeInfo other information such as heading, altitude and velocity etc.
 *
 */
  virtual void
  onLocationUpdate(const std::shared_ptr<ILocationInfo> &locationInfo) {}

/**
 * This function is called when device receives location update.
 *
 * @param [in] locationInfo - Location information  like latitude, longitude,
 * timeInfo other information such as heading, altitude and velocity etc.
 *
 */
  virtual void onBasicLocationUpdate(
      const std::shared_ptr<ILocationInfoBase> &locationInfo) {}

/**
 * This function is called when device receives Gnss location update.
 *
 * @param [in] locationInfo - Contains richer set of location information
 * like latitude, longitude, timeInfo, heading, altitude, velocity and other
 * information such as deviations, elliptical accuracies etc.
 *
 */
  virtual void onDetailedLocationUpdate(
      const std::shared_ptr<ILocationInfoEx> &locationInfo) {}

/**
 * This function is called when device receives multiple Gnss location update from
 * the different engine types requested, which are SPE/PPE/FUSED.
 * This API will be called ONLY if we use startDetailedEngineReports.
 *
 * @param [in] locationInfo - Contains a list of location infos. Each element in
 * the list corresponds to one of SPE/PPE/FUSED.
 *
 */
  virtual void onDetailedEngineLocationUpdate(
      const std::vector<std::shared_ptr<ILocationInfoEx> > &locationEngineInfo) {}

/**
 * This function is called when device receives GNSS satellite information.
 *
 * @param [in] gnssSVInfo - GNSS satellite information
 *
 */
  virtual void onGnssSVInfo(const std::shared_ptr<IGnssSVInfo> &gnssSVInfo) {}

/**
 * This function is called when device receives GNSS data information
 * like jammer metrics and automatic gain control for satellite signal type.
 *
 * @param [in] info - GNSS signal info
 *
 */
  virtual void onGnssSignalInfo(const std::shared_ptr<IGnssSignalInfo> &info) {}

/**
 * This function is called when device receives GNSS NMEA sentences.
 *
 * @param [in] timestamp - Timestamp
 * @param [in] nmea - Nmea sentence
 */
  virtual void onGnssNmeaInfo(uint64_t timestamp, const std::string &nmea) {}

/**
 * This function is called when device receives signal measurement information
 * such as satellite vehicle pseudo range, satellite vehicle clock time, carrier phase
 * measurement etc.
 *
 * @param [in] measurementInfo - GNSS measurement information
 *
 * @note  Eval: This is a new API and is being evaluated. It is subject to change
 *              and could break backwards compatibility.
 */
  virtual void onGnssMeasurementsInfo(const telux::loc::GnssMeasurements &measurementInfo) {}


/**
 * Destructor of ILocationListener
 */
  virtual ~ILocationListener() {}
};

class ILocationSystemInfoListener {
public:
/**
 * This function is called when device receives location related system information
 * such as leap second change.
 *
 * @param [in] locationSystemInfo - contains location system information such as
 *                                  current leap seconds change
 */
  virtual void onLocationSystemInfo(const LocationSystemInfo &locationSystemInfo) {}

/**
 * Destructor of ILocationSystemInfoListener
 */
  virtual ~ILocationSystemInfoListener() {}

};
/** @} */ /* end_addtogroup telematics_location */
}         // end of namespace loc

} // end of namespace telux

#endif // LOCATIONLISTENER_HPP
