## Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = dejagnu

# Install all the associated data files
SUBDIRS = doc testsuite example

# Install the bourne shell script driver in the bindir
bin_SCRIPTS = runtest

# Install the main DejaGnu expect file in the datadir
pkgdata_SCRIPTS = config.guess runtest.exp

# Install config.guess too, so we can use it to figure out
# what type of machine we're running on.
libexecdir = $(pkgdatadir)/libexec
libexec_SCRIPTS = config.guess

TLCSH = @TCLSH@

RUNTESTDEFAULTFLAGS = --tool runtest --srcdir $(srcdir)/testsuite RUNTEST=$(RUNTEST)
RUNTEST = ` \
  if [ -f ${srcdir}/runtest$(EXEEXT) ] ; then \
    echo ${srcdir}/runtest$(EXEEXT) ; \
  else echo "ERROR: runtest not found" ; exit 1; fi`

CLEANFILES = x.log x.sum site.bak setval.tmp
check-DEJAGNU:
	@echo "Do nothing here, cause we don't want to run the tests twice"

# Set ourselves up to build a RedHat package
dist2: rpmspec overview.html
	-rm -fr dejagnu-${VERSION}.0
	cp -fpr $(srcdir) dejagnu-${VERSION}.0
	@echo "clean up stuff we don't want in the source file"
	(cd dejagnu-${VERSION}.0 ; $(srcdir)/Clean.tcl)
	-mkdir -p doc/overview
	-cp -fr doc/overview dejagnu-${VERSION}.0/doc/
	tar cvf ../dejagnu-${VERSION}.0.tar dejagnu-${VERSION}.0
	gzip -9fv ../dejagnu-${VERSION}.0.tar
	cp -f ../dejagnu-${VERSION}.0.tar.gz /usr/src/redhat/SOURCES/
	cp -f $(srcdir)/redhat/dejagnu.spec /usr/src/redhat/SPECS/

rpmspec:
	cp -f $(srcdir)/redhat/dejagnu.spec /usr/src/redhat/SPECS/

rpm: dist rpmspec
	cp -f $(distdir).tar.gz /usr/src/redhat/SOURCES/
	rpm -ba /usr/src/redhat/SPECS/dejagnu.spec

overview.html install-doc doc html dvi ps pdf rtf:
	cd doc && $(MAKE) $(FLAGS_TO_PASS) $@

# Automake sucks when it comes to building a distribution, so
# we just copy the source tree onto of what Automake did, and
# then we Clean it. Automake only includes the source files.
# We want all the testsuites, data files, and html versions of the doc.
dist-hook: rpmspec overview.html
	-rm -fr $(distdir)
	cp -fpr $(srcdir) $(distdir)
	(cd $(distdir) ; $(TCLSH) $(srcdir)/Clean.tcl)
	-cp -fr doc/overview $(distdir)/doc/


# Below, host-independent data files that need to get installed.
# We do it this way so we can use globbing.

lib_dest = $(DESTDIR)$(pkgdatadir)
lib_files = $(srcdir)/*.c $(srcdir)/lib/*.exp

baseboards_dest = $(DESTDIR)$(pkgdatadir)/baseboards
baseboards_files = $(srcdir)/baseboards/README $(srcdir)/baseboards/*.exp

config_dest = $(DESTDIR)$(pkgdatadir)/config
config_files = $(srcdir)/config/README $(srcdir)/config/*.exp

install-data-local:
	$(mkinstalldirs) $(lib_dest)
	for f in $(lib_files); do \
	  test ! -f "$$f" || $(INSTALL_DATA) $$f $(lib_dest); \
	done
	#
	$(mkinstalldirs) $(baseboards_dest)
	for f in $(baseboards_files); do \
	  test ! -f "$$f" || $(INSTALL_DATA) $$f $(baseboards_dest); \
	done
	#
	$(mkinstalldirs) $(config_dest)
	for f in $(config_files); do \
	  test ! -f "$$f" || $(INSTALL_DATA) $$f $(config_dest); \
	done

uninstall-local:
	for f in $(lib_files); do \
	  test ! -f "$$f" || rm -f $(lib_dest)/`basename "$$f"`; \
	done
	for f in $(config_files); do \
	  test ! -f "$$f" || rm -f $(config_dest)/`basename "$$f"`; \
	done
	for f in $(baseboards_files); do \
	  test ! -f "$$f" || rm -f $(baseboards_dest)/`basename "$$f"`; \
	done












