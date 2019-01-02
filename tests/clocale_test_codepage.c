/*
 * Library codepage functions test program
 *
 * Copyright (C) 2010-2019, Joachim Metz <joachim.metz@gmail.com>
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

#include "../libclocale/libclocale_codepage.h"

/* Tests the libclocale_codepage_get function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_codepage_get(
     void )
{
	libcerror_error_t *error = NULL;
	int codepage             = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libclocale_codepage_get(
	          &codepage,
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
	result = libclocale_codepage_get(
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

/* Tests the libclocale_codepage_set function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_codepage_set(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = libclocale_codepage_set(
	          LIBCLOCALE_CODEPAGE_ASCII,
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
	result = libclocale_codepage_set(
	          -1,
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

/* Tests the libclocale_codepage_copy_from_string function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_codepage_copy_from_string(
     void )
{
	libcerror_error_t *error = NULL;
	int codepage             = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "ascii",
	          5,
	          0,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ASCII );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso_8859_1",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_1 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso-8859-2",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_2 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-3",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_3 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-4",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_4 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-5",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_5 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-6",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_6 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-7",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_7 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-8",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_8 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-9",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_9 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-10",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_10 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-11",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_11 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-13",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_13 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-14",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_14 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-15",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_15 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-16",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_16 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "koi8-r",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_KOI8,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_KOI8_R );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "koi8_u",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_KOI8,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_KOI8_U );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "windows874",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "windows-932",
	          11,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "windows-936",
	          11,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp949",
	          5,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "ms950",
	          5,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1250",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1251",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1252",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1253",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1254",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1255",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1256",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1257",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1258",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-0",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "iso8859-12",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "koi8-a",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_KOI8,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp000",
	          5,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "cp1259",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libclocale_codepage_copy_from_string(
	          NULL,
	          "ascii",
	          5,
	          0,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          NULL,
	          5,
	          0,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "ascii",
	          (size_t) SSIZE_MAX + 1,
	          0,
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

	result = libclocale_codepage_copy_from_string(
	          &codepage,
	          "ascii",
	          5,
	          0xffffffffUL,
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

#if defined( HAVE_WIDE_CHARACTER_TYPE )

/* Tests the libclocale_codepage_copy_from_string_wide function
 * Returns 1 if successful or 0 if not
 */
int clocale_test_codepage_copy_from_string_wide(
     void )
{
	libcerror_error_t *error = NULL;
	int codepage             = 0;
	int result               = 0;

	/* Test regular cases
	 */
	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"ascii",
	          5,
	          0,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ASCII );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso_8859_1",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_1 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso-8859-2",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_2 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-3",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_3 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-4",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_4 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-5",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_5 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-6",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_6 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-7",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_7 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-8",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_8 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-9",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_9 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-10",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_10 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-11",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_11 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-13",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_13 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-14",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_14 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-15",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_15 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-16",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_ISO_8859_16 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"koi8-r",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_KOI8,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_KOI8_R );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"koi8_u",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_KOI8,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "codepage",
	 codepage,
	 LIBCLOCALE_CODEPAGE_KOI8_U );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"windows874",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"windows-932",
	          11,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"windows-936",
	          11,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp949",
	          5,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"ms950",
	          5,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1250",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1251",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1252",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1253",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1254",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1255",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1256",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1257",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1258",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-0",
	          9,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"iso8859-12",
	          10,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_ISO_8859,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"koi8-a",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_KOI8,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp000",
	          5,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"cp1259",
	          6,
	          LIBCLOCALE_CODEPAGE_FEATURE_FLAG_HAVE_WINDOWS,
	          &error );

	CLOCALE_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 0 );

	CLOCALE_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libclocale_codepage_copy_from_string_wide(
	          NULL,
	          L"ascii",
	          5,
	          0,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          NULL,
	          5,
	          0,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"ascii",
	          (size_t) SSIZE_MAX + 1,
	          0,
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

	result = libclocale_codepage_copy_from_string_wide(
	          &codepage,
	          L"ascii",
	          5,
	          0xffffffffUL,
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

#endif /* defined( HAVE_WIDE_CHARACTER_TYPE ) */

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

	CLOCALE_TEST_RUN(
	 "libclocale_codepage_get",
	 clocale_test_codepage_get );

	CLOCALE_TEST_RUN(
	 "libclocale_codepage_set",
	 clocale_test_codepage_set );

	CLOCALE_TEST_RUN(
	 "libclocale_codepage_copy_from_string",
	 clocale_test_codepage_copy_from_string );

#if defined( HAVE_WIDE_CHARACTER_TYPE )

	CLOCALE_TEST_RUN(
	 "libclocale_codepage_copy_from_string_wide",
	 clocale_test_codepage_copy_from_string_wide );

#endif /* defined( HAVE_WIDE_CHARACTER_TYPE ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

