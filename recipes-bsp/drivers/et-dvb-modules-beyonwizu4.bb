require et-dvb-modules-new.inc

SRCDATE = "20180411"

SRC_URI = "http://source.mynonpublic.com/xtrend/beyonwizu4-drivers-${KV}-6.3.0-${SRCDATE}.zip"

SRC_URI[md5sum] = "8531611aed3c257bbff831ba343d7998"
SRC_URI[sha256sum] = "796fcf70fae36c212773e7fd6d8f8b2de39b39d4ddac5544cc8a267b5ecd192b"

COMPATIBLE_MACHINE = "^(et13000|beyonwizu4)$"
