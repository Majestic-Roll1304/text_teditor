#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
  int fd=open("roshan.c",O_RDWR);
  int x=lseek(fd,0,SEEK_END);
  printf("%d",x);
}
