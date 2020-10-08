#include <stdlib.h>
#include <stdio.h>

extern void cfdisk();
extern void installing();
extern void locale();
extern void user();
extern void apps();
int main()
{
   printf("Welcome to use!\n");
   cfdisk();
   installing();
   system("arch-chroot /mnt");
   user();
   locale();
   apps();
   system("exit");
}
