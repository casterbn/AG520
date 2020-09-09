#ifndef __QTEE_EFUSE_H
#define __QTEE_EFUSE_H

#include <inttypes.h>

typedef enum {
    QTEE_EFUSE_ADDR_RAW = 0,
    QTEE_EFUSE_ADDR_FEC = 1,
    QTEE_EFUSE_ADDR_MAX,
}QTEE_EFUSE_ADDR_TYPE;


int qtee_read_efuse(uint32_t index, uint32_t row_data[2], uint32_t index_type, uint32_t *status);
int qtee_write_efuse(uint32_t index, uint32_t row_data[2], uint32_t *status);

#endif
