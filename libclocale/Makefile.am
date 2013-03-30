AM_CPPFLAGS = \
	-DLOCALEDIR=\"$(datadir)/locale\" \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@

lib_LTLIBRARIES = libclocale.la

libclocale_la_SOURCES = \
	libclocale.c \
	libclocale_codepage.c libclocale_codepage.h \
	libclocale_definitions.h \
	libclocale_extern.h \
	libclocale_libcerror.h \
	libclocale_libcstring.h \
	libclocale_locale.c libclocale_locale.h \
	libclocale_support.c libclocale_support.h \
	libclocale_unused.h

libclocale_la_LIBADD  = \
	@LIBCSTRING_LIBADD@ \
	@LIBCERROR_LIBADD@

libclocale_la_LDFLAGS = -no-undefined -version-info 1:0:0

EXTRA_DIST = \
	libclocale_definitions.h.in \
	libclocale.rc \
	libclocale.rc.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f libclocale_definitions.h
	/bin/rm -f libclocale.rc
	/bin/rm -f Makefile

splint:
	@echo "Running splint on libclocale ..."
	-splint -preproc -redef $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) $(libclocale_la_SOURCES)

