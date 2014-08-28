lib_LTLIBRARIES = libpr2_rgba_codels.la

libpr2_rgba_codels_la_SOURCES=	pr2_rgba_c_types.h
libpr2_rgba_codels_la_SOURCES+=	pr2_rgba_codels.c
libpr2_rgba_codels_la_SOURCES+=	pr2_rgba_ReceiveImage_codels.c

libpr2_rgba_codels_la_CPPFLAGS=	$(requires_CFLAGS)
libpr2_rgba_codels_la_LDFLAGS=	$(requires_LIBS)
libpr2_rgba_codels_la_LDFLAGS+=	-release $(PACKAGE_VERSION)


# idl  mappings
BUILT_SOURCES=	pr2_rgba_c_types.h
CLEANFILES=	${BUILT_SOURCES}
pr2_rgba_c_types.h: ${top_srcdir}/pr2_rgba.gen
	${genom3}  mappings \
	  -MD -MF .deps/$@.d -MT $@ --signature -l c $< >$@

-include .deps/pr2_rgba_c_types.h.d
