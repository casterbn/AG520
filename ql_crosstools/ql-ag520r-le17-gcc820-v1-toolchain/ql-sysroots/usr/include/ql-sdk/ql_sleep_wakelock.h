#ifndef __QL_SLEEP_WAKELOCK_H__
#define __QL_SLEEP_WAKELOCK_H__

/*
 * create wakelock, return the file description of the wakelock
 */
extern int ql_slp_wakelock_create(const char *name, size_t len);

/*
 * lock the wakelock by the file description of the wakelock
 */
extern int ql_slp_wakelock_lock(int fd);


/*
 * unlock the wakelock by the file description of the wakelock
 */
extern int ql_slp_wakelock_unlock(int fd);

/*
 * destroy the wakelock by the file description of the wakelock
 */
extern int ql_slp_wakelock_destroy(int fd);

/*
 * Enable/Disable autosleep function
 */
extern int ql_autosleep_enable(char enable);

#endif  //__QL_SLEEP_WAKELOCK_H__

