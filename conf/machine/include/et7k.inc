# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

KERNELVERSION = "4.4.8"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	et-dvb-modules-${MACHINE} \
	gstreamer1.0-plugin-dvbmediasink \
	"

MTD_KERNEL = "mtd1"
MTD_ROOTFS = "mtd2"
KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

PREFERRED_PROVIDER_virtual/kernel = "linux-etxx00"
PREFERRED_VERSION_linux-etxx00 = "${KERNELVERSION}"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "et-blindscan-dvbc-utils-${MACHINE}"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_OUTPUT_DIR = "."
#KERNEL_CONSOLE = "null"

IMAGE_FSTYPES ?= "ubi"

MKUBIFS_ARGS = "-m 2048 -e 126976 -c 8192"
UBINIZE_ARGS = "-m 2048 -p 128KiB"

IMAGE_CMD_ubi_prepend = " \
        rm -rf ${IMAGE_ROOTFS}/tmp/*; \
        "

IMAGE_CMD_ubi_append = " \
	mkdir -p ${IMGDEPLOYDIR}/${IMAGEDIR}; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${IMGDEPLOYDIR}/${IMAGEDIR}/${ROOTFS_FILE}; \
	gzip -9c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${IMGDEPLOYDIR}/${IMAGEDIR}/${KERNEL_FILE}; \
	echo "${IMAGE_NAME}" > ${IMGDEPLOYDIR}/${IMAGEDIR}/imageversion; \
	echo "rename this file to 'force' to force an update without confirmation" > ${IMGDEPLOYDIR}/${IMAGEDIR}/noforce; \
	rm -f ${IMGDEPLOYDIR}/*.zip; \
	cd ${IMGDEPLOYDIR}; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubi; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
	rm -rf ${IMAGEDIR}; \
	"

MACHINE_FEATURES += "alsa usbhost switchoff osdposition hdmicec blindscan-tbs HDMI"

# Broken bootloader can only flash around 100 MB
FLASHSIZE = "96"

require conf/machine/include/tune-mips32.inc

BOX_BRAND = "xtrend"

STB_PLATFORM = "7genxt"

BLINDSCAN_BINARY = "avl_xtrend_blindscan"
