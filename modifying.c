#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int readmode(char *name)
{
  int fd=open(name,O_RDONLY);
  return fd;
}
int createmode(char *name)
{
  int fd=open(name,O_CREAT);
  puts("created new file");
  return fd;
}

int writemode(char *name)
{
  int fd=open(name,O_WRONLY);
  puts("created new file");
  write(fd,"ls",2);
  return fd;
}
int main(int argc, char **argv)
{
  //check for arguments = 2
  if(argc==2)
    {
      //first try and open in read mode
      if(readmode(argv[1])!=-1)
	{
	  puts("the file exists");
	}
      else
	{
	  puts("the file doesn't exist");
	  createmode(argv[1]);
	}
    }
  else{
    puts("enter an argument");
  }
}
