#include <stdlib.h>
#include <stdio.h>

extern void cfdisk();
extern void installing();

int main()
{
   printf("Welcome to use!\n");
   cfdisk();
   installing();
   system("pacman -S git make gcc clang");
   system("git clone https://github.com/ALKALiKong233/arch-install-helper.git");
   system("cd arch-install-helper");
   system("make && mv out/chroot /mnt/chroot");
   printf("Now I will put the next part into your root dir, run ./chroot for next step");
   system("arch-chroot /mnt");
}
