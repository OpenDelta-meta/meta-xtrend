
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS = "\
	kernel-module-cdfs \
	${@bb.utils.contains('MACHINE_FEATURES', 'v3d-mipsel', 'et-v3ddriver-${MACHINE}' , '', d)} \
	${@bb.utils.contains('MACHINE_FEATURES', 'micom', 'et-fpupdate-${MACHINE}' , '', d)} \
	\
	${@bb.utils.contains('MACHINE_FEATURES', 'wifi-kernel4', 'firmware-rtl8192eu firmware-rtl8188eu firmware-rtl8xxxu firmware-mt7601u kernel-module-rtl88x2bu kernel-module-r8188eu kernel-module-8192eu kernel-module-mt7601u kernel-module-rtl8xxxu' , '', d)} \
	"
