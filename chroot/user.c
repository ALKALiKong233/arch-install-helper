#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char username;

void user()
{
   printf("Now set root user's password\n");
   system("passwd");
   printf("Now type a username you want to add\n");
   scanf("%s",&username);
   setenv("username", &username, 1);
   system("useradd -m -G '${username}' -s '/bin/bash' '${username}'");
   printf("Now set user's password\n");
   system("passwd ${username}");
   system("echo '${username}   ALL=(ALL) ALL' > /etc/sudoers");
}