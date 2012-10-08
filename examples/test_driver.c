#include <stdio.h>

#include "libfprint/module.h"

int main(int argc, char** argv)
{
	int rc = 0;
	rc = load_module("drv_vfs101.so");
	if (rc < 0)
		goto out;

	rc = load_module("drv_uru4000.so");
	if (rc < 0)
		goto out;

	rc = load_module("drv_nonexistent.so");

	if (argc > 1) {
		rc = load_module(argv[1]);
	}

	// Try unloading a module.
	rc = unload_module("drv_vfs101.so");

	// try unloading a non-existent module..
	rc = unload_module("drv_nonexistent.so");

	// Try unloading another module.
	rc = unload_module("drv_uru4000.so");
out:
	return rc;
}
