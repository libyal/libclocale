/*
 * Library locale functions test program
 *
 * Copyright (C) 2010-2018, Joachim Metz <joachim.metz@gmail.com>
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
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "clocale_test_libcerror.h"
#include "clocale_test_libclocale.h"
#include "clocale_test_macros.h"
#include "clocale_test_unused.h"

#if defined( __GNUC__ ) && !defined( LIBCLOCALE_DLL_IMPORT ) && defined( WINAPI ) && ( WINVER < 0x0500 )

/* Tests the libclocale_GetLocaleInfoA function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_GetLocaleInfoA(
     void )
{
	DWORD locale_data = 0;
	int read_count    = 0;

	/* Test regular cases
	 */
	read_count = libclocale_GetLocaleInfoA(
	              LOCALE_USER_DEFAULT,
	              LOCALE_SDECIMAL,
	              (LPSTR) &locale_data,
	              sizeof( DWORD ) / sizeof( char ) );

	CLOCALE_TEST_ASSERT_NOT_EQUAL_INT(
	 "read_count",
	 read_count,
	 0 );

	/* Test error cases
	 */

	return( 1 );

on_error:
	return( 0 );
}

#endif /* defined( __GNUC__ ) && !defined( LIBCLOCALE_DLL_IMPORT ) && defined( WINAPI ) && ( WINVER <= 0x0500 ) */


/* Tests the libclocale_locale_get_codepage function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_locale_get_codepage(
     void )
{
	libcerror_error_t *error = NULL;
	int codepage             = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libclocale_locale_get_codepage(
	          &codepage,
	          &error );

	CLOCALE_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libclocale_locale_get_codepage(
	          NULL,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CLOCALE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libclocale_locale_get_decimal_point function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_locale_get_decimal_point(
     void )
{
	libcerror_error_t *error = NULL;
	int decimal_point        = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libclocale_locale_get_decimal_point(
	          &decimal_point,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libclocale_locale_get_decimal_point(
	          NULL,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	CLOCALE_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
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

#if defined( __GNUC__ ) && !defined( LIBCLOCALE_DLL_IMPORT ) && defined( WINAPI ) && ( WINVER < 0x0500 )

	CLOCALE_TEST_RUN(
	 "libclocale_GetLocaleInfoA",
	 clocale_test_GetLocaleInfoA );

#endif /* defined( __GNUC__ ) && !defined( LIBCLOCALE_DLL_IMPORT ) && defined( WINAPI ) && ( WINVER < 0x0500 ) */

	CLOCALE_TEST_RUN(
	 "libclocale_locale_get_codepage",
	 clocale_test_locale_get_codepage );

	CLOCALE_TEST_RUN(
	 "libclocale_locale_get_decimal_point",
	 clocale_test_locale_get_decimal_point );

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}


