AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCLOCALE_DLL_IMPORT@

TESTS = \
	test_api_functions.sh

check_SCRIPTS = \
	test_api_functions.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	clocale_test_codepage \
	clocale_test_locale \
	clocale_test_support

clocale_test_codepage_SOURCES = \
	clocale_test_codepage.c \
	clocale_test_libcerror.h \
	clocale_test_libclocale.h \
	clocale_test_macros.h \
	clocale_test_unused.h

clocale_test_codepage_LDADD = \
	../libclocale/libclocale.la \
	@LIBCERROR_LIBADD@

clocale_test_locale_SOURCES = \
	clocale_test_libcerror.h \
	clocale_test_libclocale.h \
	clocale_test_locale.c \
	clocale_test_macros.h \
	clocale_test_unused.h

clocale_test_locale_LDADD = \
	../libclocale/libclocale.la \
	@LIBCERROR_LIBADD@

clocale_test_support_SOURCES = \
	clocale_test_libcerror.h \
	clocale_test_libclocale.h \
	clocale_test_macros.h \
	clocale_test_support.c \
	clocale_test_unused.h

clocale_test_support_LDADD = \
	../libclocale/libclocale.la \
	@LIBCERROR_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

