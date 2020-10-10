#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char disk1, mnt, esp, swap, grubins;
int ifuefi, ifswap;
void mountmnt();
void mountesp();
void swapon();

void cfdisk ()
{
   system("fdisk -l");
   printf("Type a disk here\n");
   scanf("%s",&disk1);
   setenv("disk1", &disk1, 1);
   system("cfdisk ${disk1}");
   system("fdisk -l");
   mountmnt();
   mountesp();
   swapon();
}

void mountmnt ()
{
   printf("Type a partition to mount /mnt\n");
   scanf("%s",&mnt);
   setenv("mnt", &mnt, 1);
   system("mkfs.ext4 ${mnt}");
   system("mount ${mnt} /mnt");
}

void mountesp ()
{
   printf("Do you use UEFI\n Type 1 for yes or 2 for false \n");
   scanf("%d", &ifuefi);
   if ( ifuefi == 1 )
   {
      printf("Type a partition to mount /mnt/boot/efi\n");
      scanf("%s",&esp);
      setenv("esp", &esp, 1);
      system("mkdir /mnt/boot");
      system("mkdir /mnt/boot/efi");
      system("mkfs.fat -F32 ${esp}");
      system("mount ${esp} /mnt/boot/efi");
   }
   printf("Type a disk to install grub\n");
   scanf("%s",&grubins);
   setenv("grubins", &grubins, 1);
}

void swapon ()
{
   printf("Do you use swap\n Type 1 for yes or 2 for false \n");
   scanf("%d", &ifswap);
   if ( ifswap == 1 )
   {
      printf("Type a partition to turn on swap\n");
      scanf("%s",&swap);
      setenv("swap", &swap, 1);
      system("mkswap ${swap}");
      system("swapon ${swap}");
   }      
}
