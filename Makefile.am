# Process this file with automake to generate Makefile.in

AUTOMAKE_OPTIONS = dejagnu

EXTRA_DIST = ChangeLog.0 MAINTAINERS runtest site.tmpl \
	$(pkgdata_DATA) $(pkgdata_SCRIPTS) \
	$(config_DATA) $(config_SCRIPTS) \
	$(baseboard_DATA) $(baseboard_SCRIPTS) \
	$(TESTSUITE_FILES) $(XML) $(CONTRIB)

bin_SCRIPTS = runtest
include_HEADERS = dejagnu.h

pkgdata_SCRIPTS = \
  runtest.exp \
  lib/debugger.exp lib/dejagnu.exp lib/dg.exp lib/framework.exp \
  lib/ftp.exp lib/kermit.exp lib/libgloss.exp lib/remote.exp \
  lib/rlogin.exp lib/rsh.exp lib/standard.exp lib/target.exp \
  lib/targetdb.exp lib/telnet.exp lib/tip.exp lib/utils.exp

configdir = $(pkgdatadir)/config
config_DATA = config/README
config_SCRIPTS = \
	config/arc.exp \
	config/arm-ice.exp \
	config/base-config.exp \
	config/base68k.exp \
	config/bug.exp \
	config/cfdbug.exp \
	config/cygmon.exp \
	config/d10v.exp \
	config/ddb-ether.exp \
	config/ddb.exp \
	config/default.exp \
	config/dos.exp \
	config/dve.exp \
	config/gdb-comm.exp \
	config/gdb_stub.exp \
	config/h8300.exp \
	config/i386-bozo.exp \
	config/i960.exp \
	config/m32r-stub.exp \
	config/m32r.exp \
	config/m68hc11.exp \
	config/m68k-emc.exp \
	config/mips-idt.exp \
	config/mn10200-eval.exp \
	config/mn10300-eval.exp \
	config/netware.exp \
	config/powerpc-bug.exp \
	config/proelf.exp \
	config/rom68k.exp \
	config/sh.exp \
	config/sid.exp \
	config/sim.exp \
	config/slite.exp \
	config/sparclet.exp \
	config/tic80.exp \
	config/unix.exp \
	config/vr4100.exp \
	config/vr4300.exp \
	config/vr5000.exp \
	config/vxworks.exp

baseboarddir = $(pkgdatadir)/baseboards
baseboard_DATA = baseboards/README
baseboard_SCRIPTS = \
	baseboards/am33_2.0-libremote.exp \
	baseboards/arc-sim.exp \
	baseboards/arm-ice.exp \
	baseboards/arm-sid.exp \
	baseboards/arm-sim.exp \
	baseboards/basic-sid.exp \
	baseboards/basic-sim.exp \
	baseboards/cf.exp \
	baseboards/cygmon.exp \
	baseboards/cygwin.exp \
	baseboards/d10v-sim.exp \
	baseboards/d10v.exp \
	baseboards/d30v-sim.exp \
	baseboards/danlite-elf.exp \
	baseboards/dos.exp \
	baseboards/fr30-cygmon.exp \
	baseboards/fr30-elf.exp \
	baseboards/fr30-sim.exp \
	baseboards/frv-elf.exp \
	baseboards/frv-sim.exp \
	baseboards/frv-tiger.exp \
	baseboards/frv-tomcat.exp \
	baseboards/gdbserver-sample.exp \
	baseboards/h8300-sim.exp \
	baseboards/h8300.exp \
	baseboards/i386-bozo.exp \
	baseboards/i386-sid.exp \
	baseboards/i960-cyclone.exp \
	baseboards/i960-sim.exp \
	baseboards/jmr3904-sim.exp \
	baseboards/linux-gdbserver.exp \
	baseboards/linux-libremote.exp \
	baseboards/m32r-elf.exp \
	baseboards/m32r-sid.exp \
	baseboards/m32r-sim.exp \
	baseboards/m68hc11-sim.exp \
	baseboards/m68k-emc.exp \
	baseboards/m68k-sid.exp \
	baseboards/mcore-elf.exp \
	baseboards/mcore-moto-sim.exp \
	baseboards/mcore-pe.exp \
	baseboards/mcore-sim.exp \
	baseboards/mips-idt.exp \
	baseboards/mips-lnews-sim.exp \
	baseboards/mips-lsi-sim.exp \
	baseboards/mips-sim-idt32.exp \
	baseboards/mips-sim-idt64.exp \
	baseboards/mips-sim.exp \
	baseboards/mips64-sim.exp \
	baseboards/mips64vr4100-sim.exp \
	baseboards/mmixware-sim.exp \
	baseboards/mn10200-cygmon.exp \
	baseboards/mn10200-sim.exp \
	baseboards/mn10300-cygmon.exp \
	baseboards/mn10300-sim.exp \
	baseboards/msparc-cygmon.exp \
	baseboards/mt-sid.exp \
	baseboards/op50n.exp \
	baseboards/powerpc-bug.exp \
	baseboards/powerpc-bug1.exp \
	baseboards/powerpc-sim.exp \
	baseboards/powerpcle-sim.exp \
	baseboards/rom68k-idp.exp \
	baseboards/sh-hms.exp \
	baseboards/sh-sid.exp \
	baseboards/sh-sim.exp \
	baseboards/sparc-sim.exp \
	baseboards/sparc64-sim.exp \
	baseboards/sparclet-aout.exp \
	baseboards/sparclite-coff.exp \
	baseboards/sparclite-cygmon.exp \
	baseboards/sparclite-sim-le.exp \
	baseboards/sparclite-sim.exp \
	baseboards/strongarm-cygmon.exp \
	baseboards/tic80-sim.exp \
	baseboards/tx39-dve.exp \
	baseboards/tx39-sim.exp \
	baseboards/unix.exp \
	baseboards/usparc-cygmon.exp \
	baseboards/v850-sim.exp \
	baseboards/vr4100-ddb.exp \
	baseboards/vr4100-sim.exp \
	baseboards/vr4111-sim.exp \
	baseboards/vr4300-ddb.exp \
	baseboards/vr4300-sim.exp \
	baseboards/vr4300.exp \
	baseboards/vr5000-ddb.exp \
	baseboards/vx4300.exp \
	baseboards/vx68k.exp \
	baseboards/vx960.exp \
	baseboards/vxsparc.exp \
	baseboards/x86-cygmon.exp \
	baseboards/xscale-cygmon.exp \
	baseboards/xtensa-sim.exp

