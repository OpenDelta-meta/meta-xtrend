DESCRIPTION = "v3d driver for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
PACKAGE_ARCH = "${MACHINE_ARCH}"

PROVIDES = "virtual/libgles2 virtual/egl"
DEPENDS = "xtrend-v3ddriver-headers"

PV = "${SRCDATE}"

SRC_URI = "https://www.dropbox.com/s/raw/mzizz30oxltjg58/et10000-v3ddriver-20170322.zip"

S = "${WORKDIR}"

do_configure() {
}

do_compile() {
}

do_install_append() {
	install -d ${D}${libdir}
	install -m 0755 ${S}/libnxpl.so ${D}${libdir}/
	install -m 0755 ${S}/libnexus.so ${D}${libdir}/
	install -m 0755 ${S}/libv3ddriver.so ${D}${libdir}/
	ln -s libv3ddriver.so ${D}${libdir}/libEGL.so
	ln -s libv3ddriver.so ${D}${libdir}/libGLESv2.so
}

FILES_${PN} = "${libdir}/*"
FILES_${PN}-dev = "${incdir}/*"

RPROVIDES_${PN} = "libnxpl.so libnexus.so libv3ddriver.so libGLESv2.so libEGL.so"

