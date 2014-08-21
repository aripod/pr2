ACLOCAL_AMFLAGS=	-I autoconf

# IDL source files
idldir=		$(datadir)/idl/pr2_head
nobase_dist_idl_DATA= pr2_head.gen pr2_head.idl

pkgconfigdir=	$(libdir)/pkgconfig
pkgconfig_DATA=
pkgconfig_DATA+= pr2_head-genom3.pc

# we don't want generated templates in the distribution
#
DIST_SUBDIRS=		codels
SUBDIRS=		${DIST_SUBDIRS}

# recursion into templates directories configured with --with-templates
#
SUBDIRS+=		${AG_TEMPLATES_SUBDIRS}

distclean-local:
	-rm -rf ${AG_TEMPLATES_SUBDIRS}

# a rule to invoke skeleton merge mode
#
merge: merge-interactive
merge-%:
	cd ${top_srcdir} && ${genom3}  \
		skeleton -m $* pr2_head.gen
