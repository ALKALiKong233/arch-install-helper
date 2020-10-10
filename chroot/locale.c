#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char hostname;

void locale()
{
   system("ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime");
   system("hwclock --systohc");
   FILE *localefile;
   localefile = fopen(
      "/etc/locale.gen", "w+"
   );
   fputs("\nen_US.UTF-8 UTF-8\n", localefile);
   fputs("en_SG.UTF-8 UTF-8\n", localefile);
   fputs("zh_CN.UTF-8 UTF-8\n", localefile);
   fclose(localefile);
   system("locale-gen");
   system("echo 'LANG=en_SG.UTF-8' > /etc/locale.conf");
   printf("What host name do you want to set?\n");
   scanf("%s",&hostname);
   setenv("hostname", &hostname, 1);
   system("echo '${hostname}' > /etc/hostname");
}