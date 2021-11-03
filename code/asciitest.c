#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
  char ch;
  system("/bin/stty raw");
  read(1,&ch,1);
  system("/bin/stty cooked");
  printf("%d",ch);
}
