#ifndef _SM64_PLATFORM_H_
#define _SM64_PLATFORM_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* Platform-specific functions and whatnot */

#ifdef __ANDROID__
#define ANDROID_APPNAME "com.owokitty.sm64excoop"
#endif

#define SYS_MAX_PATH 4096 // FIXME: define this on different platforms

// NULL terminated list of platform specific read-only data paths
extern const char *sys_ropaths[];

// crossplatform impls of misc stuff
char *sys_strdup(const char *src);
char *sys_strlwr(char *src);
int sys_strcasecmp(const char *s1, const char *s2);

// path stuff
#ifdef __ANDROID__
const char* get_gamedir(void);
#endif
const char *sys_user_path(void);
const char *sys_exe_path(void);
const char *sys_file_extension(const char *fpath);
const char *sys_file_name(const char *fpath);

// shows an error message in some way and terminates the game
void sys_fatal(const char *fmt, ...) __attribute__ ((noreturn));

#endif // _SM64_PLATFORM_H_
