all : helper.o chroot.o
	mv out/helper.o out/helper
	mv out/chroot.o out/chroot
.PHONY: all

helper.o : helper.c before/cfdisk.c before/installing.c
	-mkdir out
	gcc -o out/helper.o helper.c before/cfdisk.c before/installing.c

chroot.o : chroot.c chroot/locale.c chroot/user.c chroot/apps.c
	gcc -o out/chroot.o chroot.c chroot/locale.c chroot/user.c chroot/apps.c

clean :
	rm -rf out
.PHONY: clean