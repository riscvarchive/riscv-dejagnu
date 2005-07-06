
figdir = images
docname = dejagnu
lang = C
omffile = dejagnu.omf

entities = $(srcdir)/legal.xml
dist-hook: app-dist-hook
gnuae_helpdir = $(datadir)/gnome/help/$(docname)/C

CLEANFILES = \
	db2texi.refs \
	DejaGnu.texi \
	DejaGnu.info \
	dejagnu.txml \
	dejagnu.mxml \
	dejagnu.tex \
	dejagnu.texi \
	dejagnu.pdf \
	dejagnu.ps \
	dejagnu.rtf \
	omf_timestamp \
	manpages.ref 


gnuae_help_DATA =    \
        topic.dat    \
	dejagnu.xml \
	ref.xml \
	user.xml

MAKEINFO = @MAKEINFO@

#html: force
#	mkdir -p html/stylesheet
#	cp -r $(srcdir)/images/*.png html/stylesheet
#	xsltproc -v -o html/ $(srcdir)/stylesheets/general-customization.xsl $(srcdir)/dejagnu.xml

clean-local: force
	rm -fr html DejaGnu.info*

html: force
	docbook2html -o html $(srcdir)/dejagnu.xml
	mv html/t1.html html/index.html

pdf: force
	docbook2pdf $(srcdir)/dejagnu.xml

ps: force
	docbook2ps $(srcdir)/dejagnu.xml

rtf: force
	docbook2rtf $(srcdir)/dejagnu.xml

man: force
	db2x_xsltproc -s man $(srcdir)/dejagnu.xml -o dejagnu.mxml
	db2x_manxml dejagnu.mxml
#	docbook2man $(srcdir)/dejagnu.xml

texi: force
	db2x_xsltproc -s texi $(srcdir)/dejagnu.xml -o dejagnu.txml
	db2x_texixml dejagnu.txml
#	docbook2texi $(srcdir)/dejagnu.xml

info: texi
	$(MAKEINFO) DejaGnu.texi

lint:
	xmllint $(srcdir)/dejagnu.xml

# install GNOME help files, which are basically the html output
install-ghelp: html
	$(mkinstalldirs) $(gnuae_helpdir)/stylesheet
	$(mkinstalldirs) $(gnuae_helpdir)/images
	$(INSTALL_DATA) html/*.html $(gnuae_helpdir)
	$(INSTALL_DATA) html/stylesheet/*.png $(gnuae_helpdir)/stylesheet
#	cp -r $(srcdir)/images $(gnuae_helpdir)/images

force:

scrollkeeper:
	scrollkeeper-install $(prefix)/dejagnu.omf
	scrollkeeper-update $(prefix)/dejagnu.omf
