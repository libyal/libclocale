/*
 * The internal extern definition
 *
 * Copyright (C) 2010-2022, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _LIBCLOCALE_INTERNAL_EXTERN_H )
#define _LIBCLOCALE_INTERNAL_EXTERN_H

#include <common.h>

/* Define HAVE_LOCAL_LIBCLOCALE for local use of libclocale
 */
#if !defined( HAVE_LOCAL_LIBCLOCALE )

#include <libclocale/extern.h>

#if defined( __CYGWIN__ ) || defined( __MINGW32__ )
#define LIBCLOCALE_EXTERN_VARIABLE	extern
#else
#define LIBCLOCALE_EXTERN_VARIABLE	LIBCLOCALE_EXTERN
#endif

#else
#define LIBCLOCALE_EXTERN		/* extern */
#define LIBCLOCALE_EXTERN_VARIABLE	extern

#endif /* !defined( HAVE_LOCAL_LIBCLOCALE ) */

#endif /* !defined( _LIBCLOCALE_INTERNAL_EXTERN_H ) */

