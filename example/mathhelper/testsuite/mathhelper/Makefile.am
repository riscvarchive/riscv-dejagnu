## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = dejagnu

# figure this out
#if HAVE_DEJAGNU
PROCTOR = proctor
#else
#PROCTOR = 
#endif

DL_LIB = @DL_LIB@
LIBLTDL = @LIBLTDL@
INCLTDL = @INCLTDL@

AM_CXXFLAGS = -g

CLEANFILES = *.log *.sum site.bak

all:
	@echo "Nothing to be done for all"

INCLUDES= \
 -I$(top_srcdir)/libmathhelper -I/opt/dejagnu-1.4.4/include

noinst_PROGRAMS = 

noinst_PROGRAMS += testmost
testmost_SOURCES = testmost.c
testmost_LDADD = $(top_builddir)/libmathhelper/libmathhelper.la

noinst_PROGRAMS += divzero
divzero_SOURCES = divzero.c
divzero_LDADD = $(top_builddir)/libmathhelper/libmathhelper.la
 
# this is the wrapper for the testcases
# noinst_PROGRAMS += $(PROCTOR) 
# proctor_SOURCES = proctor.cc
# proctor_LDFLAGS = -L../..
# proctor_LDADD = $(top_builddir)/libmathhelper/libmathhelper.la
# proctor_DEPENDENCIES = $(top_builddir)/libmathhelper/libmathhelper.la

