/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*
  Copyright (c) 2014,2016,2018-2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/
/*====*====*====*====*====*====*====*====*====*====*====*====*====*====*====*

                  qdr core i/f header file

GENERAL DESCRIPTION
  This file contains the data structure, functions and variables used for
  QDR core interface API's

NOTE
  All the function calls (API's) described in this file are non-blocking calls,
  the function should return as soon as the intended activity is completed.

=============================================================================*/
#ifndef __QDR_IF__
#define __QDR_IF__
#ifdef __cplusplus
extern "C" {
#endif
#ifdef OFFLINE
#include <stdint.h>
#endif

/* Version information */
/* M.m1.m2 date */
#define QDR_CORE_VERSION_MAJ     3

#define QDR_CORE_VERSION_MIN1    1
#define QDR_CORE_VERSION_MIN2    42
#define QDR_CORE_VERSION_DATE    "Apr 16, 2020"

typedef enum
{
   QDR_FAILURE=0,          /**< General failure */
   QDR_SUCCESS,            /**< Success */
   QDR_INVALID_SENSOR,     /**< Sensor data is invalid or of unsupported types */
   QDR_NL_UNINITIALISED    /**< QDR Core unitialized! */
} qdr_return;

typedef enum
{
   QDR_THR_SYNC_INVALID=0,
   QDR_THR_SYNC_OBJECT1,
   QDR_THR_SYNC_MAX_OBJECTS,
} qdr_threadsync_object;

typedef enum
{
   QDR_INITIALIZED=0,
   QDR_UNINITIALIZED
} qdr_navstate;

typedef enum
{
   QDR_EXT_ERR_FB_FAILED,
} qdr_external_error;

typedef struct
{
   uint8_t maj;
   uint8_t min1;
   uint8_t min2;
} tQdrVersion;

typedef struct _tQdrSVState
{
   double  GPSTime;        /**< GPS time */
   double  Pos[3];         /**< 3D positions in ECEF [m] */
   double  Vel[3];         /**< 3D velocities in ECEF [m/s] */
   float   Acc[3];         /**< 3D accelerations in ECEF [m/s^2] */
   double  ClkBias;        /**< clock bias [m] */
   float   ClkDrift;       /**< clock drift [m/s] */
   float   PosVar;         /**< position variance  [m^2] */
   float   ClkVar;         /**< clock bias variance [m^2] */
   float   Iono;           /**< ionosphere correction [m] */
   float   ionoDelayStd;   /**< ionosphere correction standard deviation [m] */
   float   TropoDelay;     /**< troposphere correction [m] */
   long    tow;            /**< GPS time referenced from start of the week. */
                           /**< [sec, 0 - 604800], toe or toa               */
   short   wno;            /**< The GPS week number, Eph or Alm weekno  */
                           /**< [weeks, 0 - life time of GPS in weeks]  */
   unsigned char EphFlag;  /**< ephemeris flag indicator (0: almanac 1: ephemeris, otherwise: unavailable) */
   unsigned char ephAge;   /**< in days */
   unsigned char Updated;  /**< updated or not */
   unsigned char Svid;     /**< sv id */
} tQdrSVState;

/**These prototypes are derived from
* OSP Message DGPS types code defines
* SIRF_MSG_SSB_DGPS_SRC_INTERNAL,SIRF_MSG_SSB_DGPS_SRC_NONE
* SIRF_MSG_SSB_DGPS_SRC_SBAS, SIRF_MSG_SSB_DGPS_SRC_SOFTWARE,
* SIRF_MSG_SSB_DGPS_SRC_USER
*/
#define DGPS_SRC_INTERNAL                                  ( 3 )
#define DGPS_SRC_NONE                                      ( 0 )
#define DGPS_SRC_SBAS                                      ( 1 )
#define DGPS_SRC_SOFTWARE                                  ( 4 )
#define DGPS_SRC_USER                                      ( 2 )

typedef enum _qdrCorrectionTypes
{
   QDR_COR_NONE            = DGPS_SRC_NONE,     /**< Use no corrections       */
   QDR_COR_SBAS            = DGPS_SRC_SBAS,     /**< Use SBAS channel         */
   QDR_COR_SERIAL          = DGPS_SRC_USER,     /**< Use external receiver    */
   QDR_COR_INTERNAL_BEACON = DGPS_SRC_INTERNAL, /**< Use internal DGPS Beacon */
   QDR_COR_SOFTWARE        = DGPS_SRC_SOFTWARE  /**< MI_SetDGPSCorrections    */
}qdrCorrectionTypes;

typedef struct  _tQdrDGPSMeasStruct /**< Structure definition for  NAV Library DGPS Interface */
{
   short SVID;
   unsigned int Signal;
   short IOD;
   qdrCorrectionTypes Source; /**< This is already defined in mi_if.h.
                                    We are using the same types here. */
   float PRCorrection;        /**< m   */
   float PRRCorrection;       /**< m/s */
   float CorrectionAge;       /**< sec */
   float PRCVariance;         /**< m;   Only for SBAS? Or from some other mechanism?)*/
   float PRRCVariance;        /**< m/s; Only for SBAS? Or from some other mechanism?)*/
} tQdrDGPSMeasStruct;

typedef enum _qdr_timeSourcet
{
   QDR_TIME_NOT_SET=0,        /**< Valid time information not available */
   QDR_TIME_SET_GPS,          /**< System time information from GPS */
   QDR_TIME_SET_GLO,          /**< System time information from GLONASS */
   QDR_TIME_SET_GAL,          /**< System time information from GALILEO */
   QDR_TIME_SET_BDS,          /**< System time information from BDS */
   QDR_TIME_SET_QZSS,         /**< System time information from QZSS */
   QDR_TIME_SET_EXT           /**< System time information from external sources */
} qdr_timeSourcet;

typedef uint8_t qdr_timevalid;
#define QDR_SYS_TIME_INVALID  0
#define QDR_SYS_TIME_VALID    0x1
#define QDR_LS_VALID          0x2
#define QDR_GGTAU_VALID       0x4
#define QDR_PPS_VALID         0x8


/**< SVID as follows:
 *   GPS      SV   1 to  32 :    0 -  31
 *   GLONASS  SV   1 to  24 :   65 -  96
 *   QZSS     SV 193 to 202 :  193 - 202
 *   BDS      SV   1 to   9 :  150 - 159
 *   BDS      SV  10 to  37 :   38 -  64
 *   GALILEO  SV   1 to  36 :  205 - 240
 */
typedef unsigned char qdr_svid;

#define QDR_GPS_MAX_PRN 32
#define QDR_GLO_MAX_PRN 24
#define QDR_BDS_MAX_PRN 37
#define QDR_GAL_MAX_PRN 36
#define QDR_SBAS_MAX_PRN 19
#define QDR_QZSS_MAX_PRN 10

typedef struct {
   uint32_t gpsList;
   uint32_t gloList;
   uint64_t bdsList;
   uint64_t galList;
   uint32_t sbasList;
   uint32_t qzssList;
   uint32_t gpsBand[QDR_GPS_MAX_PRN];
   uint32_t gloBand[QDR_GLO_MAX_PRN];
   uint32_t bdsBand[QDR_BDS_MAX_PRN];
   uint32_t galBand[QDR_GAL_MAX_PRN];
   uint32_t sbasBand[QDR_SBAS_MAX_PRN];
   uint32_t qzssBand[QDR_QZSS_MAX_PRN];
}tQdrSvList;

typedef struct _qdr_sysTime
{
   short int         week;          /**< GPS extended week. -1 = Invalid */
   unsigned int      swttag;        /**< Time Tag of measurements [ms] */
   double            swtow;         /**< GPS tow estimate [s]*/
   float             swtEstAcc;     /**< software tow estimated uncertainty [ms]*/
   uint8_t           leapSecond;    /**< Current leap second estimate */
   qdr_timevalid     time_valid;    /**< Validity Flag for time fields */
   double            glo2gpsTau;    /**< Broadcast GLO-GPS offset in sec */
   qdr_timeSourcet   src;           /**< Source of System Time information */
   uint64_t          pps_timeStamp; /**< 1PPS AP timestamp [us] */
   float             pps_unc;       /**< PPS rms uncertainty [ms] */
} qdr_sysTime;


/** QDR GNSS Signal BitMask as follows */
#define QDR_SIGNAL_TYPE_INVALID              (0x00000000)
#define QDR_SIGNAL_TYPE_GPS_L1CA             (0x00000001)
#define QDR_SIGNAL_TYPE_GPS_L1C              (0x00000002)
#define QDR_SIGNAL_TYPE_GPS_L2C_L            (0x00000004)
#define QDR_SIGNAL_TYPE_GPS_L5_Q             (0x00000008)
#define QDR_SIGNAL_TYPE_GLO_G1_CA            (0x00000010)
#define QDR_SIGNAL_TYPE_GLO_G2_CA            (0x00000020)
#define QDR_SIGNAL_TYPE_GAL_E1_C             (0x00000100)
#define QDR_SIGNAL_TYPE_GAL_E5A_Q            (0x00000200)
#define QDR_SIGNAL_TYPE_GAL_E5B_Q            (0x00000400)
#define QDR_SIGNAL_TYPE_BDS_B1_I             (0x00001000)
#define QDR_SIGNAL_TYPE_BDS_B1_C             (0x00002000)
#define QDR_SIGNAL_TYPE_BDS_B2_I             (0x00004000)
#define QDR_SIGNAL_TYPE_BDS_B2A_I            (0x00008000)
#define QDR_SIGNAL_TYPE_QZSS_L1CA            (0x00010000)
#define QDR_SIGNAL_TYPE_QZSS_L1S             (0x00020000)
#define QDR_SIGNAL_TYPE_QZSS_L2C_L           (0x00040000)
#define QDR_SIGNAL_TYPE_QZSS_L5_Q            (0x00080000)
#define QDR_SIGNAL_TYPE_SBAS_L1CA            (0x00100000)

typedef unsigned int qdr_signal;

typedef uint32_t qdr_SvDgnssMeasStatusMask;
#define QDR_MASK_DGNSS_EPOCH_TIME_VALID      (0x1)  /**<  DGNSS Epoch time is valid  */
#define QDR_MASK_DGNSS_MEAS_STATUS_PR_VALID  (0x2)  /**<  Pseudo Range correction is valid  */
#define QDR_MASK_DGNSS_MEAS_STATUS_PRR_VALID (0x4)  /**<  Pseudo Range rate correction is valid  */

typedef struct _qdr_svMeasDgnss
{
    qdr_SvDgnssMeasStatusMask dgnssMeasStatus;
    uint32_t diffDataEpochTimeMsec;
    float prCorrMeters;
    float prrCorrMetersPerSec;
} qdr_svMeasDgnss;

typedef struct
{
   unsigned long  Timetag;          /**< SV Measurement epoch in Rx SW time [ms] */
   unsigned long  TimetagLsw;
   double         Pseudorange;      /**< SV Pseudorange Measurement [m] */
   double         DeltaRange;       /**< SV Doppler Measurement [m/s] */
   double         sinel;            /**< Sine of the SV Elevation [m/s] */
   int            az;               /**< SV Azimuth w.r.t. true North [degrees] */
   double         measTow;          /**< GPS TOW at which SV measurements are reported [s] */
   double         CarrierPhase;     /**< SV Carrier Phase Measurement [cycles] */
   float          DeltaCP;          /**< SV Change in Carrier Phase [cycles] */
   unsigned short TimeInTrack;      /**< Time since measurement was acquired [0..30000 ms] */
   unsigned short DRInterval;       /**< Interval between measurements */
   unsigned short DRTime;           /**< Mean time of interval between measurements */
   short          ExtrapolationTime;/**< Extrapolation time in reach common time-tag value [ms] */
   unsigned short measWeek;         /**< GPS Week Number of measurements. 65535 if invalid */
   qdr_svid       SVID;             /**< GNSS SV ID */
   qdr_signal     SignalBand;       /**< Indicates the band this measurement is from */
   signed char    GloFrqId;         /**< Glonass Frequency Channel ID [-7..6] */
   unsigned char  SyncFlags;        /**< Measurement synchronization status
                                     *   Bit 0 - Set if acq/reacq is done success
                                     *   Bit 1 - Integrated carrier phase valid
                                     *   Bit 2 - Bit sync completed flag
                                     *   Bit 3 - Subframe sync has been done
                                     *   Bit 4 - Carrier pull in done
                                     *   Bit 5 - Code locked
                                     *   Bit 6 - Failed to acquire S/V
                                     *   Bit 7 - Scalable Tracking Loops Active
                                     */
   unsigned char  LowPowerCount;    /**< Count of preceding seconds where CNo < 28 dBHz [0..127 s] */
   unsigned char  PhaseErrorCount;  /**< Count of preceding seconds phase errors > 60 deg [0..127 s] */
   unsigned char  CtoN[10];         /**< Signal power of previous second [0.1 dBHz] */
   qdr_svMeasDgnss dgnss;
} tQdrGnssMeas2NAV;

typedef enum
{
   ICB_TYPE_GPS_GLO,    /**< Bias of GLONASS System Clock w.r.t. GPS     System Clock */
   ICB_TYPE_GPS_BDS,    /**< Bias of BDS     System Clock w.r.t. GPS     System Clock */
   ICB_TYPE_GPS_GAL,    /**< Bias of GALILEO System Clock w.r.t. GPS     System Clock */
   ICB_TYPE_GLO_BDS,    /**< Bias of BDS     System Clock w.r.t. GLONASS System Clock */
   ICB_TYPE_GLO_GAL,    /**< Bias of GALILEO System Clock w.r.t. GLONASS System Clock */
   ICB_TYPE_BDS_GAL,    /**< Bias of GALILEO System Clock w.r.t. BDS     System Clock */
   ICB_TYPE_INVALID     /**< Bias type is invalid */
} tQdrIcbType;

typedef struct
{
   double         icb;     /**< Inter Constellation Bias (m) */
   double         icb_rms; /**< Inter Constellation Bias RMS Uncertainty (m). 0 = Invalid */
} tQdrICB;


/**< Solution Info:  bit map as follows:
*  Bits 2-0:  GPS Fix Type
*    000   =  No Nav
*    001   =  1 SV solution
*    010   =  2 SV solution
*    011   =  3 SV solution (2D)
*    100   =  4 or more SV solution (3D)
*    101   =  Least Square 2D solution
*    110   =  Least Square 3D solution
*    111   =  DR solution (no SV)
*  Bit  3  :  1 = Trickle Power ON
*  Bits 5-4:  Altitude Hold
*    00    =  No Altitude Hold
*    01    =  Altitude Hold using altitude from KF
*    10    =  Altitude Hold using altitude from user
*    11    =  forced altitude
*  Bit 6   :  1 = DOP exceeded
*  Bit 7   :  1 = DGPS correction applied
*  Bit 8   :
*    1     = Sensor-based DR
*    0     = Velocity DR, if bits 2-0 = 111
*          = see bits 15-14, if bits 2-0 != 111
*  Bit 9   :  1 = Solution validated
*  Bit 10  :  1 = Velocity DR Timeout
*  Bit 11  :  1 = Solution edited by UI
*  Bit 12  :  1 = Velocity invalid
*  Bit 13  :  1 = Altitude Hold disabled
*  Bits 15-14: DR Status (applicable only when bit 8=0)
*    00    =  GPS Only
*    01    =  Calibrating
*    10    =  DR sensor error
*    11    =  DR Test mode
*  Bits 19-16: Final Fix status
*    0000  = Final Fix Reported
*    0001  = Internal GNSS only fix reported for diagnostics
*    0010  = Internal non-PPS aligned reported for diagnostics
*    Rest  = Reserved
*  Bit 20  :  1 = PPE Aiding Used
*  Bit 21  :  1 = Solution is during flashback
*  Bit 22  :  1 = Roll-Pitch Calibration needed
*  Bit 23  :  1 = Yaw Calibration needed
*  Bit 24  :  1 = Odo Calibration needed
*  Bit 25  :  1 = Gyro Calibration needed
*  Bit 26  :  1 = Factory Lever Arm used
*  Bit 27  :  1 = Factory B2S used
*  Bit 28  :  1 = DGNSS (RTCM) corrections used
*/
typedef struct _tQdrNavigationData
{
   unsigned int    solution_validity;  /**< 0 = Valid Fix. 1 = Invalid Fix */
   unsigned int    solution_info;      /**< Solution Info - See Above */
   unsigned char   cal_status;         /**< Indicated calibration status [0..100] */
   unsigned int    timestamp;          /**< AP Time stamp in ms */
   unsigned short  gps_week;           /**< GPS Extended Week Number. Invalid = 65535 */
   unsigned int    tow;                /**< GPS Time of Week [0 to 604800000] [milliseconds] */
   unsigned int    tow_sub_ms;         /**< GPS Time of Week submillisecond portion [nanoseconds] */
   short           time_bias;          /**< Offset between best estimate of time and GPS time [nanoseconds] */
   unsigned char   time_accuracy;      /**< Accuracy of best estimate GPS time
                                        *   0 = UNKNOWN
                                        *   1 = < 500ns
                                        *   2 = < 10ms
                                        *   3 = < 2s
                                        *   4 = < 5s
                                        */
   unsigned char   time_source;        /**< Source of Time information:
                                        *   0 = UNKNOWN
                                        *   1 = GPS
                                        *   2 = GLONASS
                                        *   3 = BDS
                                        *   4 = GALILEO
                                        */
   float           time_uncertainty;   /**< time uncertainty [s] */
   unsigned short  utc_year;           /**< UTC Year   [1980 to 3000] */
   unsigned char   utc_month;          /**< UTC Month  [1 to 12] */
   unsigned char   utc_day;            /**< UTC Day    [1 to 31] */
   unsigned char   utc_hour;           /**< UTC Hour   [0 to 23] */
   unsigned char   utc_min;            /**< UTC Minute [0 to 59] */
   unsigned short  utc_sec;            /**< UTC Second [0 to 59999] [milliseconds] */
   unsigned char   utc_offset;
   unsigned char   datum;              /**< Map datum.
                                        *    21 = WGS-84
                                        *   178 = Tokyo Mean
                                        *   179 = Tokyo Japan
                                        *   180 = Tokyo Korea
                                        *   181 = Tokyo Okinawa
                                        *   182 = PZ-90
                                        */
   double          clk_bias;           /**< GNSS Clock Bias [m] */
   unsigned int    clk_bias_error;     /**< GNSS Clock Bias RMS Uncertainty [m] */
   int             clk_offset;         /**< GNSS Clock Drift [m/s] */
   unsigned int    clk_offset_error;   /**< GNSS Clock Drift RMS Uncertainty [m/s] */
   int             lat;                /**< Latitude [-90..90] with resolution 1e-7 [deg]*/
   int             lon;                /**< Longitude [-180..180] with resolution 1e-7 [deg] */
   int             alt_ellips;         /**< Altitude from Ellipsoid with resolution 0.01 [m] */
   int             alt_msl;            /**< Altitude from Mean Sea Level resolution 0.01 [m] */
   unsigned short  sog;                /**< Speed Over Ground with resolution 0.01 [m/s] */
   unsigned short  cog;                /**< Course Over Ground [0..360] with resolution 0.01 [deg]*/
   short           climb_rate;         /**< Climb rate with resolution 0.01 [m/s] */
   short           heading_rate;       /**< Heading Rate with resolution 0.01 [deg/s] */
   unsigned int    distance_travel;    /**< Distance travelled since session start [m] */
   unsigned short  heading_error;      /**< Heading Uncertainty RMS with resolution 0.01 [deg]*/
   unsigned short  distance_travel_error; /**< Uncertainty of Distance travelled since session start [m] */
   unsigned int    ehpe;               /**< Expected Horizontal Position Error [0.01m] */
   unsigned int    enpe;               /**< Expected Northing Position Error [0.01m] */
   unsigned int    eepe;               /**< Expected Easting Position Error [0.01m] */
   unsigned int    evpe;               /**< Expected Vertical Position Error [0.01m] */
   unsigned short  ehve;               /**< Expected Horizontal Velocity Error [0.01m/s] */
   unsigned short  enve;               /**< Expected Northing Velocity Error [0.01m/s] */
   unsigned short  eeve;               /**< Expected Easting Velocity Error [0.01m/s] */
   unsigned short  evve;               /**< Expected Vertical Velocity Error [0.01m/s] */
   unsigned char   gdop;               /**< Geometric Dilution of Precision [0..51] with resolution 0.2 */
   unsigned char   pdop;               /**< Position Dilution of Precision [0..51] with resolution 0.2 */
   unsigned char   hdop;               /**< Horizontal Dilution of Precision [0..51] with resolution 0.2 */
   unsigned char   vdop;               /**< Vertical Dilution of Precision [0..51] with resolution 0.2 */
   unsigned char   tdop;               /**< Time Dilution of Precision [0..51] with resolution 0.2 */
   unsigned int    HorUncEllSemiMajor; /**< Semi Major Axis Of Position Uncertainty Ellipse [cm] */
   unsigned int    HorUncEllSemiMinor; /**< Semi Minor Axis Of Position Uncertainty Ellipse [cm] */
   unsigned int    HorUncEllOrient;    /**< Orientation of Position Uncertainty Ellipse [0.01 deg] */
   signed short    an;
   signed short    ae;
   signed short    ad;
   unsigned char   num_svs_in_sol;     /**< Number of GNSS SV measurements used in the solution [0..64] */
   tQdrSvList      used_in_fix;        /**< Bits  0-31  -  GPS      SV   1 to  32 */
                                       /**< SBAS     SV 120 to 138 */
                                       /**< GALILEO  SV   1 to  37 */
                                       /**< GLONASS  SV   1 to  24 */
                                       /**< QZSS     SV 193 to 202 */
                                       /**< BDS      SV   1 to  37 */
   unsigned int    additional_info;    /**< Additional info
                                        *   Bit 8 - TOW Set
                                        *   Bit 9 - Week Set
                                        *   All other bits reserved
                                        */
} tQdrNavigationData;

/*
   Core supports 64 SVs to support multiconstellation operations.
   GPS    = 16 SVs
   GLO    = 12 SVs
   BDS    = 19 SVs (10 GEO/IGSO + 9 MEO when constellation is filled)
   GAL    = 14 SVs (when Constellation is filled)
   QZSS   =  3 SVs
   SBAS   =  0 SVs (SBAS SVs are not used for ranging)
   Total  = 64 SVs
*/
#define QDR_MAX_NUM_MEAS (128)
/* Single band will be used in fix computation by SPE */
#define QDR_MAX_MEAS_USED_IN_FIX (QDR_MAX_NUM_MEAS >> 1)


/* Value used to indicate invalid Body Frame Uncertainties */
#define QDR_BFD_UNC_INVALID      0

/**< Valdity Masks for Body Frame Parameters */
#define QDR_BFD_LONG_ACCEL_VALID (0x0001) /**< Valid Body Frame Forward Acceleration */
#define QDR_BFD_LAT_ACCEL_VALID  (0x0002) /**< Valid Body Frame Lateral (Sideways) Acceleration */
#define QDR_BFD_VERT_ACCEL_VALID (0x0004) /**< Valid Body Frame Vertical Acceleration */
#define QDR_BFD_YAW_RATE_VALID   (0x0008) /**< Valid Body Frame Yaw Rate */
#define QDR_BFD_PITCH_VALID      (0x0010) /**< Valid Body Frame Pitch */

#define QDR_ICB_MAX_COUNT   (18)

#define QDR_ICB_GPS_L1_GLO_G1     (0)     /**< Bias of GLONASS G1    System Clock w.r.t. GPS L1     System Clock */
#define QDR_ICB_GPS_L1_BDS_B1     (1)     /**< Bias of BDS B1        System Clock w.r.t. GPS L1     System Clock */
#define QDR_ICB_GPS_L1_GAL_E1     (2)     /**< Bias of GALILEO E1    System Clock w.r.t. GPS L1     System Clock */
#define QDR_ICB_BDS_B1_GLO_G1     (3)     /**< Bias of GLONASS G1    System Clock w.r.t. BDS L1     System Clock */
#define QDR_ICB_GAL_E1_GLO_G1     (4)     /**< Bias of GLONASS G1    System Clock w.r.t. GALILEO E1 System Clock */
#define QDR_ICB_GAL_E1_BDS_B1     (5)     /**< Bias of BDS B1        System Clock w.r.t. GALILEO E1 System Clock */
#define QDR_ICB_GPS_L1_IRNSS_L5   (6)     /**< Bias of IRNSS L5      System Clock w.r.t. GPS L1     System Clock */
#define QDR_ICB_GLO_G1_IRNSS_L5   (7)     /**< Bias of IRNSS L5      System Clock w.r.t. GLONASS G1 System Clock */
#define QDR_ICB_BDS_B1_IRNSS_L5   (8)     /**< Bias of IRNSS L5      System Clock w.r.t. BDS B1     System Clock */
#define QDR_ICB_GAL_B1_IRNSS_L5   (9)     /**< Bias of IRNSS L5      System Clock w.r.t. GALILEO E1 System Clock */
#define QDR_ICB_GPS_L1_L2         (10)    /**< Bias of GPS L2        System Clock w.r.t. GPS L1     System Clock */
#define QDR_ICB_GPS_L1_L5         (11)    /**< Bias of GPS L5        System Clock w.r.t. GPS L1     System Clock */
#define QDR_ICB_GLO_G1_G2         (12)    /**< Bias of GLONASS G2    System Clock w.r.t. GLONASS G1 System Clock */
#define QDR_ICB_BDS_B1_B2         (13)    /**< Bias of BDS B2        System Clock w.r.t. BDS B1     System Clock */
#define QDR_ICB_GAL_E1_E5a        (14)    /**< Bias of GALILEO E5a   System Clock w.r.t. GALILEO E1 System Clock */
#define QDR_ICB_GAL_E1_E5b        (15)    /**< Bias of GALILEO E5b   System Clock w.r.t. GALILEO E1 System Clock */
#define QDR_ICB_QZSS_L1_L2        (16)    /**< Bias of QZSS L2       System Clock w.r.t. QZSS L1    System Clock */
#define QDR_ICB_QZSS_L1_L5        (17)    /**< Bias of QZSS L5       System Clock w.r.t. QZSS L1    System Clock */

typedef struct _tQdrDgnssSrc
{
   uint32_t          dgnssCorrectionSourceType;
   uint32_t          dgnssCorrectionSourceID;
   uint16_t          dgnssRefStationId;
} tQdrDgnssSrc;

typedef struct
{
   tQdrICB           icb[QDR_ICB_MAX_COUNT];
   unsigned char     numMeas; /**< Number of valid measurements in the meas array */
   tQdrGnssMeas2NAV  meas[QDR_MAX_NUM_MEAS];
   tQdrDgnssSrc      dgnssInfo;
} tQdrGnssMeasSet2NAV;

/* Body frame dynamics parameters updated by the core */
typedef struct _tQdrNavBodyFrameParams{
   float           longAccel;    /**< Longitudinal Acceleration [m/s^2] */
   float           longAccelUnc; /**< Longitudinal Acceleration RMS Uncertainty [m/s^2] */
   float           latAccel;     /**< Lateral Acceleration [m/s^2] */
   float           latAccelUnc;  /**< Lateral Acceleration RMS Uncertainty [m/s^2] */
   float           vertAccel;    /**< Vertical Acceleration [m/s^2] */
   float           vertAccelUnc; /**< Vertical Acceleration RMS Uncertainty [m/s^2] */
   float           rollRate;     /**< Roll Rate [Rad/s] */
   float           rollRateUnc;  /**< Roll Rate RMS Uncertainty [Rad/s] */
   float           pitchRate;    /**< pitch Rate [Rad/s] */
   float           pitchRateUnc; /**< pitch Rate RMS Uncertainty [Rad/s] */
   float           yawRate;      /**< Yaw Rate [Rad/s] */
   float           yawRateUnc;   /**< Yaw Rate RMS Uncertainty [Rad/s] */
   float           roll;         /**< roll w.r.t Locally Level Plane [Rad] */
   float           pitch;        /**< pitch w.r.t Locally Level Plane [Rad] */
   float           yaw;          /**< yaw w.r.t Locally Level Plane [Rad] */
   float           rollUnc;      /**< Roll RMS Uncertainty w.r.t Locally Level Plane [Rad] */
   float           pitchUnc;     /**< Pitch RMS Uncertainty w.r.t Locally Level Plane [Rad] */
   float           yawUnc;       /**< Yaw RMS Uncertainty w.r.t Locally Level Plane [Rad] */
   uint32_t        dataMask;     /**< Data Validity of above fields */
} tQdrNavBodyFrameParams;

/* For Body frame data updates */
typedef struct _tQdrCoreNavBfdParams{
    unsigned int towLatch;          /**< GPS Time of Week [0 to 604800000] [milliseconds] */
    tQdrNavBodyFrameParams bfdData; /**< Body Frame estimates of velocity & attitude */
} tQdrCoreNavBfdParams;

/**< Measurement status
*   Bit  0 : Set if acq/reacq is done success
*   Bit  1 : Integrated carrier phase valid
*   Bit  2 : Bit sync completed flag
*   Bit  3 : Subframe sync has been done
*   Bit  4 : Carrier pull in done
*   Bit  5 : Code locked
*   Bit  6 - 8 : Reserved
*   Bit  9 : Frame Sync verified
*   Bit 10 : Possible cycle slip
*   Bit 11 : Frame Sync lost
*   Bit 12 : MP detected
*   Bit 13 : MP Only detected
*   Bit 14 : Weak Frame Sync
*   Bit 15 : SV Used in solution
*   Bit 16 : SBAS Iono corrections used
*   Bit 17 : DGNSS Iono corrections used
*   Bit 18 - 31 : Reserved
*/

typedef struct _tQdrSvStateDataPerSV {
    unsigned short         sat_info;   /**< Contains Slot/PRN, Frequency ID & Constellation info
                                        *   Bits  0 -  7 : Slot / PRN
                                        *   Bits  8 - 12 : Frequency ID for GLONASS [-7 .. +6]
                                        *   Bits 13 - 15 : Constellation
                                        *                  0 - GPS/QZSS
                                        *                  1 - SBAS
                                        *                  2 - GLONASS
                                        *                  3 - GALILEO
                                        *                  4 - BEIDOU
                                        *                  5..7 - Reserved
                                        */
    unsigned short         azimuth;    /**< Azimuth of SV [0.1 deg] */
    unsigned short         elevation;  /**< Elevation of SV [0.1 deg] */
    unsigned int           status;
    unsigned short         avg_cno;    /**< CN0 of SV [0.1 dBHz] */
    qdr_signal             signalBand; /**< Band: L1/L5,E1/E5 ..? */
    unsigned int           svUsedInFix;
} tQdrSvStateDataPerSV;

typedef struct _tQdrSvStateData {
    unsigned short         gps_week;            /**< GPS Extended Week Number. Invalid = 65535 */
    unsigned int           tow;                 /**< GPS Time of Week [0 to 604800000] [milliseconds] */
    unsigned int           tow_sub_ms;          /**< GPS Time of Week submillisecond portion [nanoseconds] */
    short                  time_bias;           /**< Offset between best estimate of time and GPS time [nanoseconds] */
    unsigned char          time_accuracy;       /**< Accuracy of best estimate GPS time
                                                 *   0 = UNKNOWN
                                                 *   1 = < 500ns
                                                 *   2 = < 10ms
                                                 *   3 = < 2s
                                                 *   4 = < 5s
                                                 */
    unsigned char          time_source;         /**< Source of Time information:
                                                 *   0 = UNKNOWN
                                                 *   1 = GPS
                                                 *   2 = GLONASS
                                                 *   3 = BDS
                                                 *   4 = GALILEO
                                                 */
    float                  time_uncertainty;    /**< time uncertainty [s] */
    unsigned char          num_of_sats;         /**< Number of GNSS SV measurements available [0..64] */
    unsigned int           gps_svs_used_infix;  /**< Bit Mask for GPS     SVs used  Bit 0..31 - SV   1.. 32 */
    unsigned int           glo_svs_used_infix;  /**< Bit Mask for GLONASS SVs used  Bit 0..23 - SV   1.. 24 */
    unsigned long long     gal_svs_used_infix;  /**< Bit Mask for GALILEO SVs used  Bit 0..35 - SV   1.. 36 */
    unsigned long long     bds_svs_used_infix;  /**< Bit Mask for BDS     SVs used  Bit 0..36 - SV   1.. 37 */
    unsigned int           qzss_svs_used_infix; /**< Bit Mask for QZSS    SVs used  Bit 0..09 - SV 193..202 */
    unsigned int           sbas_svs_used_infix; /**< Bit Mask for SBAS    SVs used  Bit 0..18 - SV 120..128 */
    tQdrDgnssSrc           meas_dgnss;
    tQdrSvStateDataPerSV   sat[QDR_MAX_NUM_MEAS]; /**< Array of SV Info */
} tQdrSvStateData;


/*Callback Types*/
typedef qdr_return (* qdr_cb_retrieveNVData_t) ( unsigned char dataIDToRetrieve,
                                                 unsigned int  dataLength,
                                                 unsigned char *pPayload);

typedef qdr_return (* qdr_cb_storeNVData_t) ( unsigned char dataIDToStore,
                                              unsigned int  dataLength,
                                              unsigned char *pPayload);

typedef void (* qdr_cb_sendDIAGData_t) ( unsigned int diagID,
                                         unsigned int packetLength,
                                         void  *pPayload);

/**Diag ID's from QDR core, True mapping is done outside*/
#define QDR_DIAG_VERSION_INFO               0x0001 /**< Structure type "char *" */
#define QDR_DIAG_GNSS_NAVINIT_DATA          0x0002 /**< Structure type "tQdrNavInitData" */
#define QDR_DIAG_A6DOF_NVM_INIT_DATA        0x0003 /**< Structure type "tQdrA6DOFNvmData" */
#define QDR_DIAG_A6DOF_NAVSTATE             0x0004 /**< Structure type "tQdrA6DOFNavstate" */
#define QDR_DIAG_A6DOF_GNSS_ODO_INFO        0x0005 /**< Structure type "tQdrA6DOFGnssOdoInfo" */
#define QDR_DIAG_A6DOF_GNSS_CHAN_INFO       0x0006 /**< Structure type "tQdrA6DOFGnssChanList" */
#define QDR2_DIAG_NAVSTATE                  0x0007 /**< Structure type "MI_DR_NAV_STATE" */
#define QDR2_DIAG_NAVSTATUS                 0x0008 /**< Structure type "MI_DR_NAV_STATUS" */
#define QDR2_DIAG_NAVSUBSYS                 0x0009 /**< Structure type "MI_DR_NAV_SUBSYS" */
#define QDR2_DIAG_NVM_INIT_DATA             0x000A /**< Structure type "tDrRamData" */
#define QDR_DIAG_A6DOF_SNAPSHOT             0x000B /**< Structure type "tQdrA6DOFSnapshot" */

/**Nav Init Data structure Stored info from Last session*/
typedef struct _tqdrnlInit  /* Message 31 */
{
   unsigned char  EnableConAltMode;
   unsigned char  AltMode;
   unsigned char  AltSource;
   float          Altitude;
   unsigned char  DegradedMode;
   short          DegradedTimeout;
   short          DRTimeout;
   short          CoastTimeout;
   unsigned char  TrackSmoothMode;
   unsigned char  DOPSelection;
   short          HDOPThresh;
   short          GDOPThresh;
   short          PDOPThresh;
   unsigned char  DGPSSelection;
   short          DGPSTimeout;
   short          ElevNavMask;
   short          PowNavMask;
   unsigned char  EditingResidualMode;
   short          EditingResidualThreshold;
   unsigned char  SSDMode;
   short          SSDThreshold;
   unsigned char  StaticNavMode;
   short          StaticNavThreshold;
   double         PosX; /**Last stored Nav Position X*/
   double         PosY; /**Last stored Nav Position Y*/
   double         PosZ; /**Last stored Nav Position Z*/
   unsigned char  PositionInitSource;
   double         GPSTime; /**Last stored TOW*/
   short          GPSWeek; /**Last stored Week*/
   unsigned char  TimeInitSource;
   double         Drift;
   unsigned char  ClockDriftInitSource;
} tqdrnlInit;

typedef struct
{
   short             SeqNum;         /*For testing and user stuff*/
   unsigned short    OkAcrossReset;  /*TRUE:  DR stay valid after a RESET if vehicle staionary at IGN off*/
   unsigned char     SensorDataType; /* Need to remember Bus Type Across reset*/

   unsigned char     new_data; /**Reserved flag used for bookkeeping on the interface*/

   unsigned char     valid;   /* Holds whether the cal is valid and navigation is resumable */
   char              prerot;  /**Switch to control the pre-rotation of raw axes*/
   unsigned short    sensor_rate; /** Sensor rate previously detected */
   unsigned char     primary_constell;  /**Primary Constellation */
   unsigned char     b2s_rp_gain; /**RP Filter Gain*/
   unsigned char     b2s_yaw_gain; /**Yaw Filter gain*/
   unsigned char     b2s_estimate; /**Estimation of B2S*/
   unsigned char     gsf_gain; /**Gyro scale factor filter Gain*/
   //unsigned char asf_gain[3];
   unsigned char     osf_gain; /**Odo scale factor filter Gain*/
   unsigned char     co_gain; /**Gain of Stationary Detect filter*/
   unsigned char     scd_gain; /** Gain of Sensor Clock Drift Estimate filter */
   unsigned char     icb_constell[8]; /* icb constell w.r.t. primary */
   unsigned char     icb_gain[8]; /* Gain of icb (w.r.t) primary */
   unsigned char     gnss_loss; /**GNSS loss used to calibrate LOS/NLOS detection*/
   /* We might want to store the time to use for uncertainty growth */

   double            llh[3]; /**Last saved Latitude,Longitude and Altitude */
   float             att[3]; /**Attitude information X,Y and Z*/
   float             acc_bias[3]; /**Accelerometer Bias X, Y and Z*/
   float             gyro_bias[3]; /**Gyroscope Bias X, Y and Z*/
   float             unc[12]; /**DR Nav filter State Uncertainities*/
   float             b2s[3]; /**B2S Roll, Pitch and Gain*/
   float             gsf; /**Gyro Scale factor*/
   float             osf; /**Odo Scale factor*/
   float             gco; /**Stationary Gyro Threshold*/
   float             aco; /**Stationary Accelerometer Threshold*/
   float             scd; /**Sensor Clock Drift Estimate*/
   float             icb[8]; /**icb (w.r.t) primary */
   float             icb_var[8]; /**icb variance (w.r.t) primary */
   float             ts; /*ap timestamp*/
   float             wk; /* week number */
   float             temperature; /* sensor temperature */
   double            tow; /**TOW*/
   float             factory_b2s[4]; /** Factory RPY and unc */
   uint8_t           factory_b2s_status; /** Factory-b2s usage status */
   float             factory_lever_arm[3]; /** Factory Lever-Arm */
   uint8_t           factoy_la_valid; /** LA validity */
   float             reserved[4]; /**Reserved*/
}  tQdrA6DOFNvmData;

typedef struct
{
   short             SeqNum;
   unsigned short    OkAcrossReset;      /* TRUE:  DR data can be used after a RESET */
                                         /* FALSE: DR data cannot be used after a RESET */
   float             DRHeading;          /* deg */
   float             DRHeadingError;     /* deg, 1-sigma */
   float             DRSpeedError;       /* m/sec, 1-sigma */
   float             DRPositionError;    /* meters, 1-sigma */
   /*
    Odometer data
    */
   float             SpeedSf;           /* dimensionless */
   float             OdoSpeedSf;        /* dimensionless */
   /*
    Gyro Data
    */
   float             HeadingRateBias;   /* deg/sec */
   float             HeadingRateSf;     /* dimensionless */
   double            HeadingRateSf_SD;  /* dimensionless */


   /* end of update */

   /*
    * Legacy Differential Wheel Speed Data to use for existing files (These things will not be used
    in real time system)
   */
   float             LFSpeedSF;     /* Left Front Wheel Speed Scale Factor, dimensionless */
   float             RFSpeedSF;     /* Right Front Wheel Speed Scale Factor, dimensionless */
   float             LRSpeedSF;     /* Left Rear Wheel Speed Scale Factor, dimensionless */
   float             RRSpeedSF;     /* Right Rear Wheel Speed Scale Factor, dimensionless */
   float             AxleLength;    /* Length of rear axle, meters */
   float             AxleSep;       /* Distance from rear to front axle, meters (positive forward) */
   float             AntennaDist;   /* Distance from rear axle to GPS antenna, meters (positive forward)*/

   char              WheelSelectCtr;  /*added */

   unsigned short    FirstHRSFDone; /* Indicates First Heading Rate Scale Factor estimate was done */

   unsigned short    DiffWheelSpdCalOK; /* Indicates whether DWS calibration has been successful */

   unsigned char     LFSpeedSFCalOk; /* Indicates whether individual speed has been calibrated */
   unsigned char     RFSpeedSFCalOk; /* Indicates whether individual speed has been calibrated */
   unsigned char     LRSpeedSFCalOk; /* Indicates whether individual speed has been calibrated */
   unsigned char     RRSpeedSFCalOk; /* Indicates whether individual speed has been calibrated */

   float             HeadingRateSf_Front;
   float             HeadingRateSf_Rear;
   float             HeadingRateSf_Front_SD;
   float             HeadingRateSf_Rear_SD;

   float             RearDSF_SD;
   float             FrontDSF_SD;

   short             DrNavControl;      /* GPS Only, DR with Stored Cal, or DR with GPS Cal */



   double            RawLonAccel;
   double            RawLatAccel;
   double            RawUpAccel;

   double            YawAngle_rads ;   /* radians */
   double            YawAngleSD_rads;   /* radians */

   double            PitchAngle_rads;      /* radians */
   double            RollAngle_rads;      /* radians */

   short             Sensor2YawedDone;
   short             YawAngleComputed;

   short             UserResetWithData; /*TRUE  = User has issued Reset with Data for us to update DR with */
                                        /*FALSE = No data from user to update DR with*/

   /*TM 01/16/08 */
   short             ValidDrCal;
   short             OdoSpeedSFCalOk;
   unsigned char     SensorDataType; /*Need to remember Bus Type Across reset */

   /*
    * Start-Up Altitude Checks
    */
   float             TOWLastValidKFAltitude; /* Time-Of-Week (in secs) of the last time KF computed an altitude */
   float             LastValidKFAltitude;    /* Last, good, KF-computed altitude */
   /*
    * END OF Start-Up Altitude Checks
    */

   unsigned short    SessionCounter; /* Starts at zero and incs every hard/soft reset. Only factory clears it */
   int               CheckSum;

   double            Lat;
   double            Lon;
   double            Alt;
   unsigned char     GyroDetectionStatus;
   float             PowerOffset;   /* GPSSystemState.PowerOffset   */
   unsigned char     PowerOffsetValid;     /*GPSSystemState.PowerOffsetValid */

   float             ENE;
   float             EVE;
   char              WheelSelectCtrStrt;
   unsigned char     GState;


   unsigned char     PL_Mode;

   double            PL_Lat;
   double            PL_Lon;
   float             PL_Alt;

   float             PL_DeltaPos;
   float             PL_TotalDist;
   float             PL_TotalStrtDist;
   unsigned char     PL_NumHighSpeedEpochs;
   float             PL_ManeuverAnglePL;
   double            tow; /**TOW*/

}  tQdr2NvmData;


/**Nav Auxillary Init Data structure*/
typedef struct _tqdrnlAuxInit  /* Message 64 Sid 1 */
{
   unsigned int time_init_unc;         /**< Initial time uncertainty (usec) */
   unsigned short saved_pos_week;      /**< Week of saved position */
   unsigned int saved_pos_tow;         /**< Time of week of saved position (sec) */
   unsigned short saved_pos_ehe;       /**< EHE of saved position (100m) */
   unsigned short saved_pos_eve;       /**< EVE of saved position (m) */
   unsigned char  sw_version;          /**< Tracker SW version */
   unsigned char  icd_version;         /**< Tracker ICD version */
   unsigned short chip_version;        /**< Tracker HW Chip version */
   unsigned int acq_clk_speed;         /**< Default rate of Tracker's internal clock (Hz) */
   unsigned int default_clock_offset;  /**< Default freq offset of Tracker's internal clock (Hz) */
   unsigned int tracker_status;        /**< Tracker System status:
                                        * Bit 0: Status 0=good; 1=bad
                                        * Bit 1: Cache  0=Disable; 1=Enable
                                        * Bit 2: RTC    0=Invalid; 1=Valid
                                        * Bit 3-31: reserved
                                        */

   unsigned int reserved;

} tqdrnlAuxInit;

/**Complete structured of NVM Data retrieved*/
/**Diag ID QDR_DIAG_GNSS_NAVINIT_DATA*/
typedef struct _tQdrNavInitData  /* Message 31 and 64,1 */
{
   tqdrnlInit nl_init;
   tqdrnlAuxInit nl_auxinit;
} tQdrNavInitData;

/**Complete structure for injected PVT solution from both
   GNSS only sources and precise position (PPE/RTK) sources */
/**Diag ID ??*/

/** tQdrInjNavReport:valid_mask */
#define QDR_INJ_NAV_POS_FIX_VALID          0x00000001 /**< Position Solution valid */
#define QDR_INJ_NAV_VEL_FIX_VALID          0x00000002 /**< Velocity Solution valid */
#define QDR_INJ_NAV_POS_FIX_ALT_AIDED      0x00000004 /**< Position Solution is Altitude aided */
#define QDR_INJ_NAV_POS_FIX_DGPS           0x00000008 /**< Solution uses DGPS Corrections */
#define QDR_INJ_NAV_FIX_KF                 0x00000010 /**< Solution is Kalman Filtered output */
#define QDR_INJ_NAV_FIX_LSQ                0x00000020 /**< Solution is Least Squares output */

#define QDR_INJ_NAV_TOW_KNOWN              0x00010000 /**< Solution reported TOW is valid */
#define QDR_INJ_NAV_TOW_WEEK_KNOWN         0x00020000 /**< Solution reported TOW & Week are valid */
#define QDR_INJ_NAV_GLON_TOD_KNOWN         0x00040000 /**< Solution reported GLONASS TOD is valid */
#define QDR_INJ_NAV_GLON_DAY_KNOWN         0x00080000 /**< Solution reported GLONASS Day Number is valid */
#define QDR_INJ_NAV_TOW_SOLVE_FOR_TIME     0x00100000 /**< Solution reported TOW is through Solve for Time */
#define QDR_INJ_NAV_TOW_KF_SOLN            0x00200000 /**< Solution reported TOW is from KF output */
#define QDR_INJ_NAV_CLKB_KNOWN             0x00400000 /**< Solution reports valid Clock Bias */
#define QDR_INJ_NAV_PPE_FLOAT_SOLN         0x00800000 /**< Precise Solution used floating ambiguity resolution */

typedef struct
{
   uint32_t valid_mask;          /**< Bit mask as defined above */
   uint16_t week_no;             /**< Extended GPS Week. -1 = invalid */
   uint32_t tow;                 /**< GPS TOW [ms] */
   uint8_t num_sv_used;          /**< Number of Satellite Measurements used in the solution */
   float time_unc;               /**< Time uncertainty of the solution [s] */
   double latitude;              /**< Latitude of the solution [rad] */
   double longitude;             /**< Longitude of the solution [rad] */
   float hor_unc_ell_semi_maj;   /**< Semi-major of the horizontal rms uncertainty ellipse [m]*/
   float hor_unc_ell_semi_min;   /**< Semi-minor of the horizontal rms uncertainty ellipse [m]*/
   float hor_unc_ell_orient_az;  /**< Orientation w.r.t. North Pole of the horizontal rms uncertainty ellipse [rad]*/
   float north_unc;              /**< North Position rms uncertainty [m] */
   float east_unc;               /**< East Position rms uncertainty[m] */
   float alt_wrt_ellipsoid;      /**< Altitude w.r.t. WGS-84 Ellipsoid [m]*/
   float alt_unc;                /**< Altitude rms uncertainty [m] */
   float heading;                /**< Heading [degrees] */
   float heading_unc;            /**< Heading uncertainty rms [degrees] */
   float vel_NED[3];             /**< Velocity in NED [m/s] */
   float vel_NED_unc[3];         /**< Velocity rms uncertainty [m/s] */
   double clk_bias;              /**< Local Clock bias estimate [m] */
   float clk_bias_unc;           /**< Local Clock bias estimate rms uncertainty [m] */
   float clk_drift;              /**< Local Clock drift estimate [s/s] */
   float clk_drift_unc;          /**< Local Clock drift estimate rms uncertainty [s/s] */
   float DOP[3];                 /**< Dilution of Precision metrics HDOP, VDOP, PDOP */
   qdr_svid svid[QDR_MAX_MEAS_USED_IN_FIX]; /**< List of SV IDs used in the fix */
   qdr_signal signalBand[QDR_MAX_MEAS_USED_IN_FIX]; /**< List of SV IDs used in the fix */
   float res[64];                /**< PR Residuals of upto num_sv_used SVs [m] */
} tQdrInjNavReport;

typedef struct {
   float fsu[3]; /* Lever Arm : Forward, sideways and Up in meters */
   uint8_t la_valid; /* validity check passed */
} tQdrFactoryLeverArm;

typedef struct
{
   /* roll, pitch, yaw absolute w.r.t. the sensor X,Y,Z */
    float roll;
    float pitch;
    float yaw;
    float unc;
    uint8_t valid;
} tQdrFactoryB2S;

typedef enum {
   QDR_CORE_CONFIG_CAN_DO_NOT_USE,
   QDR_CORE_CONFIG_CAN_MANDATORY,
   QDR_CORE_CONFIG_CAN_OPTIONAL
} tQdrCanMode;

typedef struct
{
   uint8_t              pos_filter;        /**< Position Filter mode 0 = OFF, 1 = ON */
   uint8_t              snapshot_period;   /**< QDR Snapshot rate 0 = OFF, 1 = 1s, 2 = 10s, 3 = 50s, 4 = 100s */
   uint8_t              sensor_test_off;   /**< Disable sensor tests */
   uint8_t              can_mode;          /**< 0 = do not use, 1 = mandatory, 2 = optional */
   tQdrFactoryB2S       factory_b2s;       /**< Factory b2s wrt. sensor xyz. user input in degrees*/
   tQdrFactoryLeverArm  lever_arm;         /**< QDR input Lever Arm from GNSS antenna to IMU */
   uint8_t              pad[30];           /**< Padding to ensure structure is 64 bytes in size.
                                             *< Decrement the size when new fields are added
                                             */
} tQdrConfig;

/* QDR Core API Diag Structure for 6DOF Nav State and mirror of MI_DR_A6DOF_NAV_STATE Data for OSP message 48,20*/
/**Diag ID QDR_DIAG_A6DOF_NAVSTATE*/
typedef struct _tQdrA6DOFNavstate {
   double              tow;                  /**< GPS TOW [s] */
   unsigned char       a6dof_state;          /**< A6DOF internal state [0..4] */
   unsigned long long  a6dof_error_report;   /**< A6DOF internal error reports bitmask */
   unsigned char       calibration_percent;  /**< A6DOF Calibration percentage [0..100] */
   unsigned char       OkAcrossReset;        /**< Calibration OK to use across reset */
   unsigned char       sensor_valid;         /**< Sensor data valid bitmask
                                              * 0x01 - 6DOF
                                              * 0x02 - ODO
                                              * 0x04 - Gear
                                              */
   char                prerot;               /**< Sensor pre-rotation index [-3,-2,-1,1,2,3] */
   char                stationary;           /**< 0 = Moving, 1 = Stationary, -1 = Indeterminate */
   char                motion;               /**< 0 = NOT Moving, 1 = Moving, -1 = Indeterminate */
   char                constantVel;          /**< Constant Velocity observed */
   float               Yaw;                  /**< B2S Yaw Estimate [deg] */
   unsigned int        yaw_status;           /**< B2S Yaw Estimate status */
   unsigned char       yaw_gain;             /**< B2S Yaw Gain [1..50] */
   unsigned char       yaw_ctr;              /**< B2S Yaw Estimate progress counter */
   float               Roll;                 /**< B2S Roll Estimate [deg] */
   float               pitch;                /**< B2S Pitch Estimate [deg] */
   unsigned int        rp_status;            /**< B2S Roll and Pitch Estimate status */
   unsigned char       roll_pitch_gain;      /**< B2S Yaw Gain [1..50] */
   unsigned char       rp_ctr;               /**< B2S Roll and Pitch Estimate progress counter */
   float               gyro_delta;           /**< Gyro delta observed in 1s accumulation [rad/s] */
   unsigned int        gyro_status;          /**< Gyro Scale Factor estimate status */
   unsigned char       gyro_gain;            /**< Gyro Scale Factor estimate gain [1..50] */
   unsigned char       gsf_stm_state;        /**< Gyro Scale Factor state */
   float               gsf_stm_gnss_accum;   /**< Gyro SF accumulated GNSS heading change [deg] */
   float               gsf_stm_gyro_accum;   /**< Gyro SF accumulated Gyro [deg] */
   float               gyro_bias_0;          /**< KF estimated Gyro bias for axis 0 */
   float               gyro_bias_1;          /**< KF estimated Gyro bias for axis 1 */
   float               gyro_bias_2;          /**< KF estimated Gyro bias for axis 2 */
   float               gyro_sf;              /**< Gyro Scale Factor estimate */
   float               acc_delta;            /**< Accel delta observed in 1s accumulation [m/s^2] */
   float               acc_bias_0;           /**< KF estimated Accel bias for axis 0 */
   float               acc_bias_1;           /**< KF estimated Accel bias for axis 1 */
   float               acc_bias_2;           /**< KF estimated Accel bias for axis 2 */
   float               acc_sf_0;             /**< Accel axis 0 Scale Factor estimate */
   float               acc_sf_1;             /**< Accel axis 1 Scale Factor estimate */
   float               acc_sf_2;             /**< Accel axis 2 Scale Factor estimate */
   float               ns_roll;              /**< Body frame roll [deg] */
   float               ns_pitch;             /**< Body frame pitch [deg] */
   float               ns_yaw;               /**< Body frame yaw [deg] */
   float               Roll_e;               /**< Body frame roll rms uncertainty [deg] */
   float               Pitch_e;              /**< Body frame pitch rms uncertainty [deg] */
   float               Yaw_e;                /**< Body frame yaw rms uncertainty [deg] */
} tQdrA6DOFNavstate;

/* QDR Core API Diag Structure for GNSS odo Info MI_DR_A6DOF_GNSS_ODO for OSP message 48,21 */
/**Diag ID QDR_DIAG_A6DOF_GNSS_ODO_INFO*/
typedef struct _tQdrA6DOFGnssOdoInfo {
   double              tow;                  /**< GPS TOW [s] */
   unsigned short      gnss_valid;           /**< GNSS PVT solution validity mask */
   float               hdg;                  /**< GNSS Heading [deg] */
   float               hdg_rate;             /**< GNSS Heading Rate [deg/s] */
   float               gnss_pitch;           /**< GNSS Pitch [deg] */
   float               spd;                  /**< GNSS Speed [m/s] */
   float               spd_rate;             /**< GNSS Speed Rate [m/s^2] */
   float               odo;                  /**< Odo average speed in 1s [m/s] */
   unsigned char       reverse_from_prndl;   /**< 1 = Reverse, 0 = Forward */
   char                reverse_output;       /**< KF Reverse status
                                              *  1 = Reverse
                                              *  0 = Forward
                                              * -1 = Indeterminate
                                              */
   float               odo_sf;               /**< Odo Scale Factor (SF) estimate */
   unsigned int        odo_status;           /**< Odo SF estimate status */
   unsigned char       odo_gain;             /**< Odo SF estimate gain [1..50] */
   float               gnss_spd_accum;       /**< Odo SF estimation accumulated GNSS speed */
   float               odo_accum;            /**< Odo SF estimation accumulated Odo speed */
} tQdrA6DOFGnssOdoInfo;

/* QDR Core API Diag Structure for GNSS Channel Info. mirror of MI_DR_A6DOF_GNSS_CHAN for OSP message 48,22 */
typedef struct _tQdrA6DOFGnssChanInfo {
   unsigned char       gnss_meas_available;  /**< Measurement used in solution */
   qdr_svid            sv_id;                /**< GNSS SV ID */
   float               pr_res;               /**< Pseudo-Range apriori residual [m] */
   float               dr_res;               /**< Pseudo-Range Rate apriori residual [m/s] */
   unsigned short      sv_elevation;         /**< SV Elevation [0.01 deg] */
   unsigned short      sv_azimuth;           /**< SV Azimuth [0.01 deg] */
   float               sv_meas_avg_pwr;      /**< SV Average Power [dBHz] */
} tQdrA6DOFGnssChanInfo;

/* QDR Core A6DOF Snapshot related structures */
/* No comments are provided as these are expected to be treated as a
   blob of data */
typedef struct {
   uint8_t  secondary_constell;
   double   tow;
   float    icb;
   float    icb_var;
   float    icb_drift_var;
   uint32_t gain;
   float    icb_rej_sigma;
   uint32_t icb_rej_count;
   float    icb_rej_res;
} tQdrICBEst;

typedef struct
{
   uint32_t          ts;
   uint32_t          tow;
   int16_t           gps_week;

   uint8_t           pr_nsv;
   uint8_t           dr_nsv;
   uint8_t           fix_validated;
   uint8_t           valid_cnt;
   float             gnss_dt;
   float             no_gnss_time;

   int8_t            prerot;
   int8_t            reverse;
   int8_t            stationary;
   int8_t            motion;
   int8_t            cons_speed;
   uint8_t           calibration_percent;

   uint32_t          ppe_tow;
   uint8_t           ppe_aid_valid;

   /* Sensor Estimates */
   float             apx_clkd;
   uint8_t           apx_clkd_gain;
   uint32_t          apx_clkd_dt_sum;
   uint32_t          apx_clkd_dt_count;
   uint32_t          apx_clkd_prev_sens_rate;

   uint16_t          sensor_rate_Hz;
   uint8_t           sensor_rate_gain;
   uint16_t          sensor_rate_mismatch;
   uint8_t           sensor_rate_err_count;
   uint32_t          sensor_rate_dt_sum;
   uint8_t           sensor_rate_dt_count;
   uint16_t          sensor_rate_prev_set_validity;
   uint32_t          sensor_rate_prev_set_time;

   float             sensor_clkd;
   float             sensor_ap_clkd;
   uint8_t           sensor_clkd_gain;
   uint64_t          sensor_clkd_prev_pps_ms;
   uint8_t           sensor_clkd_prev_pps_valid;
   uint32_t          sensor_clkd_prev_pps_tow;
   uint32_t          sensor_clkd_sensor_sample_period;
   uint32_t          sensor_clkd_sensor_sample_count;
   uint64_t          sensor_clkd_sample_period_start_pps_ms;
   uint64_t          sensor_clkd_sensor_sample_start_ms;
   uint16_t          sensor_clkd_last_proc_set_validity;
   uint32_t          sensor_clkd_last_proc_set_time;

   /* OSF */
   float             osf;
   uint32_t          osf_status;
   uint8_t           osf_gain;
   uint8_t           osf_active;
   uint8_t           osf_fail_count;
   float             osf_cutoff;
   float             osf_gnss_accum;
   float             osf_odo_accum;

   /* GSF */
   float             gsf;
   uint32_t          gsf_status;
   uint8_t           gsf_gain;
   uint8_t           gsf_fail_count;
   uint8_t           gsf_state;
   float             gsf_gnss_accum;
   float             gsf_gyro_accum;

   /* B2S estimates */
   float             b2s[3];
   uint32_t          b2s_rp_status;
   uint32_t          b2s_yaw_status;
   uint8_t           b2s_sta_cnt;
   uint8_t           b2s_rp_gain;
   uint8_t           b2s_yaw_gain;
   uint8_t           b2s_rp_ctr;
   uint8_t           b2s_yaw_ctr;
   float             b2s_roll_sum;
   float             b2s_pitch_sum;
   float             b2s_sin_yaw_sum;
   float             b2s_cos_yaw_sum;
   float             b2s_sta_acc[3];
   float             b2s_sta_gyro[3];
   float             b2s_tm_gyr_accum[3];
   float             b2s_tm_roll;
   float             b2s_tm_pitch;
   uint8_t           b2s_tm_ctr;
   uint8_t           b2s_tm_gain;
   uint8_t           b2s_tm_turn;
   uint32_t          b2s_tm_state;
   uint32_t          b2s_tm_status;

   /* GNSS signal loss estimate */
   float             gnss_offset;
   uint8_t           gnss_offset_ctr[12];

   /* ICB estimates */
   uint8_t           primary_constell;
   tQdrICBEst        icb_est[8];

   /* A6DOF Nav States */
   double            llh[3];
   float             vel_ned[3];
   float             att[3];
   float             acc_bias[3];
   float             gyro_bias[3];
   double            clk_bias;
   float             clk_drift;

   /* A6DOF Nav Filter Covariance Matrix */
   float             u[17 * (17 + 1) / 2];
   float             factory_b2s[4];
   uint8_t           factory_b2s_status;
   float             factory_lever_arm[3];
   uint8_t           factory_la_valid;
} tQdrA6DOFSnapshot;

/* QDR Core API Diag Structure for GNSS Channel data. Mirror of MI_DR_A6DOF_GNSS_CHAN_LIST for OSP message 48,22 */
/**Diag ID QDR_DIAG_A6DOF_GNSS_CHAN_INFO*/
typedef struct _tQdrA6DOFGnssChanList {
   double               tow;
   unsigned char        num_chan;
   tQdrA6DOFGnssChanInfo gnss_chan_list[QDR_MAX_NUM_MEAS];
} tQdrA6DOFGnssChanList;

/* QDR2 Core API Diag Structure for NavState and mirror of MI_DR_NAV_STATUS and MI_DR_NAV_STATE Data
   for OSP message 48,1 and 48,2 respectively */
/**Diag ID QDR2_DIAG_NAVSTATUS*/
typedef struct _tQdr2NavStatus {
      unsigned int  Nav;         /**< DR Navigation Validity:
                                  *  0 = DR Nav is valid
                                  *  otherwise, bit map as follows:
                                  *    Bit 0 : 1 = GPS Only Required
                                  *    Bit 1 : 1 = Speed is not 0 at startup
                                  *    Bit 2 : 1 = DR Position is not valid
                                  *    Bit 3 : 1 = DR Heading is not valid
                                  *    Bit 4 : 1 = DR Calibration is not valid
                                  *    Bit 5 : 1 = DR Data is not valid
                                  *    Bit 6 : 1 = System has gone into Cold Start
                                  *    Bit 7 : reserved
                                  */
      unsigned short Data;       /**< DR Data Validity:
                                  *  0 = DR Data is valid
                                  *  otherwise, bit map as follows:
                                  *    Bit 0 : 1 = DR Gyro Subsystem Operational is false
                                  *    Bit 1 : 1 = DR Speed Subsystem Operational is false
                                  *    Bit 2 : 1 = DR Measurement Time < 0
                                  *    Bit 4 : 1 = No DR Data for > 2 seconds
                                  *    Bit 5 : 1 = DR Data timestamp did not advance
                                  *    Bit 6 : 1 = DR data bytes all 0x00 or all 0xff
                                  *    Bit 7 : 1 = Composite wheeltick count jumped too much
                                  *                (by more than 400) between successive DR messages
                                  *    Bit 8 : 1 = Input Gyro data bits value of 0x0000 or 0x3fff
                                  *    Bit 9 : 1 = More than 10 DR messages in one second
                                  *    Bit 10: 1 = Delta time <= 0
                                  *    other bits are reserved
                                  */
      unsigned int  Cal_GbCal;       /* DR Calibration Validity (Bits 0 to 3):
                               *  0 = DR Calibration is valid
                               *  otherwise, bit map as follows:
                               *    Bit 0 : 1 = DR Gyro Bias cal is not valid
                               *    Bit 1 : 1 = DR Gyro Scale Factor cal is not valid
                               *    Bit 2 : 1 = DR Speed Scale Factor cal is not valid
                               *    Bit 3 : 1 = GPS calibration is required and is not yet available
                               * DR Gyro Bias Calibration Validity (Bits 4 to 6):
                               *  0 = DR Gyro Bias Calibration is valid
                               *  otherwise, bit map as follows:
                               *    Bit 4 : 1 = DR Data is not valid
                               *    Bit 5 : 1 = Zero-Speed Gyro Bias Calibration was not updated
                               *    Bit 6 : 1 = Heading Rate Scale Factor <= -1
                               */
      unsigned int  GsfCal_SsfCal;   /* DR Gyro Scale Factor Calibration Validity (Bits 0 to 3):
                               *  0 = DR Gyro Scale Factor calibration is valid
                               *  otherwise, bit map as follows:
                               *    Bit 0 : 1 = DR Heading is not valid
                               *    Bit 1 : 1 = DR Data is not valid
                               *    Bit 2 : 1 = DR Position is not valid
                               *    Bit 3 : 1 = Heading Rate Scale Factor <= -1
                               * DR Speed Scale Factor Calibration Validity (Bits 4 to 7):
                               *  0 = DR Speed Scale Factor calibration is valid
                               *  otherwise, bit map as follows:
                               *    Bit 4 : 1 = DR Data is not valid
                               *    Bit 5 : 1 = DR Position is not valid
                               *    Bit 6 : 1 = GPS velocity is not valid for DR
                               *    Bit 7 : 1 = DR Speed Scale Factor <= -1
                               */
      unsigned int  NavAcrossReset_Pos; /* DR Nav Validity across reset (Bits 0 to 1):
                                  *  0 = DR Nav is valid across reset
                                  *  otherwise, bit map as follows:
                                  *    Bit 0 : 1 = DR Navigation is not valid
                                  *    Bit 1 : 1 = Speed > 0.1 m/sec
                                  * DR Position Validity (Bits 3 to 6):
                                  *  0 = DR Position is valid
                                  *  otherwise, bit map as follows:
                                  *    Bit 3 : 1 = Speed != 0 at startup
                                  *    Bit 4 : 1 = GPS Position is not valid
                                  *    Bit 5 : 1 = System has gone into Cold Start
                                  *    Bit 6 : 1 = DR Data is not valid
                                  * Bits 2 and 7 : reserved
                                  */
      unsigned int  Hd;               /* DR Heading Validity (Bits 0 to 6):
                                *  0 = DR Heading is valid
                                *  otherwise, bit map as follows:
                                *    Bit 0 : 1 = Speed != 0 at startup
                                *    Bit 1 : 1 = GPS Position is not valid
                                *    Bit 2 : 1 = GPS Speed is not valid
                                *    Bit 3 : 1 = GPS Updated Heading flag is false
                                *    Bit 4 : 1 = Delta GPS Time <= 0.0 or >= 2.0
                                *    Bit 5 : 1 = System has gone into Cold Start
                                *    Bit 6 : 1 = DR Data is not valid
                                * Other bits are reserved
                                */
      unsigned int  GyrSubOp_SpdSubOp; /* DR Gyro Subsystem Operational (Bits 0 to 2):
                                 *  0 = OK
                                 *  otherwise, bit map as follows:
                                 *    Bit 0 : 1 = High, Persistent Turn Rate
                                 *    Bit 1 : 1 = Low, Persistent Turn Rate
                                 *    Bit 2 : 1 = Gyro Turn Rate residual is too large
                                 * DR Speed Subsystem Operational (Bits 4 to 6):
                                 *  0 = OK
                                 *  otherwise, bit map as follows:
                                 *    Bit 4 : 1 = DR Speed Data = 0 when GPS Speed != 0
                                 *    Bit 5 : 1 = DR Speed Data != 0 when GPS Speed = 0
                                 *    Bit 6 : 1 = DR Speed residual is too large
                                 * Other bits are reserved.
                                 */
      unsigned int  NavStIntRan_ZGbCalUpd; /* DR Nav State Integration Ran (Bits 0 to 2):
                                     *  0 = OK
                                     *  otherwise, bit map as follows:
                                     *    Bit 0 : 1 = DR Position is not valid
                                     *    Bit 1 : 1 = DR Heading is not valid
                                     *    Bit 2 : 1 = DR Data is not valid
                                     * Zero-Speed Gyro Bias Calibration Updated (Bits 4 to 6):
                                     *  0 = Updated
                                     *  otherwise, bit map as follows:
                                     *    Bit 4 : 1 = GPS Speed > 0.1 m/sec
                                     *    Bit 5 : 1 = Zero Speed During Cycle is false
                                     *    Bit 6 : 1 = Zero Speed Previous is false
                                     * Other bits are reserved.
                                    */
      unsigned int  GbsfCalUpd_SpdCalUpd_UpdNavSt; /* DR Gyro Bias and Scale Factor Calibration Updated (Bits 0 to 3):
                                             *  0 = Updated
                                             *  otherwise, bit map as follows:
                                             *    Bit 0 : 1 = DR Data is not valid
                                             *    Bit 1 : 1 = DR Position is not valid
                                             *    Bit 2 : 1 = GPS velocity is not valid for DR
                                             *    Bit 3 : 1 = GPS Updated Heading is false
                                             * DR Speed Calibration Updated (Bits 4 to 6):
                                             *  0 = Updated
                                             *  otherwise, bit map as follows:
                                             *    Bit 4 : 1 = DR Data is not valid
                                             *    Bit 5 : 1 = DR Position is not valid
                                             *    Bit 6 : 1 = GPS velocity is not valid for DR
                                             * DR Navigation State Updated (Bit 7)
                                             *    0 = Updated;  1 = DR Navigation is not valid
                                            */
      unsigned int  GpsUpdPos;       /* GPS Updated Position (Bits 0 to 7):
                               *  0 = Updated
                               *  otherwise, bit map as follows:
                               *    Bit 0 : 1 = Update Mode != KF
                               *    Bit 1 : 1 = EHE > 10.0
                               *    Bit 2 : 1 = No previous GPS KF update < 4 SVs
                               *    Bit 3 : 1 = GPS EHPE > DR EHPE
                               *    Bit 4 : 1 = DR EHPE < 10 even if GPS EHPE < DR EHPE
                               *    Bit 5 : 1 = Less than 4 SVs
                               *    Bit 6 : 1 = 0 SV
                               *    Bit 7 : 1 = DR NAV ONLY required
                              */
      unsigned int  GpsUpdHd;        /* GPS Updated Heading (Bits 0 to 6):
                               *  0 = Updated
                               *  otherwise, bit map as follows:
                               *    Bit 0 : 1 = Update Mode != KF
                               *    Bit 1 : 1 = GPS Speed <= 2.0 m/sec
                               *    Bit 2 : 1 = Less than 4 SVs
                               *    Bit 3 : 1 = Horizontal Velocity Variance > 1.0 (m/sec)*(m/sec)
                               *    Bit 4 : 1 = GPS Heading Error >= DR Heading Error * 1.2
                               *    Bit 5 : 1 = GPS KF Updated is false
                               *    Bit 6 : 1 = Initial Speed Transient is not complete
                               *    Bit 7 : Reserved
                              */
      unsigned int  GpsPos_GpsVel;   /* GPS Position Validity for DR (Bits 0 to 2):
                               *  0 = Valid
                               *  otherwise, bit map as follows:
                               *    Bit 0 : 1 = Less than 4 SVs
                               *    Bit 1 : 1 = EHPE > 30
                               *    Bit 2 : 1 = GPS Updated Position is false
                               * Bit 3 : reserved
                               * GPS Velocity Validity for DR (Bits 4 to 7):
                               *  0 = Valid
                               *  otherwise, bit map as follows:
                               *    Bit 4 : 1 = GPS Position is not valid for DR
                               *    Bit 5 : 1 = EHVE > 3
                               *    Bit 6 : 1 = GPS Speed < 2 m/sec
                               *    Bit 7 : 1 = GPS did not update the Heading
                              */
      unsigned int  DWSHdRtSFCalValid; /* DWS Heading Rate Scale Factor Calibration Validity:
                                 *  0 = Valid
                                 *  otherwise, bit map as follows:
                                 *    Bit 0 : 1 = Heading Rate Scale Factor <= -1.0
                                 *    Bits 1 - 7 : Reserved
                                */
      unsigned int  DWSHdRtSFCalUpd; /* DWS Heading Rate Scale Factor Calibration Was Updated:
                               *  0 = Updated
                               * otherwise, bit map as follows:
                               *    Bit 0 : 1 = GPS Heading Rate is not valid
                               *    Bit 1 : 1 = Absolute value of GPS Heading Rate < 5.0
                               *    Bit 2 : 1 = Absolute value of GPS Heading Rate >= 90.0
                               *    Bit 3 : 1 = Left Rear Speed SF Cal is not valid
                               *    Bit 4 : 1 = Right Rear Speed SF Cal is not valid
                               *    Bit 5 : 1 = Absolute value of prev Rear Axle Hd Rt <= 0.0
                               *    Bit 6 : 1 = (GPS Hd Rt * prev Rear Axle Hd Rt) <= 1.0
                               *    Bit 7 : reserved
                              */
      unsigned short DWSSpdSFCalValid; /* DWS Speed Scale Factor Calibration Validity:
                                *  0 = Valid
                                * otherwise, bit map as follows:
                                *  Bit 0 : 1 = Right Rear Speed SF <= -1.0
                                *  Bit 1 : reserved for RR status
                                *  Bit 2 : reserved for RR status
                                *  Bit 3 : reserved for RR status
                                *  Bit 4 : 1 = Left Rear Speed SF <= -1.0
                                *  Bit 5 : reserved for LR status
                                *  Bit 6 : reserved for LR status
                                *  Bit 7 : reserved for LR status
                                *  Bit 8 : 1 = Right Front Speed SF <= -1.0
                                *  Bit 9 : reserved for RF status
                                *  Bit 10: reserved for RF status
                                *  Bit 11: reserved for RF status
                                *  Bit 12: 1 = Left Front Speed SF <= -1.0
                                *  Bit 13: reserved for LF status
                                *  Bit 14: reserved for LF status
                                *  Bit 15: reserved for LF status
                               */
      unsigned int DWSSpdSFCalUpd;    /* DWS Speed Scale Factor Cal was updated:
                                *  0 = Updated
                                * otherwise, bit map as follows:
                                *  Bit 0 : 1 = GPS Speed is not valid for DR
                                *  Bit 1 : 1 = GPS Heading Rate is not valid
                                *  Bit 2 : 1 = Absolute value of GPS Hd Rate >= 0.23
                                *  Bit 3 : 1 = GPS Heading Rate Error >= 0.5
                                *  Bit 4 : 1 = Average GPS Speed <= 0.0
                                *  Bit 5 : 1 = DR Position is not valid
                                *  Bits 6 - 7 : reserved
                               */

} tQdr2NavStatus;

/* QDR2 Core API Diag Structure for NavState and mirror of MI_DR_NAV_STATE Data for OSP message 48,2*/
/**Diag ID QDR2_DIAG_NAVSTATE*/
typedef struct _tQdr2NavState {
   unsigned short Spd;              /**< DR Speed [0.01 m/s] */
   unsigned short SpdE;             /**< DR Speed Error [0.01 m/s] */
   short  Ssf;                      /**< DR Speed Scale Factor scaled by 1000 */
   unsigned short SsfE;             /**< DR Speed Scale Factor Error scaled by 1000 */
   short  HdRte;                    /**< DR Heading Rate [0.01 deg/s] */
   unsigned short HdRteE;           /**< DR Heading Rate Error [0.01 deg/s] */
   short  Gb;                       /**< DR Gyro Bias [0.01 deg/s] */
   unsigned short GbE;              /**< DR Gyro Bias Error [0.01 deg/s] */
   short  Gsf;                      /**< DR Gyro Scale Factor scaled by 1000 */
   unsigned short GsfE;             /**< DR Gyro Scale Factor Error scaled by 1000 */
   unsigned int TPE;                /**< Total DR Position Error [0.01 m] */
   unsigned short THE;              /**< Total DR Heading Error [0.01 deg] */
   unsigned char NavCtrl;           /**< DR Nav Mode Control:
                                     *   0x01 = GPS Only Navigation Required (No DR Nav Allowed)
                                     *   0x02 = GSP + DR using default or stored calibration
                                     *   0x03 = GPS + DR using current GPS calibration
                                     *   0x04 = DR Only Navigation (no GPS)
                                    */
   unsigned char Reverse;           /**< DR Direction:  0 = forward; 1 = reverse */
   unsigned short Hd;               /**< DR Heading [0.01 deg/s] */
   unsigned char SensorPkg;         /**< Identify which sensor package used:
                                     *   0 = Gyro and Odo
                                     *   1 = Wheel Speed and Odo
                                     */
   unsigned short OdoSpd;           /**< Odometer Speed [0.01 m/s] */
   short  OdoSpdSF;                 /**< Odometer Speed Scale Factor scaled by 1000 */
   unsigned short OdoSpdSFErr;      /**< Odometer Speed Scale Factor Error scaled by 1000 */
   short  LFWheelSpdSF;             /**< Left Front Wheel Speed Scale Factor scaled by 1000 */
   unsigned short LFWheelSpdSFErr;  /**< Left Front Wheel Speed Scale Factor Error scaled by 1000 */
   short  RFWheelSpdSF;             /**< Right Front Wheel Speed Scale Factor scaled by 1000 */
   unsigned short RFWheelSpdSFErr;  /**< Right Front Wheel Speed Scale Factor Error scaled by 1000 */
   short  LRWheelSpdSF;             /**< Left Rear Wheel Speed Scale Factor scaled by 1000 */
   unsigned short LRWheelSpdSFErr;  /**< Left Rear Wheel Speed Scale Factor Error scaled by 1000 */
   short  RRWheelSpdSF;             /**< Right Rear Wheel Speed Scale Factor scaled by 1000 */
   unsigned short RRWheelSpdSFErr;  /**< Right Rear Wheel Speed Scale Factor Error scaled by 1000 */
   short  RearAxleSpdDelta;         /**< Rear Axle Speed Delta [0.01 m/s] */
   unsigned short RearAxleAvgSpd;   /**< Rear Axle Average Speed [0.01 m/s] */
   unsigned short RearAxleSpdErr;   /**< Rear Axle Speed Error [0.01 m/s] */
   short  RearAxleHdRt;             /**< Rear Axle Heading Rate [0.01 deg/s] */
   unsigned short RearAxleHdRtErr;  /**< Rear Axle Heading Rate Error [0.01 deg/s] */
   short  FrontAxleSpdDelta;        /**< Front Axle Speed Delta [0.01 m/s] */
   unsigned short FrontAxleAvgSpd;  /**< Front Axle Average Speed [0.01 m/s] */
   unsigned short FrontAxleSpdErr;  /**< Front Axle Speed Error [0.01 m/s] */
   short  FrontAxleHdRt;            /**< Front Axle Heading Rate [0.01 deg/s] */
   unsigned short FrontAxleHdRtErr; /**< Front Axle Heading Rate Error [0.01 deg/s] */
} tQdr2NavState;

typedef struct _tQdr2NavSubSys{
   short          GpsHdRte;     /**< GPS Heading Rate [0.01 deg/s] */
   unsigned short GpsHdRteE;    /**< GPS Heading Rate Error [0.01 deg/s] */
   unsigned short GpsHd;        /**< GPS Heading [0.01 deg] */
   unsigned short GpsHdE;       /**< GPS Heading Error [0.01 deg] */
   unsigned short GpsSpd;       /**< GPS Speed [0.01 m/s] */
   unsigned short GpsSpdE;      /**< GPS Speed Error [0.01 m/s] */
   unsigned int   GpsPosE;      /**< GPS Position Error [0.01 m] */
   short          DrHdRte;      /**< DR Heading Rate [0.01 m/s] */
   unsigned short DrHdRteE;     /**< DR Heading Rate Error [0.01 m/s] */
   unsigned short DrHd;         /**< DR Heading [0.01 deg] */
   unsigned short DrHdE;        /**< DR Heading Error [0.01 deg] */
   unsigned short DrSpd;        /**< DR Speed [0.01 m/s] */
   unsigned short DrSpdE;       /**< DR Speed Error [0.01 m/s] */
   unsigned int   DrPosE;       /**< DR Position Error [0.01 m] */
   unsigned char  DrCalPercent; /**< DR calibration Percentage [0..100] */
   unsigned char  Reserved;
} tQdr2NavSubSys;


typedef enum
{
   eQDR_DIAGLOG_SENSOR_DATA_PRODUCED,
   eQDR_DIAGLOG_SENSOR_DATA_CONSUMED,
   eQDR_DIAGLOG_QDR_A6DOF_NF_STATE_KF,
   eQDR_DIAGLOG_QDR_A6DOF_NF_STATE_LSQ,
   eQDR_DIAGLOG_QDR_A6DOF_NF_STATE_PREROTATION,
   eQDR_DIAGLOG_QDR_A6DOF_NF_STATE_B2S_RP,
   eQDR_DIAGLOG_QDR_A6DOF_NF_STATE_B2S_YAW,
   eQDR_DIAGLOG_QDR_A6DOF_NF_STATE_NAVIGATING,
   eQDR_DIAGLOG_QDR_NAVLITE_START,
   eQDR_DIAGLOG_QDR_NAVLITE_END
} dr_gluediagevent;


/** QDR Core callbacks definitions */
typedef void         (* qdr_cb_reportSvStatus_t)(tQdrSvStateData *pQdrSvstatusData);

typedef void         (* qdr_cb_reportPosition_t)(tQdrNavigationData *pQdrNavData,
                                                 tQdrCoreNavBfdParams *pQdrBFData);

typedef void         (* qdr_cb_clearNVData_t)(unsigned char dataIDToClear);

typedef qdr_return   (* qdr_cb_getSVState_t)(unsigned char svid,
                                             unsigned int signal,
                                             double measTow,
                                             tQdrSVState *pSvState);

typedef qdr_return   (* qdr_cb_getDGPSCorrection_t)(unsigned char svid,
                                                    unsigned int signal,
                                                    double measTow,
                                                    tQdrDGPSMeasStruct *pDGPS);
typedef void         (* qdr_cb_reportNavInitData_t)(tQdrNavInitData *pQdrNavInitData);

typedef qdr_return   ( *qdr_cb_getPPSInfo_t)(double *tow,
                                             uint64_t *aptime_us,
                                             float *aptime_unc_us );

typedef qdr_return   ( *qdr_cb_getNavReport_t)( tQdrInjNavReport *nav_report );



/** QDR Core Platform callbacks definitions */
typedef void         (* qdr_cb_debugLog_t)(const char *pFmt,
                                           int cnt);

typedef unsigned int (* qdr_getsystime_t)(void);

typedef qdr_return   (* qdr_log_diagEvent_t)(dr_gluediagevent event_id);

typedef qdr_return   (* qdr_cb_createThreadsyncObject)(qdr_threadsync_object objectID,
                                                       unsigned char createLocked);

typedef void         (* qdr_cb_destroyThreadsyncObject)(qdr_threadsync_object objectID);

typedef qdr_return   (* qdr_cb_waitlockThreadsyncObject)(qdr_threadsync_object objectID);

typedef qdr_return   (* qdr_cb_unlockThreadsyncObject)(qdr_threadsync_object objectID);


/** structure for QDR Core callbacks*/
typedef struct _tQdrCallbacks
{
   qdr_cb_getSVState_t        getSVState;
   qdr_cb_getDGPSCorrection_t getDGPScorrection;
   qdr_cb_reportPosition_t    reportPosition_cb;
   qdr_cb_reportNavInitData_t reportNavInitData_cb;
   qdr_cb_reportSvStatus_t    reportSVStatus_cb;
   qdr_cb_sendDIAGData_t      sendDIAGData_cb;
   qdr_cb_storeNVData_t       storeNVData_cb;
   qdr_cb_retrieveNVData_t    retrieveNVData_cb;
   qdr_cb_clearNVData_t       clearNVData_cb;
   qdr_cb_getPPSInfo_t        getPPSInfo_cb;
   qdr_cb_getNavReport_t      getGnssNavReport_cb;
   qdr_cb_getNavReport_t      getPreciseNavReport_cb;
}tQdrCallbacks;

/** structure for Platform IF callbacks*/
typedef struct _tQdrPlatfCallbacks
{
   qdr_cb_debugLog_t                debugLog_cb;
   qdr_getsystime_t                 getTime_cb;
   qdr_log_diagEvent_t              log_diag_event_cb;
   qdr_cb_createThreadsyncObject    createThreadSyncObject_cb;
   qdr_cb_destroyThreadsyncObject   destroyThreadSyncObject_cb;
   qdr_cb_waitlockThreadsyncObject  lockThreadSyncObject_cb;
   qdr_cb_unlockThreadsyncObject    unlockThreadSyncObject_cb;

}tQdrPlatfCallbacks;

/**< NVM Store/Retrieve Data IDs */
#define QDR_NV_FILE_QDR3_DATA    0x0001   /**< Data ID for QDR3 - A6DOF */
#define QDR_NV_FILE_NLCTRL_DATA  0x0002   /**< Data ID for NAV Control */
#define QDR_NV_FILE_NLINIT_DATA  0x0003   /**< Data ID for NAV INIT, AUX INIT & MI_NAV_INIT */
#define QDR_NV_FILE_QDR2_DATA    0x0004   /**< Data ID for QDR2 */

qdr_return qdr_init(tQdrCallbacks *pQdrCallbacks,tQdrPlatfCallbacks *pQdrPlatfCallbacks);
qdr_return qdr_shutdown(void);

#define A6DOF_MAX_SENSORS  9
#define A6DOF_MAX_SENSOR_SETS  11

typedef struct _tQdr_SensorSet
{
   unsigned short    validity;
   unsigned int      time;
   float     data[A6DOF_MAX_SENSORS];
} tQdr_SensorSet;

/**This is a bitmap that describes the validity of the various information
* elements in the sensor data set.*/
#define A6DOF_SENSOR_VALID_TIME_TAG  (0x0001)
#define A6DOF_SENSOR_VALID_DATA0     (0x0002)
#define A6DOF_SENSOR_VALID_DATA1     (0x0004)
#define A6DOF_SENSOR_VALID_DATA2     (0x0008)
#define A6DOF_SENSOR_VALID_DATA3     (0x0010)
#define A6DOF_SENSOR_VALID_DATA4     (0x0020)
#define A6DOF_SENSOR_VALID_DATA5     (0x0040)
#define A6DOF_SENSOR_VALID_DATA6     (0x0080)
#define A6DOF_SENSOR_VALID_DATA7     (0x0100)
#define A6DOF_SENSOR_VALID_DATA8     (0x0200)

/** This bit will be appended in the API call to indicate that the data
 *  was from flashback period i.e. buffered */
#define A6DOF_FLASHBACK_DATA_FLAG    (0x4000)
/** This bit will be appended in the API call to indicate that the data
*corresponds to the GNSS epoch and DR sync pulse */
#define A6DOF_EPOCH_DATA_FLAG        (0x8000)


typedef struct _tQdrSensorDataSet2NAV
{
   unsigned char            type;
   unsigned char            num_sets;
   unsigned short           reserved;
   tQdr_SensorSet DataSet[A6DOF_MAX_SENSOR_SETS];
 } tQdrSensorData2NAV;

typedef struct
{
    size_t         size;
    qdr_return     (*do1HzNav)(void);
    qdr_return     (*init)(tQdrCallbacks *, tQdrPlatfCallbacks *);
    qdr_return     (*shutdown)(void);
    qdr_return     (*getVersionInfo)(tQdrVersion *);
    qdr_return     (*transfer1HzSensorData)(tQdrSensorData2NAV *);
    qdr_return     (*do10HzNav)(unsigned char , tQdr_SensorSet *);
    qdr_return     (*setSystemTime)(qdr_sysTime *);
    qdr_return     (*transferGnssMsmt)(tQdrGnssMeasSet2NAV *);
    qdr_return     (*doNHzNav)(uint8_t meas_avail);
    qdr_return     (*config)(uint8_t set, tQdrConfig *config);
    qdr_return     (*reportExternalError)(qdr_external_error err);
} qdr_GlueCoreInterface;

qdr_GlueCoreInterface* get_qdr_interface(void);
/*******************************************
* Definitions for Sensor Data Types
********************************************/

#define QDR_SDT_UNKNOWN                (0xff)

#define QDR_SDT_ODO_GYRO_REV           (1)
#define QDR_SDT_DIF_PULSES_REV         (2)
#define QDR_SDT_DIF_SPEEDS_REV         (3)
#define QDR_SDT_DIF_ANGLRT_REV         (4)
#define QDR_SDT_ODO_GYRO_NOREV         (5)
#define QDR_SDT_DIF_PULSES_NOREV       (6)
#define QDR_SDT_DIF_SPEEDS_NOREV       (7)
#define QDR_SDT_DIF_ANGLRT_NOREV       (8)
#define QDR_SDT_GYRO_ODO_STEER_A       (9)
#define QDR_SDT_1G_3A_RESERVED         (10)
#define QDR_SDT_GYRO_DIF_PULSES_REV    (11)
#define QDR_SDT_1G_3A                  (12)
#define QDR_SDT_ODO_GYRO_REV_5HZ       (13)
#define QDR_SDT_3G_3A_ODO_REV          (14)
#define QDR_SDT_6DOF_ODO_REV           (15)
#define QDR_SDT_3G_3A_ODO_RS_RESERVED  (16) // reserved
#define QDR_SDT_3G_3A_ODO_DWT_REV      (17) //ODO DWT
#define QDR_SDT_3G_3A_ODO_DWS_REV      (18) //ODO DWS
#define QDR_SDT_3G_3A_ODO_PULSES_REV   (19) //ODO pulses

/**An array of sensor data sets each corresponding to a 100ms period*/

qdr_return qdr_transfer1HzSensorData(tQdrSensorData2NAV *pQdrSensorData);

qdr_return qdr_setSystemTime(qdr_sysTime *time);

qdr_return qdr_transferGnssMsmt(tQdrGnssMeasSet2NAV *pGnssMeasData);

uint8_t qdr_isFlashback();

qdr_return qdr_do1HzNav(void);
qdr_return qdr_do10HzNav(unsigned char SensorDataType,tQdr_SensorSet *pSensorDataSet);
qdr_return qdr_doNHzNav(uint8_t meas_avail);
qdr_return qdr_config(uint8_t set, tQdrConfig *config);
qdr_return qdr_report_external_error(qdr_external_error err);

qdr_return qdr_getVersionInfo(tQdrVersion *);

void NavStoreNVMData(void);
void NavInitData(void);

qdr_return qdr_clearNVData(unsigned int  dataIDToClear);
#define QDR_CLEAR_DR_DATA              0x4000
#define QDR_CLEAR_ALL                  0xFFFF

qdr_return qdr_clearRAMData(unsigned int  dataIDToClear);
#define QDR_CLEAR_EPHEMERIS            0x0001
#define QDR_CLEAR_ALMANAC              0x0002
#define QDR_CLEAR_POSITION             0x0004
#define QDR_CLEAR_TIME                 0x0008
#define QDR_CLEAR_IONO                 0x0010
#define QDR_CLEAR_UTC                  0x0020
#define QDR_CLEAR_HEALTH               0x0040
#define QDR_CLEAR_SVDIR                0x0080
#define QDR_CLEAR_SVSTEER              0x0100
#define QDR_CLEAR_SADATA               0x0200
#define QDR_CLEAR_RTI                  0x0400
#define QDR_CLEAR_CELLDB_INFO          0x8000
#define QDR_CLEAR_DR_DATA              0x4000
#define QDR_CLEAR_ALL                  0xFFFF

#ifdef __cplusplus
}
#endif
#endif /*__QDR_IF__*/
