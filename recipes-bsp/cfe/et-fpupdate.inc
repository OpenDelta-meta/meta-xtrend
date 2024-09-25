DESCRIPTION = "Xtrend frontpanel update"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"
COMPATIBLE_MACHINE = "et"

PV = "${FPVERSION}"

S = "${WORKDIR}"

inherit update-rc.d

INITSCRIPT_NAME = "fpupdate"
INITSCRIPT_PARAMS = "start 22 S ."

FILES_${PN} = "${bindir} /lib/firmware ${sysconfdir}/init.d"

do_install() {
	install -d ${D}${bindir}
	install -d ${D}${nonarch_base_libdir}/firmware
	install -m 0755 ${S}/fpupdate ${D}${bindir}
	install -m 0644 ${S}/avrmain-* ${D}${nonarch_base_libdir}/firmware/

	echo "#!/bin/sh" > ${S}/fpupdate.sh
	echo "boxtype=\`cat /proc/stb/info/boxtype\`" >> ${S}/fpupdate.sh
	echo "if ! [ -f /lib/firmware/avrmain-\$boxtype.hex ]; then" >> ${S}/fpupdate.sh
	echo "	exit 0" >> ${S}/fpupdate.sh
	echo "fi" >> ${S}/fpupdate.sh
	echo "if ! [ -x ${bindir}/fpupdate ]; then" >> ${S}/fpupdate.sh
	echo "	exit 0" >> ${S}/fpupdate.sh
	echo "fi" >> ${S}/fpupdate.sh
	echo "${bindir}/fpupdate /lib/firmware/avrmain-\$boxtype.hex ${FPVERSION} && rm /lib/firmware/avrmain*.hex" >> ${S}/fpupdate.sh

	install -d ${D}${sysconfdir}/init.d
	install -m 0755 ${S}/fpupdate.sh ${D}${sysconfdir}/init.d/fpupdate
}

pkg_postinst_${PN}_append() {
	if test -z "$D"
	then
		# force update without requiring reboot
		# (update-rc.d does not restart the script, when it was already installed)
		${sysconfdir}/init.d/fpupdate
	fi
	true
}

PACKAGE_ARCH := "${MACHINE_ARCH}"
