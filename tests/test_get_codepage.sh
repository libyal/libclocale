#!/bin/bash
# Library get codepage testing script
#
# Version: 20160327

EXIT_SUCCESS=0;
EXIT_FAILURE=1;
EXIT_IGNORE=77;

TEST_PREFIX=`dirname ${PWD}`;
TEST_PREFIX=`basename ${TEST_PREFIX} | sed 's/^lib\([^-]*\)/\1/'`;

TEST_PROFILE="lib${TEST_PREFIX}";
TEST_DESCRIPTION="get codepage";
OPTION_SETS="";

TEST_TOOL_DIRECTORY=".";
TEST_TOOL="${TEST_PREFIX}_test_get_codepage";

test_get_codepage()
{
	local TEST_EXECUTABLE=$1;

	echo -n -e "Testing retrieving codepage\t"

	run_test_with_arguments ${TEST_EXECUTABLE};
	local RESULT=$?;

	if test ${RESULT} -ne 0;
	then
		echo "(FAIL)";
	else
		echo "(PASS)";
	fi
	return ${RESULT};
}

if ! test -z ${SKIP_LIBRARY_TESTS};
then
	exit ${EXIT_IGNORE};
fi

TEST_EXECUTABLE="${TEST_TOOL_DIRECTORY}/${TEST_TOOL}";

if ! test -x "${TEST_EXECUTABLE}";
then
	TEST_EXECUTABLE="${TEST_TOOL_DIRECTORY}/${TEST_TOOL}.exe";
fi

if ! test -x "${TEST_EXECUTABLE}";
then
	echo "Missing test executable: ${TEST_EXECUTABLE}";

	exit ${EXIT_FAILURE};
fi

TEST_RUNNER="tests/test_runner.sh";

if ! test -f "${TEST_RUNNER}";
then
	TEST_RUNNER="./test_runner.sh";
fi

if ! test -f "${TEST_RUNNER}";
then
	echo "Missing test runner: ${TEST_RUNNER}";

	exit ${EXIT_FAILURE};
fi

source ${TEST_RUNNER};

test_get_codepage "${TEST_EXECUTABLE}";
RESULT=$?;

exit ${RESULT};

