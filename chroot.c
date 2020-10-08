#include <stdlib.h>
#include <stdio.h>
extern void locale();
extern void user();
extern void apps();
int main()
{
   user();
   locale();
   apps();
   system("exit");
}