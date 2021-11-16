#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
//to change the location of the character pointer in the file
//passing address to change the address of the original file descriptor

int edit(char *arg)
{
  //reading the file contents into a buffer
  //this process is repeated many times i must modify it once the code works properly
  int ptr=open(arg,O_RDWR);
  int x=getfilesize(&ptr);
  char buffer[x+1];
  read(ptr,buffer,x);
  buffer[x+1]='\0';
  remove(arg);
  ptr=open(arg,O_CREAT,00666);
  ptr=open(arg,O_WRONLY);
  int f=strlen(buffer);
  //i will insert edit function method here then f is the new buffer length cause i think i might need x(old buffer length)
  //felt to send the file pointer to the function rather than returning the whole buffer again here which i have to do a lot of work to pass the buffer by reference and edit it and write. 
  realedit(buffer,/*buffer length*/f,/*file descriptor*/ptr);
  //to change a file im using remove and remake method till i get a better idea
  //have to make a method to change the buffer dynamically
}

int backup(char *arg,int x)
{
  char newname[x+1];
  //getting a newname for the backup file 
  sprintf(newname,"%c%s",'1',arg);
  //for text the backup file is 1text
  int ptr=open(newname,O_CREAT,00666);
  //create a backup 
  int back=open(arg,O_RDONLY);
  //read from originalfile file
  int size=getfilesize(&back);
  char backupbuffer[size];
  read(back,backupbuffer,size);

  
  //write the buffer to the backup file
  ptr=open(newname,O_RDWR);
  write(ptr,backupbuffer,size);
  return  ptr;
  
}
  
int printfile(int fd)
{
  int sizeoffile=gotoend(&fd);
  char *buff=malloc(sizeoffile);
  gotobegin(&fd);
  //reading the file data into a buffer with memory or the size of the file which seems optimal for now
  read(fd,buff,sizeoffile);

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
      if(backup(argv[1],sizeof(argv[1]))!=-1)
	{
	  puts("created a backup");
	}
      //first try and open in read mode
      if(editmode(argv[1])!=-1)
	{
	  puts("the file exists");
	  edit(argv[1]);
	}
      else
	{
	  puts("the file doesn't exist");
	  puts("start editing by clicking backspace");
	  createmode(argv[1]);
	  edit(argv[1]);
	}
    }
  else{
    puts("enter an argument");
  }
}
