#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void installing()
{
   system("timedatectl set-ntp true");
   system("rm -rf /etc/pacman.d/mirrorlist");
   system("echo 'Server = https://mirrors.bfsu.edu.cn/archlinux/$repo/os/$arch' > /etc/pacman.d/mirrorlist");
   system("pacstrap /mnt base linux linux-firmware nano base-devel man-db man-pages texinfo grub ntfs-3g efibootmgr os-prober bash");
   system("genfstab -U /mnt >> /mnt/etc/fstab");
}
