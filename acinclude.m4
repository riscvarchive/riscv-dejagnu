AC_DEFUN([DJ_AC_PATH_DOCBOOK], [
AC_MSG_CHECKING(for Docbook tools)
AC_ARG_WITH(oskith, [  --with-docbook       directory where the db2 sgml tools are], with_docbook=${withval})
AC_CACHE_VAL(ac_cv_c_docbook,[
dnl first check to see if --with-docbook was specified
if test x"${with_docbook}" != x ; then
  if test -f ${with_docbook}/db2html ; then
    ac_cv_c_docbook=`(cd ${with_docbook}; pwd)`
  else
    AC_MSG_ERROR([${with_docbook} directory doesn't contain SGML tools])
  fi
fi
])
if test x"${ac_cv_c_docbook}" = x ; then
    for i in $ac_default_prefix/bin /usr/local/bin $OSKITHDIR/../bin /usr/bin /bin /opt /home; do
	dnl See is we have an SGML tool in that directory.
	if test -f $i/db2html ; then
	    ac_cv_c_docbook=$i
	    break
	fi
    done
fi

if test x"${ac_cv_c_docbook}" = x ; then
    AC_MSG_RESULT(none)
else
    DOCBOOK="${ac_cv_c_docbook}"
    AC_MSG_RESULT(${ac_cv_c_docbook})
fi

AC_SUBST(DOCBOOK)
])
