#!/bin/sh
# Script to run tests
#
# Version: 20260609

if test -f ${PWD}/libclocale/.libs/libclocale.1.dylib && test -f ./pyclocale/.libs/pyclocale.so
then
	install_name_tool -change /usr/local/lib/libclocale.1.dylib ${PWD}/libclocale/.libs/libclocale.1.dylib ./pyclocale/.libs/pyclocale.so
fi

make check-build > /dev/null

make check $@
RESULT=$?

if test ${RESULT} -ne 0
then
	find . -name \*.log -path \*.dir/\*/\*.log -print -exec cat {} \;
fi
exit ${RESULT}

