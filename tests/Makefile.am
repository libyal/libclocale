AM_CPPFLAGS = \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/common \
	@LIBCSTRING_CPPFLAGS@ \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCLOCALE_DLL_IMPORT@

TESTS = \
	test_get_codepage.sh

check_SCRIPTS = \
	test_get_codepage.sh \
	test_runner.sh

EXTRA_DIST = \
	$(check_SCRIPTS)

check_PROGRAMS = \
	clocale_test_get_codepage

clocale_test_get_codepage_SOURCES = \
	clocale_test_libcerror.h \
	clocale_test_libclocale.h \
	clocale_test_libcstring.h \
	clocale_test_get_codepage.c

clocale_test_get_codepage_LDADD = \
	../libclocale/libclocale.la \
	@LIBCERROR_LIBADD@ \
	@LIBCSTRING_LIBADD@

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

