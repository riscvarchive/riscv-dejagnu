## Process this file with automake to generate Makefile.in

# AUTOMAKE_OPTIONS =

man_MANS = runtest.1
# FIXME: We need to generate an info doc from SGML somehow, but for
# now, don't install the old texinfo document from version 1.3
# info_TEXINFOS = dejagnu.texi
DOCBOOK = @DOCBOOK@
TARGETS = overview.html overview.rtf overview.ps # overview.pdf overview.dvi

docs: $(TARGETS)

%.ps: %.dvi
	dvips -o $@ $<

%.pdf: %.sgml
	$(DOCBOOK)/db2pdf $<

%.dvi: %.sgml
	$(DOCBOOK)/db2dvi $<

%.rtf: %.sgml
	$(DOCBOOK)/db2rtf -o $@ $<

%.gif: %.fig
	convert -transparency white $< $@ # .fig -> .gif

%.epsi: %.eps
	ps2epsi $<                                     # .eps -> .epsi

%.eps: %.fig
	fig2dev -L ps -m 0.7 -p dummy $< > $@          # .fig -> .eps/portrait

%.html: %.sgml
	$(DOCBOOK)/db2html $<

# now for some extra dependencies that the automatic rules will not
# catch:

html rtf overview.pdf overview.ps overview.dvi overview.rtf overview.html: overview.sgml ref.sgml user.sgml

clean realclean distclean:
	rm -fr $(TARGETS) DBHTOHTML* overview.junk overview.{aux,dvi,log}

install-doc: $(TARGETS)
	$(mkinstalldirs) $(DESTDIR)$(pkgdatadir)/html $(DESTDIR)$(pkgdatadir)/html/stylesheet-images
	$(INSTALL_DATA) overview/*.html $(DESTDIR)$(pkgdatadir)/html
	$(INSTALL_DATA) overview/stylesheet-images/*.png $(DESTDIR)$(pkgdatadir)/html/stylesheet-images
	$(INSTALL_DATA) overview.rtf $(DESTDIR)$(pkgdatadir)/dejagnu.ps
	$(INSTALL_DATA) overview.ps $(DESTDIR)$(pkgdatadir)/dejagnu.ps
	$(INSTALL_DATA) overview.pdf $(DESTDIR)$(pkgdatadir)/dejagnu.pdf
	$(INSTALL_DATA) runtest.1 $(mandir)/man1/


