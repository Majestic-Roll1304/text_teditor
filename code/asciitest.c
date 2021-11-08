#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char **argv)
{
  char ch;
  system("/bin/stty raw");
  if(argc==2)
    {
      int ptr=open("thh",O_RDONLY);
      lseek(ptr,0,SEEK_SET);
      read(ptr,&ch,1);
    }
  else if(argc==1)
    {
      read(1,&ch,1);
    }
  printf("%d",ch);
  system("/bin/stty cooked");

}
