dnl Functions for libclocale
dnl
dnl Version: 20120501

dnl Function to detect whether nl_langinfo supports CODESET
AC_DEFUN([AX_LIBCLOCALE_CHECK_FUNC_LANGINFO_CODESET],
 [AC_CHECK_FUNCS([nl_langinfo])

 AS_IF(
  [test "x$ac_cv_func_nl_langinfo" = xyes],
  [AC_CACHE_CHECK(
   [for nl_langinfo CODESET support],
   [ac_cv_cv_langinfo_codeset],
   [AC_LANG_PUSH(C)
   AC_LINK_IFELSE(
    [AC_LANG_PROGRAM(
     [[#include <langinfo.h>]],
     [[char* charset = nl_langinfo( CODESET );]] )],
    [ac_cv_cv_langinfo_codeset=yes],
    [ac_cv_cv_langinfo_codeset=no])
   AC_LANG_POP(C) ]) ],
  [ac_cv_cv_langinfo_codeset=no])

 AS_IF(
  [test "x$ac_cv_cv_langinfo_codeset" = xyes],
  [AC_DEFINE(
   [HAVE_LANGINFO_CODESET],
   [1],
   [Define if nl_langinfo has CODESET support.])
  ])
 ])

dnl Function to detect if libclocale dependencies are available
AC_DEFUN([AX_LIBCLOCALE_CHECK_LOCAL],
 [dnl Headers included in libclocale/libclocale_locale.c
 AC_CHECK_HEADERS([langinfo.h locale.h])

 dnl Check for environment functions in libclocale/libclocale_locale.c
 AC_CHECK_FUNCS([getenv])

 AS_IF(
  [test "x$ac_cv_func_getenv" != xyes],
  [AC_MSG_FAILURE(
   [Missing function: getenv],
   [1])
  ])
 
 dnl Check for localization functions in libclocale/libclocale_locale.c
 AS_IF(
  [test "x$ac_cv_enable_winapi" = xno],
  [AC_CHECK_FUNCS([localeconv])

  AS_IF(
   [test "x$ac_cv_func_localeconv" != xyes],
   [AC_MSG_FAILURE(
    [Missing function: localeconv],
    [1])
   ])
  ])
 
 AC_CHECK_FUNCS([setlocale])

 AS_IF(
  [test "x$ac_cv_func_setlocale" != xyes],
  [AC_MSG_FAILURE(
   [Missing function: setlocale],
   [1])
  ])
 
 AX_LIBCLOCALE_CHECK_FUNC_LANGINFO_CODESET
 
 ac_cv_libclocale_CPPFLAGS="-I../libclocale";
 ac_cv_libclocale_LIBADD="../libclocale/libclocale.la";

 ac_cv_libclocale=local
 ])

