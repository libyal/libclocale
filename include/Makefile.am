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
	/bin/rm -f libclocale.h
	/bin/rm -f libclocale/definitions.h
	/bin/rm -f libclocale/features.h
	/bin/rm -f libclocale/types.h
	/bin/rm -f Makefile

