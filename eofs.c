#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  int x=open("roshan.c",O_RDWR);
  char buff[10]={-1};
  write(x,buff,10);
  printf("%d",EOF);
}
