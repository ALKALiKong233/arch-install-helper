live : live.o
	mv out/live.o out/live
.PHONY: live

live.o : live.c before/cfdisk.c before/installing.c
	-mkdir out
	gcc -o out/live.o live.c before/cfdisk.c before/installing.c

clean :
	rm -rf out
.PHONY: clean