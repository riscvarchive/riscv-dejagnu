## Process this file with automake to generate Makefile.in

dist_man_MANS = runtest.1
info_TEXINFOS = dejagnu.texi

DOCBOOK = @DOCBOOK@
TARGETS = book1.html overview.ps overview.pdf

EXTRA_DIST = overview.sgml user.sgml ref.sgml \
	overview.pdf \
	overview.ps \
	html/book1.html \
	html/x953.html \
	html/x935.html \
	html/x916.html \
	html/x81.html \
	html/x755.html \
	html/x5158.html \
	html/x5058.html \
	html/x428.html \
	html/x319.html \
	html/x276.html \
	html/x227.html \
	html/x1655.html \
	html/x1600.html \
	html/x1590.html \
	html/x1551.html \
	html/x1522.html \
	html/x1493.html \
	html/x1462.html \
	html/x1445.html \
	html/x134.html \
	html/x1234.html \
	html/x1214.html \
	html/x1195.html \
	html/x1107.html \
	html/x107.html \
	html/f40.html \
	html/c848.html \
	html/c5112.html \
	html/c50.html \
	html/c401.html \
	html/c203.html \
	html/c1593.html \
	html/c1584.html \
	html/c1099.html \
	html/x992.html

docs: $(TARGETS)

%.ps: %.dvi
	src=$(srcdir); \
	dir=`(cd $${src}; pwd)`; \
	dvips -o $@ $*.dvi

%.pdf: %.sgml
	src=$(srcdir); \
	dir=`(cd $${src}; pwd)`; \
	$(DOCBOOK2PDF) $${dir}/$*.sgml

%.dvi: %.sgml
	src=$(srcdir); \
	dir=`(cd $${src}; pwd)`; \
	$(DOCBOOK2DVI) $${dir}/$*.sgml

%.html: %.sgml
	src=$(srcdir); \
	dir=`(cd $${src}; pwd)`; \
	mkdir html; \
	$(DOCBOOK2HTML) $${dir}/$*.sgml

# Now for some extra dependencies that the automatic rules will not
# catch:

book1.html: html/book1.html

html/book1.html overview.pdf overview.ps overview.html: overview.sgml ref.sgml user.sgml

html/book1.html: overview.sgml ref.sgml user.sgml

install-doc: $(TARGETS)
	$(mkinstalldirs) $(DESTDIR)$(pkgdatadir)/html $(DESTDIR)$(pkgdatadir)/html/stylesheet-images
	$(INSTALL_DATA)	html/*.html $(DESTDIR)$(pkgdatadir)/html
	$(INSTALL_DATA) overview.ps $(DESTDIR)$(pkgdatadir)/dejagnu.ps
	$(INSTALL_DATA) overview.pdf $(DESTDIR)$(pkgdatadir)/dejagnu.pdf
	$(INSTALL_DATA) $(srcdir)/runtest.1 $(mandir)/man1/
