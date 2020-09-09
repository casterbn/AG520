/*
 * Copyright (c) 2019 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
*/

/*
 * 2014, 2016 Qualcomm Atheros, Inc.
 * All Rights Reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 */

#if !defined(_ART_UTF_COMMON_H)
#define _ART_UTF_COMMON_H

#define __ATTRIB_PACK           __attribute__ ((packed))
#define __ATTRIB_PRINTF         __attribute__ ((format (printf, 1, 2)))
#define __ATTRIB_NORETURN       __attribute__ ((noreturn))

#ifndef INLINE
#define INLINE                  __inline__
#endif

#define MPATTERN                (10*4)
#define RATE_POWER_MAX_INDEX    8
#define RATE_MASK_ROW_MAX       9

#define PSAT_WHAL_NUM_11G_CAL_PIERS_MAX 3
#define PSAT_WHAL_NUM_11A_CAL_PIERS_MAX 8

#define AR6320_EEPROM_BOARDFLAGSEXT_OFFSET            28
#define AR6320_EEPROM_BOARDFLAGSEXT_LENGTH            4
#define WHAL_BOARD_SCPC_IS_DONE                       0x00000004
#define AR6320_EEPROM_PSATPWR2G_OFFSET                0x9A4
#define AR6320_EEPROM_PSATPWR2G_LENGTH                0x1
#define AR6320_EEPROM_2G_SCPC_CAL_DATA_OFFSET         0x280
#define AR6320_EEPROM_2G_SCPC_CAL_DATA_LENGTH         0x17A
#define AR6320_EEPROM_5G_SCPC_CAL_DATA_OFFSET         0xAE8
#define AR6320_EEPROM_5G_SCPC_CAL_DATA_LENGTH         0x360
#define AR6320_EEPROM_CHECKSUM_OFFSET                 0x2
#define AR6320_EEPROM_CHECKSUM_LENGTH                 0x2
#define AR6320_EEPROM_STRUCT_LENGTH                   8124

typedef enum {
    ZEROES_PATTERN = 0,
    ONES_PATTERN,
    REPEATING_10,
    PN7_PATTERN,
    PN9_PATTERN,
    PN15_PATTERN,
    USER_DEFINED_PATTERN
}TX_DATA_PATTERN;

typedef enum {
    TCMD_CONT_TX_OFF = 0,
    TCMD_CONT_TX_SINE,
    TCMD_CONT_TX_FRAME,
    TCMD_CONT_TX_TX99,
    TCMD_CONT_TX_TX100,
    TCMD_CONT_TX_OFFSETTONE,
    TCMD_CONT_TX_PSAT_CAL,
    TCMD_CONT_TX_CWTONE,
    TCMD_CONT_TX_CLPCPKT,
} TCMD_CONT_TX_MODE;

typedef enum {
    TCMD_WLAN_MODE_NOHT = 0,
    TCMD_WLAN_MODE_HT20 = 1,
    TCMD_WLAN_MODE_HT40PLUS = 2,
    TCMD_WLAN_MODE_HT40MINUS = 3,
    TCMD_WLAN_MODE_CCK = 4,
//#ifdef SUPPORT_VHT
    TCMD_WLAN_MODE_VHT20 = 5,
    TCMD_WLAN_MODE_VHT40PLUS = 6,
    TCMD_WLAN_MODE_VHT40MINUS = 7,
    TCMD_WLAN_MODE_VHT80_0 = 8,
    TCMD_WLAN_MODE_VHT80_1 = 9,
    TCMD_WLAN_MODE_VHT80_2 = 10,
    TCMD_WLAN_MODE_VHT80_3 = 11,
//#endif
    TCMD_WLAN_MODE_VHT80P80 = 12,
    TCMD_WLAN_MODE_VHT160 = 13,

    TCMD_WLAN_MODE_VHT80P80_0 = 21,
    TCMD_WLAN_MODE_VHT80P80_1 = 22,
    TCMD_WLAN_MODE_VHT80P80_2 = 23,
    TCMD_WLAN_MODE_VHT80P80_3 = 24,
    TCMD_WLAN_MODE_VHT80P80_4 = 25,
    TCMD_WLAN_MODE_VHT80P80_5 = 26,
    TCMD_WLAN_MODE_VHT80P80_6 = 27,
    TCMD_WLAN_MODE_VHT80P80_7 = 28,

    TCMD_WLAN_MODE_VHT160_0 = 29,
    TCMD_WLAN_MODE_VHT160_1 = 30,
    TCMD_WLAN_MODE_VHT160_2 = 31,
    TCMD_WLAN_MODE_VHT160_3 = 32,
    TCMD_WLAN_MODE_VHT160_4 = 33,
    TCMD_WLAN_MODE_VHT160_5 = 34,
    TCMD_WLAN_MODE_VHT160_6 = 35,
    TCMD_WLAN_MODE_VHT160_7 = 36,

    TCMD_WLAN_MODE_VHT165_0 = 37,
    TCMD_WLAN_MODE_VHT165_1 = 38,
    TCMD_WLAN_MODE_VHT165_2 = 39,
    TCMD_WLAN_MODE_VHT165_3 = 40,
    TCMD_WLAN_MODE_VHT165_4 = 41,
    TCMD_WLAN_MODE_VHT165_5 = 42,
    TCMD_WLAN_MODE_VHT165_6 = 43,
    TCMD_WLAN_MODE_VHT165_7 = 44,

    TCMD_WLAN_MODE_HALF_RATE = 50,
    TCMD_WLAN_MODE_QUARTER_RATE = 51,

    TCMD_WLAN_MODE_MAX,
    TCMD_WLAN_MODE_INVALID = TCMD_WLAN_MODE_MAX,

} TCMD_WLAN_MODE;

