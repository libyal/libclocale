AM_CPPFLAGS = \
	-DLOCALEDIR=\"$(datadir)/locale\" \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCLOCALE_DLL_EXPORT@

lib_LTLIBRARIES = libclocale.la

libclocale_la_SOURCES = \
	libclocale.c \
	libclocale_codepage.c libclocale_codepage.h \
	libclocale_definitions.h \
	libclocale_extern.h \
	libclocale_libcerror.h \
	libclocale_locale.c libclocale_locale.h \
	libclocale_support.c libclocale_support.h \
	libclocale_unused.h \
	libclocale_wide_string.c libclocale_wide_string.h

libclocale_la_LIBADD = \
	@LIBCERROR_LIBADD@

libclocale_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libclocale_definitions.h.in \
	libclocale.rc \
	libclocale.rc.in

DISTCLEANFILES = \
	libclocale_definitions.h \
	libclocale.rc \
	Makefile \
	Makefile.in

sources-local: $(BUILT_SOURCES)

splint-local:
	@echo "Running splint on libclocale ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libclocale_la_SOURCES)

