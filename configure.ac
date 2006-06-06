dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.50)
AC_INIT([GNU DejaGnu], 1.4.99, [bug-dejagnu@gnu.org])
AM_INIT_AUTOMAKE
AM_MAINTAINER_MODE
AC_PROG_MAKE_SET

AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_EXEEXT

dnl Search for the Docbook utilities.
AC_PATH_PROG([DOCBOOK2HTML], [docbook2html], [false])
AC_PATH_PROG([DOCBOOK2RTF], [docbook2rtf], [false])
AC_PATH_PROG([DOCBOOK2PDF], [docbook2pdf], [false])
AC_PATH_PROG([DOCBOOK2PS], [docbook2ps], [false])
AC_PATH_PROG([DOCBOOK2TEXI], [docbook2texi], [false])

dnl Search for expect.
AC_PATH_PROG([EXPECT], [expect])
if test -z $ac_cv_path_EXPECT ; then
   AC_MSG_ERROR([unable to locate expect])
fi

dnl Check the Tcl version is >= 8.3.
AC_MSG_CHECKING([Tcl version 8.3 or greater])
AC_CACHE_VAL(ac_cv_dg_tcl_modern,[
  ac_cv_dg_tcl_modern=`$EXPECT << EOF
if @<:@ expr \\${tcl_version} >= 8.3  @:>@ then { puts yes } else { puts no }
EOF`
])
if test x${ac_cv_dg_tcl_modern} = xyes ; then
  AC_MSG_RESULT(${ac_cv_dg_tcl_modern})
else
  AC_MSG_ERROR([Tcl 8.3 or greater is required])
fi

AC_CONFIG_SUBDIRS([example/calc example/hello example/mathhelper])
AC_OUTPUT([Makefile])
