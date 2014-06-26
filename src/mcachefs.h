#ifndef __FUSE_MCACHEFS_H
#define __FUSE_MCACHEFS_H

#define __MCACHEFS_VERSION__ "0.5.30"

#define FUSE_USE_VERSION 29
#define _BSD_SOURCE
#ifdef linux
/* For pread()/pwrite() */
#define _XOPEN_SOURCE 600
#define _ATFILE_SOURCE
#define __USE_GNU
#endif

#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/statfs.h>
#include <sys/mman.h>
#include <sys/file.h>
#include <sys/statvfs.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <linux/limits.h>

#include <sys/timeb.h>
#include <sys/time.h>
#include <time.h>

#define FUNCTIONCALL 1

#define PARANOID 0

/**
 * States of the backing mechanism
 */
#define MCACHEFS_STATE_NORMAL   0
#define MCACHEFS_STATE_FULL     1
#define MCACHEFS_STATE_HANDSUP  2
#define MCACHEFS_STATE_NOCACHE  3
#define MCACHEFS_STATE_QUITTING 4

/**
 * States of the writing mechanism
 */
#define MCACHEFS_WRSTATE_CACHE 0
#define MCACHEFS_WRSTATE_FLUSH 1
#define MCACHEFS_WRSTATE_FORCE 2

/**
 * Fuse File Handlers, provided by mcachefs at open() and used in read(), write() and release()
 */
typedef unsigned long long mcachefs_fh_t;
typedef unsigned long long mcachefs_metadata_id;

#include "mcachefs-config.h"
#include "mcachefs-mutex.h"
#include "mcachefs-file.h"
#include "mcachefs-metadata.h"
#include "mcachefs-journal.h"
#include "mcachefs-util.h"
#include "mcachefs-transfer.h"
#include "mcachefs-vops.h"
#include "mcachefs-log.h"
#include "mcachefs-io.h"

extern struct fuse_operations mcachefs_oper;

extern struct stat mcachefs_target_stat;

#endif // __FUSE_MCACHEFS_H
