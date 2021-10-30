#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int editmode(char *name)
{
  int fd=open(name,O_RDWR);
  return fd;
}

int createmode(char *name)
{
  //creating file with input name and mode rw_rw_rw which is general mode for text files
  int fd=open(name,O_CREAT,00666);
  puts("created new file");
  return fd;
}

int main(int argc, char **argv)
{
  //check for arguments = 2
  if(argc==2)
    {
      //first try and open in read mode
      if(editmode(argv[1])!=-1)
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
