
#pragma once
typedef blkcnt_t;	//Used for file block counts
typedef blksize_t;	//Used for block sizes
typedef clock_t;	//Used for system times in clock ticks or CLOCKS_PER_SEC(see <time.h>).
typedef clockid_t;	//Used for clock ID type in the clock and timer functions.
typedef dev_t;	//Used for device IDs.
typedef fsblkcnt_t;	//Used for file system block counts
typedef fsfilcnt_t;	//Used for file system file counts
typedef gid_t;	//Used for group IDs.
typedef id_t;	//Used as a general identifier; can be used to contain at least a pid_t, uid_t or a gid_t.
typedef ino_t;	//Used for file serial numbers.
typedef key_t;	//Used for interprocess communication.
typedef mode_t;	//Used for some file attributes.
typedef nlink_t;	//Used for link counts.
typedef off_t;	//Used for file sizes.
typedef pid_t;	//Used for process IDs and process group IDs.
typedef pthread_attr_t;	//Used to identify a thread attribute object.
typedef pthread_cond_t;	//Used for condition variables.
typedef pthread_condattr_t;	//Used to identify a condition attribute object.
typedef pthread_key_t;	//Used for thread - specific data keys.
typedef pthread_mutex_t;	//Used for mutexes.
typedef pthread_mutexattr_t;	//Used to identify a mutex attribute object.
typedef pthread_once_t;	//Used for dynamic package initialisation.
typedef pthread_rwlock_t;	//Used for read - write locks.
typedef pthread_rwlockattr_t;	//Used for read - write lock attributes.
typedef unsigned pthread_t;	//Used to identify a thread.
typedef unsigned long size_t;	//Used for sizes of objects.
typedef unsigned long long ssize_t;	//Used for a count of bytes or an error indication.
typedef unsigned suseconds_t;	//Used for time in microseconds
typedef unsinged long long time_t;	//Used for time in seconds.
typedef unsigned long long timer_t;	//Used for timer ID returned by timer_create().
typedef uid_t;	//Used for user IDs.
typedef useconds_t;	//Used for time in microseconds.