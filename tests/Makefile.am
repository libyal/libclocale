AM_CPPFLAGS = \
	-I../include -I$(top_srcdir)/include \
	-I../common -I$(top_srcdir)/common \
	@LIBCERROR_CPPFLAGS@ \
	@LIBCLOCALE_DLL_IMPORT@

BUILT_SOURCES = package.m4

check_AUTOTESTS = \
	test_library \
	test_manpages

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

AUTOM4TE = autom4te
AUTOTEST = $(AUTOM4TE) --language=autotest

SUFFIXES = .at

.at:
	$(AM_V_GEN)rm -f $@ $@.tmp; \
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $< && \
	mv $@.tmp $@

atconfig: $(top_builddir)/config.status
	cd $(top_builddir) && $(SHELL) ./config.status tests/$@

check-build: $(check_PROGRAMS)

check-local: $(check_AUTOTESTS)
	@fail=0; \
	for test_suite in $(check_AUTOTESTS); do \
		$(AM_TESTS_ENVIRONMENT) $(SHELL) "./$$test_suite" $(TESTSUITEFLAGS) || fail=1; \
		echo ""; \
	done; \
	exit $$fail

clean-local:
	for test_suite in $(check_AUTOTESTS); do \
		test ! -f "$$test_suite" || $(SHELL) "./$$test_suite" --clean; \
	done

package.m4: $(top_srcdir)/configure.ac
	$(AM_V_GEN):; \
	{ \
	  echo 'm4_define([AT_PACKAGE_NAME], [$(PACKAGE_NAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [$(PACKAGE_TARNAME)])' ; \
	  echo 'm4_define([AT_PACKAGE_VERSION], [$(PACKAGE_VERSION)])' ; \
	  echo 'm4_define([AT_PACKAGE_STRING], [$(PACKAGE_STRING)])' ; \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [$(PACKAGE_BUGREPORT)])' ; \
	} > $@

test_library: \
	package.m4 \
	test_library.at \
	test_macros.at

test_manpages: \
	package.m4 \
	test_manpages.at

EXTRA_DIST = \
	$(check_AUTOTESTS:=.at) \
	package.m4 \
	test_macros.at

CLEANFILES = \
	$(check_AUTOTESTS) \
	*.exe \
	*.tmp

DISTCLEANFILES = \
	*.log \
	atconfig \
	Makefile \
	Makefile.in

