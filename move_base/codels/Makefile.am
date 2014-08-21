lib_LTLIBRARIES = libpr2_move_base_codels.la

libpr2_move_base_codels_la_SOURCES=	pr2_move_base_c_types.h
libpr2_move_base_codels_la_SOURCES+=	pr2_move_base_codels.c
libpr2_move_base_codels_la_SOURCES+=	pr2_move_base_display_codels.c

libpr2_move_base_codels_la_CPPFLAGS=	$(requires_CFLAGS)
libpr2_move_base_codels_la_LDFLAGS=	$(requires_LIBS)
libpr2_move_base_codels_la_LDFLAGS+=	-release $(PACKAGE_VERSION)


# idl  mappings
BUILT_SOURCES=	pr2_move_base_c_types.h
CLEANFILES=	${BUILT_SOURCES}
pr2_move_base_c_types.h: ${top_srcdir}/pr2_move_base.gen
	${genom3}  mappings \
	  -MD -MF .deps/$@.d -MT $@ --signature -l c $< >$@

-include .deps/pr2_move_base_c_types.h.d
