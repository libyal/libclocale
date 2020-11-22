#!/bin/sh
# Script to run tests
#
# Version: 20201121

if test -f ${PWD}/libclocale/.libs/libclocale.1.dylib && test -f ./pyclocale/.libs/pyclocale.so;
then
	install_name_tool -change /usr/local/lib/libclocale.1.dylib ${PWD}/libclocale/.libs/libclocale.1.dylib ./pyclocale/.libs/pyclocale.so;
fi

make check CHECK_WITH_STDERR=1;
RESULT=$?;

if test ${RESULT} -ne 0 && test -f tests/test-suite.log;
then
	cat tests/test-suite.log;
fi
exit ${RESULT};

