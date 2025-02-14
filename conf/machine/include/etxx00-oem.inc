# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

BOX_BRAND = "xtrend"

MTD_ROOTFS = "mmcblk0p4"
MTD_KERNEL = "mmcblk0p3"
KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.tar.bz2"

MTD_BLACK  = "mmcblk0"

DVBPROVIDER = "kernel"
DVBSKYPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gstreamer1.0-plugin-dvbmediasink \
	gstreamer1.0-libav \
	"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dtsdownmix --with-eac3 --with-h265 --with-vb6 --with-vb8 --with-vb9 --with-spark"

TARGET_ARCH = "arm"
DEFAULTTUNE = "cortexa15hf-neon-vfpv4"
IMAGE_FSTYPES += "tar.bz2"

PREFERRED_PROVIDER_virtual/kernel = "linux-etxx00"

MACHINE_FEATURES += "alsa switchoff hdmicec videoenhancement emmc mmc blindscan-tbs HDMI"

IMAGE_CMD_tar_prepend = "\
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	cp ${DEPLOY_DIR_IMAGE}/${MACHINE}_update.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/update.bin; \
	cp ${DEPLOY_DIR_IMAGE}/zImage ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "rename this file to 'force' to force an update without confirmation" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/noforce; \
	echo "this file enable kernel update" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/partition.update; \
	cd ${IMAGE_ROOTFS}; \
	tar -cvf ${DEPLOY_DIR_IMAGE}/rootfs.tar -C ${IMAGE_ROOTFS} .; \
	mv ${DEPLOY_DIR_IMAGE}/rootfs.tar ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
	bzip2 ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.tar.bz2; \
	rm -Rf ${IMAGEDIR}; \
	"

require conf/machine/include/tune-cortexa15.inc
require conf/machine/include/soc-family.inc

BLINDSCAN_BINARY = "avl_xtrend_blindscan"
