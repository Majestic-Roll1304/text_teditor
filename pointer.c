#include<unistd.h>
//to change the location of the character pointer in the file
//passing address to change the address of the original file descriptor
int gotobegin(int *fd)
{
  return lseek(*fd,0,SEEK_SET);
}

int gotoend(int *fd)
{
  return lseek(*fd,0,SEEK_END);
}
