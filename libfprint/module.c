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

#include <errno.h>
#include <string.h>
#include <dlfcn.h>

#include <glib.h>
#include <config.h>
#include <fp_internal.h>

#include "module.h"

static GSList *modules = NULL;

static int module_exists(const char *mod_path, GSList **entry);

API_EXPORTED int load_module(const char *mod_path)
{
	int rc = 0;
	initcall_t init_call = NULL;
	exitcall_t exit_call = NULL;
	struct fp_mod *mod = NULL;
	void *handle = NULL;

	if (module_exists(mod_path, NULL)) {
		fp_info("Module '%s' already loaded - skipping..\n", mod_path);
		return rc;
	}

	handle = dlopen(mod_path, RTLD_LAZY);
	if (!handle) {
		fp_err("failed to load module %s\n", dlerror());
		return errno;
	}

	init_call = (initcall_t)dlsym(handle, "init_mod");
	if (!init_call) {
		fp_err("failed to get init call pointer: %s\n", dlerror());
		rc = errno;
		goto close_lib;
	}

	exit_call = (exitcall_t)dlsym(handle, "cleanup_mod");

	mod = g_malloc0(sizeof(*mod));
	mod->init = init_call;
	mod->exit = exit_call;
	mod->handle = handle;
	strncpy(mod->path, mod_path, MODULE_PATH_LEN);

	/*
	 * TODO:
	 * For now, copy the file path into name.
	 * When we add support for MODULE_NAME(), we need to change this
	 * to copy the actual module name.
	 */
	strncpy(mod->name, mod_path, MODULE_NAME_LEN);

	rc = init_call();
	if (rc < 0) {
		/* Init routine failed. Abort loading of module.. */
		fp_warn("module '%s' returned %d - aborting loading", mod->name, rc);
		g_free(mod);
	} else {
		modules = g_slist_prepend(modules, (gpointer) mod);
	}
	goto out;

close_lib:
	dlclose(handle);
out:
	return rc;
}

API_EXPORTED int unload_module(const char *mod_path)
{
	GSList *entry = NULL;
	struct fp_mod *mod = NULL;
	int rc = 0;

	if (!module_exists(mod_path, &entry)) {
		fp_err("Module '%s' not found. Perhaps not loaded?\n", mod_path);
		return -ENOENT;
	}

	mod = (struct fp_mod*)entry->data;

	modules = g_slist_delete_link(modules, entry);

	if (mod->exit) {
		mod->exit();
	}

	rc = dlclose(mod->handle);
	if (rc < 0) {
		/*
		 * This is a potential memory leak.
		 * The loaded library is dangling here.
		 * Hopefully, sensible OS will clean it out when the main process
		 * terminates.
		 */
		fp_dbg("Failed to unload module '%s': %s\n", mod->name, dlerror());
	}

	if (entry)
		entry = NULL;

	g_free(mod);
	mod = NULL;

	return rc;
}

static int module_exists(const char *mod_path, GSList **entry)
{
	GSList *elem = modules;

	if (g_slist_length(elem) == 0)
		return 0;

	do {
		struct fp_mod *mod = (struct fp_mod*)elem->data;
		if (strncmp(mod->path, mod_path, MODULE_PATH_LEN) == 0) {
			if (entry)
				*entry = elem;
			return 1;
		}
	} while ((elem = g_slist_next(elem)));

	return 0;
}
