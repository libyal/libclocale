MSVSCPP_FILES = \
	clocale_test_get_codepage/clocale_test_get_codepage.vcproj \
	clocale_test_get_decimal_point/clocale_test_get_decimal_point.vcproj \
	clocale_test_get_version/clocale_test_get_version.vcproj \
	libcerror/libcerror.vcproj \
	libclocale/libclocale.vcproj \
	libcstring/libcstring.vcproj \
	libclocale.sln

SCRIPT_FILES = \
	scripts/vs2008_x64.sh \
	scripts/vs2008_x64_sln.sed \
	scripts/vs2008_x64_vcproj.sed \
	scripts/vs2010_x64.sh \
	scripts/vs2010_x64_sln.sed \
	scripts/vs2010_x64_vcxproj.sed

EXTRA_DIST = \
	$(MSVSCPP_FILES) \
	$(SCRIPT_FILES)

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	/bin/rm -f Makefile

