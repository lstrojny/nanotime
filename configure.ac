AC_INIT([libnanotime], [1.0.0], [lars@strojny.net])
AC_CONFIG_MACRO_DIR([m4])
AC_PROG_CC
AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile])
AC_ENABLE_SHARED
AC_DISABLE_STATIC
AC_PROG_LIBTOOL(libtool)
AC_CHECK_LIB(rt, clock_gettime)

PKG_CHECK_MODULES([CHECK], [check >= 0.9.0])

AM_INIT_AUTOMAKE([1.10 -Wall -Werror])
#AM_INIT_AUTOMAKE([1.14 -Wall -Werror -Wno-extra-portability])
AM_MAINTAINER_MODE
AM_PROG_CC_C_O

LT_PREREQ([2.2])

AC_OUTPUT
