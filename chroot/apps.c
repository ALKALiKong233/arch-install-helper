#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int dechoose;
int ifoptimus;
int ifuefiboot;
void dechoosing();
void optimus();
void bootloader();

void apps()
{
   FILE *pacmanfile;
   pacmanfile = fopen(
      "/etc/pacman.conf", "a+"
   );
   fputs("\n[archlinuxcn]\n", pacmanfile);
   fputs("Server = https://mirrors.bfsu.edu.cn/archlinuxcn/$arch\n", pacmanfile);
   fclose(pacmanfile);
   system("pacman -Syu archlinuxcn-keyring");
   system("rm -fr /etc/pacman.d/gnupg");
   system("pacman-key --init");
   system("pacman-key --populate archlinux");
   system("pacman-key --populate archlinuxcn");
   system("pacman -S neofetch firefox noto-fonts noto-fonts-cjk noto-fonts-emoji networkmanager nvidia");
   system("systemctl enable NetworkManager");
   dechoosing();
   optimus();
   bootloader();
}

void dechoosing()
{
   printf("Choose a de you like \n 1.GNOME \n2.KDE \n3.LXDE \n4.XFCE \n");
   scanf("%d", &dechoose);
   switch(dechoose)
   {
      case 1:system("pacman -S gnome gnome-extra gnome-shell gdm");
         system("systemctl enable gdm");
         break;
      case 2:system("pacman -S plasma kde-applications sddm sddm-kcm");
         system("systemctl enable sddm");
         break;
      case 3:system("pacman -S xfce4 xfce4-goodies sddm");
         system("systemctl enable sddm");
         break;
      case 4:system("pacman -S lxde lxdm");
         system("systemctl enable lxdm");
         break;
    }
}

void optimus()
{
   printf("Do you need Optimus-Manager? [1 for yes, 2 for not] (fuck nvidia) \n");
   scanf("%d", &ifoptimus);
   if( ifoptimus == 1 )
   {
      system("pacman -S optimus-manager optimus-manager-qt");
      system("systemctl enable optimus-manager");
   }
}

void bootloader()
{
   printf("Do you use UEFI to boot? 1 for yes or 2 for no\n");
   scanf("%d", &ifuefiboot);
   switch (ifuefiboot)
   {
   case 1:
      system("grub-install ${grubins}");
      break;
   case 2:
      system("grub-install --target=i386-pc ${grubins}");
      break;
   }
   system("grub-mkconfig -o /boot/grub/grub.cfg");
}