typedef enum {
    TCMD_CONT_RX_PROMIS =0,
    TCMD_CONT_RX_FILTER,
    TCMD_CONT_RX_REPORT,
    TCMD_CONT_RX_SETMAC,
    TCMD_CONT_RX_SET_ANT_SWITCH_TABLE,

    TC_CMD_RESP,
	TCMD_CONT_RX_GETMAC,
} TCMD_CONT_RX_ACT;

typedef enum {
    PHY_RF_MODE_NON_DBS_PHY0 = 0,
    PHY_RF_MODE_DBS_PHY0_PHY1,
    PHY_RF_MODE_SBS_PHY0_PHY1,
    PHY_RF_MODE_NON_DBS_PHY1,
} PHY_RF_MODE;

typedef enum {
    TCMD_RATEBW_CW = -1,
    TCMD_RATEBW_CCK = 0,
    TCMD_RATEBW_LEGACY_OFDM,
    TCMD_RATEBW_HT20,
    TCMD_RATEBW_HT40,
    TCMD_RATEBW_VHT20,
    TCMD_RATEBW_VHT40,
    TCMD_RATEBW_VHT80,
    TCMD_RATEBW_VHT80P80,
    TCMD_RATEBW_HE20,
    TCMD_RATEBW_HE40,
    TCMD_RATEBW_HE80,
    TCMD_RATEBW_HE80P80,
    TCMD_RATEBW_OFDMA_HE20,
    TCMD_RATEBW_OFDMA_HE40,
    TCMD_RATEBW_OFDMA_HE80,
    TCMD_RATEBW_OFDMA_HE80P80,
    TCMD_RATEBW_HE160,
    TCMD_RATEBW_OFDMA_HE160,
    TCMD_RATEBW_HE165,
    TCMD_RATEBW_OFDMA_HE165,
    TCMD_RATEBW_VHT160,
    TCMD_RATEBW_VHT165,
    TCMD_RATEBW_INVALID
} TCMD_RATEBW;

typedef enum {
    TCMD_GI_0 = 0,
    TCMD_GI_LTF_MODE0_GI_400 = 1,
    TCMD_GI_LTF_MODE0_GI_800,
    TCMD_GI_LTF_MODE0_GI_1600,
    TCMD_GI_LTF_MODE0_GI_3200,
    TCMD_GI_LTF_MODE1_GI_400 = 17,
    TCMD_GI_LTF_MODE1_GI_800,
    TCMD_GI_LTF_MODE1_GI_1600,
    TCMD_GI_LTF_MODE1_GI_3200,
    TCMD_GI_LTF_MODE2_GI_400 = 33,
    TCMD_GI_LTF_MODE2_GI_800,
    TCMD_GI_LTF_MODE2_GI_1600,
    TCMD_GI_LTF_MODE2_GI_3200,
    TCMD_GI_LTF_MODE4_GI_400 = 49,
    TCMD_GI_LTF_MODE4_GI_800,
    TCMD_GI_LTF_MODE4_GI_1600,
    TCMD_GI_LTF_MODE4_GI_3200,
} TCMD_GI;

typedef enum {
    TCMD_PPDU_SINGLEUSER = 0,
    TCMD_PPDU_MULTIPLEUSERS,
    TCMD_PPDU_EXTRANGESINGLEUSER,
    TCMD_PPDU_TRIGGER,
    TCMD_PPDU_INVALID
} TCMD_PPDU_TYPE;

typedef enum {
    TCMD_DIR_UP = 0,
    TCMD_DIR_DOWN,
    TCMD_DIR_DIRECT,
    TCMD_DIR_INVALID
} TCMD_LINK_DIR;
#endif //#if !defined(_ART_UTF_COMMON_H)
