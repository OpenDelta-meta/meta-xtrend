require conf/machine/include/et.inc

KERNELVERSION = "4.10.6"

PREFERRED_VERSION_linux-etxx00 = "${KERNELVERSION}"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "et-blindscan-dvbc-utils-${MACHINE}"

MKUBIFS_ARGS = "-m 2048 -e 126976 -c 8192"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

MACHINE_FEATURES += "videoenhancement blindscan-tbs SCART"

STB_PLATFORM = "2genxt"
