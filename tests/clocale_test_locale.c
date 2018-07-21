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

#include "../libclocale/libclocale_locale.h"

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

#if defined( __GNUC__ ) && !defined( LIBCLOCALE_DLL_IMPORT )

/* Tests the libclocale_locale_get_codepage_from_charset function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_locale_get_codepage_from_charset(
     void )
{
	libcerror_error_t *error = NULL;
	int codepage             = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "UTF-8",
	          5,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "874",
	          3,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_874 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "932",
	          3,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_932 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "936",
	          3,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_936 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "949",
	          3,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_949 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "950",
	          3,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_950 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "1250",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_1250 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "1251",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_1251 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "1252",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_1252 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "1253",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_1253 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "1254",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_1254 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "1255",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_1255 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "1256",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_1256 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "1257",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_1257 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "1258",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_WINDOWS_1258 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "utf8",
	          4,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libclocale_locale_get_codepage_from_charset(
	          NULL,
	          "UTF-8",
	          5,
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

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          NULL,
	          5,
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

	result = libclocale_locale_get_codepage_from_charset(
	          &codepage,
	          "UTF-8",
	          (size_t) SSIZE_MAX + 1,
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

#endif /* defined( __GNUC__ ) && !defined( LIBCLOCALE_DLL_IMPORT ) */

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

#if defined( __GNUC__ ) && !defined( LIBCLOCALE_DLL_IMPORT )

	CLOCALE_TEST_RUN(
	 "libclocale_locale_get_codepage_from_charset",
	 clocale_test_locale_get_codepage_from_charset );

#endif /* defined( __GNUC__ ) && !defined( LIBCLOCALE_DLL_IMPORT ) */

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


