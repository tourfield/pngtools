#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([pngtools],[0.1],[ywzj0306@163.com])
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADERS(config.h)
AM_INIT_AUTOMAKE(pngtools,0.1)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stddef.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset strerror strstr])

AC_CONFIG_FILES([Makefile
                 crc32/Makefile
                 minigzip/Makefile
                 resource/Makefile])
AC_OUTPUT
