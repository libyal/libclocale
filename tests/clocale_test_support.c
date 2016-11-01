/*
 * Library support functions test program
 *
 * Copyright (C) 2010-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "clocale_test_libcerror.h"
#include "clocale_test_libclocale.h"
#include "clocale_test_libcstring.h"
#include "clocale_test_macros.h"
#include "clocale_test_unused.h"

/* Tests the libclocale_get_version function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_get_version(
     void )
{
	const char *version_string = NULL;
	int result                 = 0;

	version_string = libclocale_get_version();

	result = libcstring_narrow_string_compare(
	          version_string,
	          LIBCLOCALE_VERSION_STRING,
	          9 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	return( 1 );

on_error:
	return( 0 );
}

/* Tests the libclocale_initialize function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_initialize(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	result = libclocale_initialize(
	          "test",
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        CLOCALE_TEST_ASSERT_IS_NULL(
         "error",
         error );

	return( 1 );

on_error:
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc CLOCALE_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] CLOCALE_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc CLOCALE_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] CLOCALE_TEST_ATTRIBUTE_UNUSED )
#endif
{
	CLOCALE_TEST_UNREFERENCED_PARAMETER( argc )
	CLOCALE_TEST_UNREFERENCED_PARAMETER( argv )

	CLOCALE_TEST_RUN(
	 "libclocale_get_version",
	 clocale_test_get_version );

	CLOCALE_TEST_RUN(
	 "libclocale_initialize",
	 clocale_test_initialize );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

