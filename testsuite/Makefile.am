## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = dejagnu
SUBDIRS = libdejagnu

EXTRA_DIST = \
	runtest.all/topdir/subdir1/subsubdir1/subsubfile1 \
	runtest.all/topdir/subdir1/subfile1 \
	runtest.all/topdir/subdir1/subfile2 \
	runtest.all/topdir/subdir2/subfile2 \
	runtest.all/libs.exp \
	runtest.all/options.exp \
	runtest.all/remote.test \
	runtest.all/stats-sub.exp \
	runtest.all/stats.exp \
	runtest.all/target.test \
	runtest.all/utils.test \
	runtest.all/clone_output.test \
	runtest.all/config.test \
	runtest.all/default_procs.tcl \
	config/default.exp \
	lib/libsup.exp

RUNTEST = ` \
  if [ -f ${top_srcdir}/runtest$(EXEEXT) ] ; then \
    echo ${top_srcdir}/runtest$(EXEEXT); \
  else echo "ERROR: runtest not found" ; exit 1; fi`

RUNTESTDEFAULTFLAGS = --tool runtest
# --srcdir $$srcdir
CLEANFILES = *.log *.sum site.bak setval.tmp
