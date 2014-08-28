lib_LTLIBRARIES = libpr2_full_codels.la

libpr2_full_codels_la_SOURCES=	pr2_full_c_types.h
libpr2_full_codels_la_SOURCES+=	pr2_full_codels.c
libpr2_full_codels_la_SOURCES+=	pr2_full_PublishPort_codels.c
libpr2_full_codels_la_SOURCES+=	pr2_full_VideoCamera_RGBA_codels.c

libpr2_full_codels_la_CPPFLAGS=	$(requires_CFLAGS)
libpr2_full_codels_la_LDFLAGS=	$(requires_LIBS)
libpr2_full_codels_la_LDFLAGS+=	-release $(PACKAGE_VERSION)


# idl  mappings
BUILT_SOURCES=	pr2_full_c_types.h
CLEANFILES=	${BUILT_SOURCES}
pr2_full_c_types.h: ${top_srcdir}/pr2_full.gen
	${genom3}  mappings \
	  -MD -MF .deps/$@.d -MT $@ --signature -l c $< >$@

-include .deps/pr2_full_c_types.h.d
