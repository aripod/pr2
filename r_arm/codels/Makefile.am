lib_LTLIBRARIES = libpr2_r_arm_codels.la

libpr2_r_arm_codels_la_SOURCES=	pr2_r_arm_c_types.h
libpr2_r_arm_codels_la_SOURCES+=	pr2_r_arm_codels.c
libpr2_r_arm_codels_la_SOURCES+=	pr2_r_arm_move_codels.c

libpr2_r_arm_codels_la_CPPFLAGS=	$(requires_CFLAGS)
libpr2_r_arm_codels_la_LDFLAGS=	$(requires_LIBS)
libpr2_r_arm_codels_la_LDFLAGS+=	-release $(PACKAGE_VERSION)


# idl  mappings
BUILT_SOURCES=	pr2_r_arm_c_types.h
CLEANFILES=	${BUILT_SOURCES}
pr2_r_arm_c_types.h: ${top_srcdir}/pr2_r_arm.gen
	${genom3}  mappings \
	  -MD -MF .deps/$@.d -MT $@ --signature -l c $< >$@

-include .deps/pr2_r_arm_c_types.h.d
