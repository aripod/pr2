lib_LTLIBRARIES = libpr2_torso_codels.la

libpr2_torso_codels_la_SOURCES=	pr2_torso_c_types.h
libpr2_torso_codels_la_SOURCES+=	pr2_torso_codels.c
libpr2_torso_codels_la_SOURCES+=	pr2_torso_PublishPort_codels.c

libpr2_torso_codels_la_CPPFLAGS=	$(requires_CFLAGS)
libpr2_torso_codels_la_LDFLAGS=	$(requires_LIBS)
libpr2_torso_codels_la_LDFLAGS+=	-release $(PACKAGE_VERSION)


# idl  mappings
BUILT_SOURCES=	pr2_torso_c_types.h
CLEANFILES=	${BUILT_SOURCES}
pr2_torso_c_types.h: ${top_srcdir}/pr2_torso.gen
	${genom3}  mappings \
	  -MD -MF .deps/$@.d -MT $@ --signature -l c $< >$@

-include .deps/pr2_torso_c_types.h.d