pkgdata_DATA = stub-loader.c testglue.c

djlibexecdir = $(pkgdatadir)/libexec
djlibexec_SCRIPTS = config.guess

# Contributed scripts, etc.

CONTRIB = contrib/compare_tests

# Testsuite.

TESTSUITE_FILES = \
	testsuite/runtest.all/topdir/subdir1/subsubdir1/subsubfile1 \
	testsuite/runtest.all/topdir/subdir1/subfile1 \
	testsuite/runtest.all/topdir/subdir1/subfile2 \
	testsuite/runtest.all/topdir/subdir2/subfile2 \
	testsuite/runtest.all/libs.exp \
	testsuite/runtest.all/options.exp \
	testsuite/runtest.all/remote.test \
	testsuite/runtest.all/stats-sub.exp \
	testsuite/runtest.all/stats.exp \
	testsuite/runtest.all/target.test \
	testsuite/runtest.all/utils.test \
	testsuite/runtest.all/clone_output.test \
	testsuite/runtest.all/config.test \
	testsuite/runtest.all/default_procs.tcl \
	testsuite/config/default.exp \
	testsuite/lib/libsup.exp \
	testsuite/lib/util-defs.exp \
	testsuite/libdejagnu/tunit.exp

RUNTEST = ${top_srcdir}/runtest
RUNTESTDEFAULTFLAGS = --srcdir $(srcdir)/testsuite

AM_CXXFLAGS = -I$(top_srcdir) -g
check_PROGRAMS = unit
unit_SOURCES = testsuite/libdejagnu/unit.cc

# Documentation.

dist_man_MANS = doc/runtest.1
info_TEXINFOS = doc/dejagnu.texi

DOCBOOK2PDF = @DOCBOOK2PDF@
DOCBOOK2RTF= = @DOCBOOK2RTF@
DOCBOOK2PS = @DOCBOOK2PS@
DOCBOOK2HTML = @DOCBOOK2HTML@
DOCBOOK2TEXI = @DOCBOOK2TEXI@

XML = doc/dejagnu.xml doc/legal.xml doc/ref.xml doc/user.xml

dejagnu.pdf: $(XML)
	$(DOCBOOK2PDF) $(srcdir)/doc/dejagnu.xml

dejagnu.ps: $(XML)
	$(DOCBOOK2PS) $(srcdir)/doc/dejagnu.xml

dejagnu.rtf: $(XML)
	$(DOCBOOK2RTF) $(srcdir)/doc/dejagnu.xml

html:
	$(DOCBOOK2HTML) -o html $(srcdir)/doc/dejagnu.xml

doc/dejagnu.texi: $(XML)
	$(DOCBOOK2TEXI) --string-param directory-description="The GNU testing framework." --string-param directory-category="Programming" $(srcdir)/doc/dejagnu.xml
	mv dejagnu.texi $(srcdir)/doc

# Packaging.

# RPM
rpm: dist $(srcdir)/packaging/rpm/dejagnu.spec
	cp -f $(srcdir)/packaging/rpm/dejagnu.spec /usr/src/redhat/SPECS/
	cp -f dejagnu-${VERSION}.tar.gz /usr/src/redhat/SOURCES/
	rpm -ba /usr/src/redhat/SPECS/dejagnu.spec

# Debian GNU/Linux package
deb: dist
	rm -rf dejagnu-${VERSION}
	tar xfz dejagnu-${VERSION}.tar.gz
	cp -fr $(srcdir)/packaging/deb dejagnu-${VERSION}/
	(cd dejagnu-${VERSION}; dpkg-buildpackage)

# Most proprietary Unices use /opt for optional packages.
PKGDIR = /opt

$(PKGDIR)/dejagnu:
	rm -rf dejagnu-${VERSION}
	mkdir dejagnu-${VERSION}
	cd dejagnu-${VERSION}
	$(srcdir)/configure -v --prefix $@
	make install

# Solaris package
solpkg: $(PKGDIR)/dejagnu
	cp $(srcdir)/packaging/pkg/prototype /tmp
	cp $(srcdir)/packaging/pkg/pkginfo /tmp
	here=`pwd`; \
	  cd /tmp; \
	  pkgmk -o -r / -d /tmp; \
	  tar cf $$here/dejagnu-${VERSION}.SPARC.2.8.pkg.tar DejaGnu; \
	  gzip -9fv  $$here/dejagnu-${VERSION}.SPARC.2.8.pkg.tar
	rm -rf /tmp/prototype /tmp/pkginfo /tmp/DejaGnu

# HP depot package
hpdepot: $(PKGDIR)/dejagnu
	swpackage -s $(srcdir)/packaging/depot/dejagnu.psf -x target_type=directory -d /tmp
	here=`pwd`; \
	  cd /tmp; \
	  tar cf $$here/dejagnu-${VERSION}.hpux11.depot dejagnu; \
	  gzip -9fv  $$here/dejagnu-${VERSION}.hpux11.depot; \
	  rm -rf /tmp/dejagnu
