#! /bin/sh
# bootstrap -- Use this script to create generated files from the CVS dist
# Copyright (C) 2000 Gary V. Vaughan
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

## @start 1
#! /bin/sh

progname=`basename $0`
top_srcdir=`dirname $0`

verbose="";
quiet="false"
mode="generate"

usage()
{
  echo
  echo "usage: ${progname} [-h|-q|-v]"
  echo
  echo "options:"
  echo "        -h .. display this message and exit";
  echo "        -q .. quiet, don't display directories";
  echo "        -v .. verbose, pass -v to automake when invoking automake"
  echo "        -c .. clean, remove all aclocal/autoconf/automake generated files"
  echo
  exit 1
}
 
while test $# -gt 0; do
case $1 in
-h|--he|--hel|--help)
  usage ;;
-q|--qu|--qui|--quie|--quiet)
  quiet="true";
  shift;;
-v|--ve|--ver|--verb|--verbo|--verbos|--verbose)
  verbose="-v";
  shift;;
-c|--cl|--cle|--clea|--clean)
  mode="clean";
  shift;;
-*) echo "unknown option $1" ;
  usage ;;
*) echo "invalid parameter $1" ;
  usage ;;
esac
done
 
case $mode in 
generate)
  aclocal
  libtoolize --force
  automake --add-missing
  autoconf
  ;;
clean)
   test "$quiet" = "true" || echo "removing automake generated Makefile.in files"
  files=`find . -name 'Makefile.am' -print | sed -e 's%\.am%\.in%g'` ;
  for i in $files; do if test -f $i; then
    rm -f $i
    test "$verbose" = "-v" && echo "$i"
  fi; done

  test "$quiet" = "true" || echo "removing configure files"
  files=`find . -name 'configure' -print` ;
  test "$verbose" = "-v" && test -n "$files" && echo "$files" ;
  for i in $files; do if test -f $i; then
    rm -f $i config.sub config.guess depcomp install-sh mdate-sh missing \
        mkinstalldirs texinfo.tex compile
    test "$verbose" = "-v" && echo "$i"
  fi; done

  test "$quiet" = "true" || echo "removing aclocal.m4 files"
  files=`find . -name 'aclocal.m4' -print` ;
  test "$verbose" = "-v" && test -n "$files" && echo "$files" ;
  for i in $files; do if test -f $i; then
    rm -f $i
    test "$verbose" = "-v" && echo "$i"
  fi; done

  find . -name '*~' -print | xargs rm -f
  find . -name '*.orig' -print | xargs rm -f
  find . -name '*.rej' -print | xargs rm -f
  find . -name 'config.status' -print | xargs rm -f
  find . -name 'config.log' -print | xargs rm -f
  find . -name 'config.cache' -print | xargs rm -f
  find . -name 'Makefile' -print | xargs rm -f
  find . -name '.deps' -print | xargs rm -rf
  find . -name '.libs' -print | xargs rm -rf
  find . -name 'stamp-h.in' | xargs rm -rf
  find . -name 'autom4te*.cache' | xargs rm -rf
  ;;
esac
exit 0

## @end 1
