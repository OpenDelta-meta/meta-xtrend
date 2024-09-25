require conf/machine/include/et.inc

KERNELVERSION = "3.8.7"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "et-blindscan-dvbs-utils"

MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

# Broken bootloader can only flash around 100 MB
FLASHSIZE = "96"

PREFERRED_VERSION_linux-etxx00 = "${KERNELVERSION}"

MACHINE_FEATURES += "blindscan-tbs blindscan-dvbs YUV"

STB_PLATFORM = "1genxt"
