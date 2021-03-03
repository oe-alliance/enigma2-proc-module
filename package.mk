PKG_NAME="enigma2-proc-module"
#PKG_VERSION="1.0"
PKG_REV="1"
#PKG_ARCH="arm"
PKG_LICENSE="GPLv3"
PKG_SITE="https://github.com/oe-alliance"
PKG_URL=""
PKG_DEPENDS_TARGET="toolchain linux"
PKG_NEED_UNPACK="$LINUX_DEPENDS"
PKG_PRIORITY="optional"
PKG_SECTION="driver"
PKG_SHORTDESC="enigma2 proc module"
PKG_LONGDESC="Creates proc entries with hardware details"
PKG_MAINTAINER="OE Alliance"

PKG_IS_ADDON="no"
PKG_AUTORECONF="no"

pre_make_target() {
	unset LDFLAGS
}

make_target() {
	if [ -d "$ROOT/$BUILD" ]; then
		if [ -d "$ROOT/$PKG_BUILD" ]; then
			rm -rf "$ROOT/$PKG_BUILD"
		fi

		cp -rf "$PKG_DIR/source" "$ROOT/$PKG_BUILD"
	fi

	cd "$ROOT/$PKG_BUILD/epm"

	make \
		V=1 \
		ARCH=$TARGET_ARCH \
		KSRC=$(kernel_path) \
		CROSS_COMPILE=$TARGET_PREFIX

	fix_module_depends "epm.ko"
}

makeinstall_target() {
	mkdir -p "$INSTALL/lib/modules/$(get_module_dir)/$PKG_NAME"
	install -m 0755 *.ko "$INSTALL/lib/modules/$(get_module_dir)/$PKG_NAME"
}
