#ifndef __QL_MCLI_H__ 
#define __QL_MCLI_H__ 
#include <stdint.h>
#include "mcm_common_v01.h"
#include "common_v01.h"

#ifdef __cplusplus
extern "C" {
#endif

qmi_client_type ql_mcli_ril_init(qmi_client_ind_cb ind_cb);
qmi_client_type ql_mcli_data_init(qmi_client_ind_cb ind_cb);
qmi_client_type ql_mcli_sim_init(qmi_client_ind_cb ind_cb);
qmi_client_type ql_mcli_atcop_init(qmi_client_ind_cb ind_cb);
qmi_client_type ql_mcli_loc_init(qmi_client_ind_cb ind_cb);
int ql_mcli_release(qmi_client_type handle);

int mcli_qmi_err_to_mcm( qmi_client_error_type client_err);

int ql_mcli_send_sync_ex(qmi_client_type handle, uint32_t msg_id, void *req, int req_len, 
        void *resp, int resp_len, int timeout_msecs);

int ql_mcli_send_async(qmi_client_type handle, int msg_id, void *req, int req_len, void *resp, 
        int resp_len, qmi_client_recv_msg_async_cb resp_cb, void *resp_data, void *p_token);

#ifdef __cplusplus
}
#endif

#endif // MCM_CLIENT_H
