## Process this file with automake to generate Makefile.in

# AUTOMAKE_OPTIONS =

DOCBOOK = @DOCBOOK@
TARGETS = overview.html overview.rtf # overview.dvi overview.ps

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

clean:
	rm -f $(TARGETS)

install-doc: $(TARGETS)
	$(mkinstalldirs) $(DESTDIR)$(pkgdatadir)/html
	$(INSTALL_DATA) overview/*.html $(DESTDIR)$(pkgdatadir)/html
#	$(INSTALL_DATA) overview.ps $(DESTDIR)$(pkgdatadir)/dejagnu.ps
#	$(INSTALL_DATA) overview.pdf $(DESTDIR)$(pkgdatadir)/dejagnu.pdf
