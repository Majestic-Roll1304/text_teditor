#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


int change(int *fd)
{//write a sentence at the beggining of the file
  fputs("estoy aqui\n",stdout);
  lseek(*fd,0,SEEK_END);
  write(*fd,"changed\n",7);
}
int reader(int *fd)
{//to read a file and save it in the buffer
  char buff[50]={0},ch=0;
  int x=lseek(*fd,0,SEEK_END);
  lseek(*fd,0,SEEK_SET);
  read(*fd,buff,50);

  //count of the current character
  //  ch=getc(stdin);
  while(x>=0&&x<50)
    {
      ch=getc(stdin);
      if(ch=='\b')
	{
	  x--;
	  continue;
	}
      if(ch=='\\');
      {
	break;
      }
      buff[x++]=ch;
      printf("%c",ch);
    }
  if(x==50)
    {
      fputs("the file size is at most",stdout);
    }
    write(*fd,buff,x);
}
int main(int argc, char **argv)
{
  if(argc==2)
    {
      int filedescriptor=open(argv[1],O_RDONLY);
      if(filedescriptor!=-1)
	{
	  fputs("editing existing file\n",stdout);
	}
      else{	
	  filedescriptor=open(argv[1],O_CREAT);
	  if(filedescriptor!=-1)
	    {
	      fputs("new file created\n",stdout);
	    }
	  else
	    {
	      printf("error creating file %s",argv[1]);
	    }
      }
      filedescriptor=open(argv[1],O_RDWR);
      fputs("here\n",stdout);
      //      change(&filedescriptor);
      reader(&filedescriptor);
    }
  else
    {
      fputs("insert the file argument\n",stdout);
    }
}
			    
