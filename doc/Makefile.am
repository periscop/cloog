info_TEXINFOS = cloog.texi

cloog.pdf: gitversion.texi

gitversion.texi: @GIT_INDEX@
	echo '@set VERSION '`$(top_builddir)/genversion.sh`'' > $@
