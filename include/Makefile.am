include_HEADERS = \
	libclocale.h

pkginclude_HEADERS = \
	libclocale/definitions.h \
	libclocale/error.h \
	libclocale/extern.h \
	libclocale/features.h \
	libclocale/types.h

EXTRA_DIST = \
	libclocale.h.in \
	libclocale/definitions.h.in \
	libclocale/features.h.in \
	libclocale/types.h.in

MAINTAINERCLEANFILES = \
	Makefile.in

distclean: clean
	-rm -f libclocale.h
	-rm -f libclocale/definitions.h
	-rm -f libclocale/features.h
	-rm -f libclocale/types.h
	-rm -f Makefile

