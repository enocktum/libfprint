DRIVER_CFLAGS = -fvisibility=hidden -fPIC -DPIC -I../ -I$(top_srcdir)/nbis/include $(LIBUSB_CFLAGS) $(GLIB_CFLAGS) $(CRYPTO_CFLAGS) $(AM_CLFAGS)
DRIVER_LDFLAGS = -module -version-info @lt_major@:@lt_revision@:@lt_age@ -shared

DRIVER_LIBADD = -lm $(GLIB_LIBS) $(CRYPTO_LIBS) ../libfprint.la

driver_LTLIBRARIES = 
driverdir=$(pkglibdir)/drivers

drv_upeke2_la_CFLAGS = $(DRIVER_CFLAGS)
drv_upeke2_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_upeke2_la_LIBADD = $(DRIVER_LIBADD)
drv_upeke2_la_SOURCES = upeke2.c

# drv_upektc_la_CFLAGS = $(DRIVER_CFLAGS)
# drv_upektc_la_LDFLAGS = $(DRIVER_LDFLAGS)
# drv_upektc_la_LIBADD = $(DRIVER_LIBADD)
# drv_upektc_la_SOURCES = upektc.c

drv_upekts_la_CFLAGS = $(DRIVER_CFLAGS)
drv_upekts_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_upekts_la_LIBADD = $(DRIVER_LIBADD)
drv_upekts_la_SOURCES = upekts.c

drv_upeksonly_la_CFLAGS = $(DRIVER_CFLAGS)
drv_upeksonly_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_upeksonly_la_LIBADD = $(DRIVER_LIBADD)
drv_upeksonly_la_SOURCES = upeksonly.c

drv_vcom5s_la_CFLAGS = $(DRIVER_CFLAGS)
drv_vcom5s_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_vcom5s_la_LIBADD = $(DRIVER_LIBADD)
drv_vcom5s_la_SOURCES = vcom5s.c

drv_uru4000_la_CFLAGS = $(DRIVER_CFLAGS)
drv_uru4000_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_uru4000_la_LIBADD = $(DRIVER_LIBADD)
drv_uru4000_la_SOURCES = uru4000.c

drv_fdu2000_la_CFLAGS = $(DRIVER_CFLAGS)
drv_fdu2000_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_fdu2000_la_LIBADD = $(DRIVER_LIBADD)
drv_fdu2000_la_SOURCES = fdu2000.c

drv_aes1610_la_CFLAGS = $(DRIVER_CFLAGS)
drv_aes1610_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_aes1610_la_LIBADD = $(DRIVER_LIBADD)
drv_aes1610_la_SOURCES = aes1610.c

drv_aes2501_la_CFLAGS = $(DRIVER_CFLAGS)
drv_aes2501_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_aes2501_la_LIBADD = $(DRIVER_LIBADD)
drv_aes2501_la_SOURCES = aes2501.c

drv_aes4000_la_CFLAGS = $(DRIVER_CFLAGS)
drv_aes4000_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_aes4000_la_LIBADD = $(DRIVER_LIBADD)
drv_aes4000_la_SOURCES = aes4000.c

drv_vfs101_la_CFLAGS = $(DRIVER_CFLAGS)
drv_vfs101_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_vfs101_la_LIBADD = $(DRIVER_LIBADD)
drv_vfs101_la_SOURCES = vfs101.c

drv_vfs301_la_CFLAGS = $(DRIVER_CFLAGS)
drv_vfs301_la_LDFLAGS = $(DRIVER_LDFLAGS)
drv_vfs301_la_LIBADD = $(DRIVER_LIBADD)
drv_vfs301_la_SOURCES = vfs301.c vfs301_proto.c

if ENABLE_DYNAMIC_DRIVERS

if ENABLE_UPEKE2
driver_LTLIBRARIES += drv_upeke2.la
endif # ENABLE_UPEKE2

if ENABLE_UPEKTS
driver_LTLIBRARIES += drv_upekts.la
endif # ENABLE_UPEKTS

# if ENABLE_UPEKTC
# driver_LTLIBRARIES += drv_upektc.la
# endif # ENABLE_UPEKTC

if ENABLE_UPEKSONLY
driver_LTLIBRARIES += drv_upeksonly.la
endif # ENABLE_UPEKSONLY

if ENABLE_VCOM5S
driver_LTLIBRARIES += drv_vcom5s.la
endif # ENABLE_VCOM5S

if ENABLE_URU4000
driver_LTLIBRARIES += drv_uru4000.la
endif # ENABLE_URU4000

if ENABLE_FDU2000
driver_LTLIBRARIES += drv_fdu2000.la
endif # ENABLE_FDU2000

if ENABLE_AES1610
driver_LTLIBRARIES += drv_aes1610.la
endif # ENABLE_AES1610

if ENABLE_AES2501
driver_LTLIBRARIES += drv_aes2501.la
endif # ENABLE_AES2501

if ENABLE_AES4000
driver_LTLIBRARIES += drv_aes4000.la
endif # ENABLE_AES4000

if ENABLE_VFS101
driver_LTLIBRARIES += drv_vfs101.la
endif # ENABLE_VFS101

if ENABLE_VFS301
driver_LTLIBRARIES += drv_vfs301.la
endif # ENABLE_VFS301

endif # ENABLE_DYNAMIC_DRIVERS
