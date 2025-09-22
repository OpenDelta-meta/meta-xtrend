KV = "4.4.8"
SRCDATE = "20170424"
GCC = "6.3.0"

SRC_URI = "http://downloads.openpli.org/archive/xtrend/${MACHINE}-drivers-${KV}-${GCC}-${SRCDATE}.zip"

require et-nextv-dvb-modules.inc

SRC_URI[md5sum] = "ef54c0dc19c0b70b4f64e125fefcfa30"
SRC_URI[sha256sum] = "1d90f5523234ba745250e72acd64fe07e16f4fd3e9e1c04a2b0a159523a2d150"

COMPATIBLE_MACHINE = "et8500"
