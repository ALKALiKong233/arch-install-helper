helper : helper.o
	mv out/helper.o out/helper
.PHONY: helper

helper.o : helper.c before/cfdisk.c before/installing.c chroot/locale.c chroot/user.c
	-mkdir out
	gcc -o out/helper.o helper.c before/cfdisk.c before/installing.c \
	chroot/locale.c chroot/user.c chroot/apps.c

clean :
	rm -rf out
.PHONY: clean