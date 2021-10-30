#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include"pointer.c"
int updatebuffer(int fd,char *buff)
{
   buff=realloc(buff,100);
   int x=gotoend(&fd);
   gotobegin(&fd);
   char ch;
   while(x<100 && x>1)
     {
       ch=getc(stdin);
       if(ch=='\\')
	 {
	   buff[x--]='\0';
	 }
       buff[x++]=ch;
     }
   x=printf("%s",buff);
   write(fd,buff,x);
}

int printfile(int fd)
{
  int sizeoffile=gotoend(&fd);
  char *buff=malloc(sizeoffile);
  gotobegin(&fd);
  //reading the file data into a buffer with memory or the size of the file which seems optimal for now
  read(fd,buff,sizeoffile);
  updatebuffer(fd,buff);
} 

int editmode(char *name)
{
  int fd=open(name,O_RDWR);
  printfile(fd);
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
