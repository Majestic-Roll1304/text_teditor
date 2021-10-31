#include<unistd.h>
int finalwrite(int fd,char *buff,int x)
{
  x=printf("%s",buff);
  buff=realloc(buff,x);
  write(fd,buff,x);
}
