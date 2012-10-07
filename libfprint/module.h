/*
 * Support for dynamically loading drivers
 * Copyright (C) 2012 Kunal Gangakhedkar <kunal.gangakhedkar@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __FPRINT_MODULE_H__
#define __FPRINT_MODULE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/param.h>
#include <config.h>

#define MODULE_PATH_LEN		MAXPATHLEN
#define MODULE_NAME_LEN		MODULE_PATH_LEN

typedef int (*initcall_t)(void);
typedef void (*exitcall_t)(void);

struct fp_mod {
	char name[MODULE_NAME_LEN];
	char path[MODULE_PATH_LEN];
	initcall_t init;
	exitcall_t exit;
	void *handle;
};

#define module_init(initfn)			\
	API_EXPORTED int init_mod(void) __attribute__((alias(#initfn)));

#define module_exit(exitfn)			\
	API_EXPORTED int cleanup_mod(void) __attribute__((alias(#exitfn)));

int load_module(const char *modpath);
int unload_module(const char *modpath);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __FPRINT_MODULE_H__ */
