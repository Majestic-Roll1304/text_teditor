//for changing the buffer in realtime
//using system methods like clear and /bin/stty raw and cooked
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int realedit(char *buff,int len,int fd)
{
  char *buffer=malloc(len);
  strcpy(buffer,buff);
  write(1,buffer,len);
  
  char ch;
  int x=len;
  //have to add the dynamic size of the file instead of old file size
  while(x>=0 && x<=len)
    {
      if(x>=len)
	{
	  buffer=realloc(buffer,len+50);
	  len=len+50;
	}
      system("/bin/stty raw");
      read(1,&ch,1);
      if(ch==127)
	{
	  buffer[x--]='\0';
	}
      else if(ch==13)
	{
	  //if x is greater than the length  of the buffer stack  smashed error occurs
	  //unable to print the \n correctly like a text editor
	  //two days later the problem is solved :)
	  buffer[(x++)]='\n';
	}
      else if(ch==24)
	{
	  read(1,&ch,1);
	  if(ch==3)
	    {
	      system("/bin/stty cooked");
	      break;
	    }
	}
      else
	{
	  //adding the character if not a and b
	  //now i have to find a way to take input character from backspace and enter key
	  buffer[(x++)]=ch;
	}
      system("clear");
      system("/bin/stty cooked");
      write(1,buffer,x);
    }
  write(fd,buffer,x);

}
