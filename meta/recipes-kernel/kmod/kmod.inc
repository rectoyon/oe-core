# Copyright (C) 2012 Khem Raj <raj.khem@gmail.com>
# Released under the MIT license (see COPYING.MIT for the terms)

SUMMARY = "Tools for managing Linux kernel modules"
DESCRIPTION = "kmod is a set of tools to handle common tasks with Linux kernel modules like \
               insert, remove, list, check properties, resolve dependencies and aliases."
HOMEPAGE = "http://packages.profusion.mobi/kmod/"
LICENSE = "GPL-2.0+ & LGPL-2.1+"
LICENSE_libkmod = "LGPL-2.1+"
SECTION = "base"

DEPENDS += "pkgconfig-native"

LIC_FILES_CHKSUM = "file://COPYING;md5=751419260aa954499f7abaabaa882bbe \
                    file://libkmod/COPYING;md5=a6f89e2100d9b6cdffcea4f398e37343 \
                   "
inherit autotools gtk-doc ptest

SRCREV = "49d8e0b59052999de577ab732b719cfbeb89504d"
# Lookout for PV bump too when SRCREV is changed
PV = "17+git${SRCPV}"

SRC_URI = "git://git.kernel.org/pub/scm/utils/kernel/kmod/kmod.git \
           file://depmod-search.conf \
           file://run-ptest \
           file://ptest.patch \
           file://avoid_parallel_tests.patch \
           file://fix-O_CLOEXEC.patch \
          "

S = "${WORKDIR}/git"

EXTRA_AUTORECONF += "--install --symlink"
EXTRA_OECONF +="--enable-debug --enable-logging --enable-tools --disable-manpages --with-zlib"

do_configure_prepend () {
        gtkdocize --docdir ${S}/libkmod/docs || touch ${S}/libkmod/docs/gtk-doc.make
}
