## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = dejagnu

all:
	@echo "Nothing to be done for all"

RUNTEST = ` \
  if [ -f ${top_srcdir}/runtest$(EXEEXT) ] ; then \
    echo ${top_srcdir}/runtest$(EXEEXT) ; \
  else echo "ERROR: runtest not found" ; exit 1; fi`

RUNTESTDEFAULTFLAGS = --tool runtest --srcdir $$srcdir
CLEANFILES = *.log *.sum site.bak setval.tmp
