//for changing the buffer in realtime
//using system methods like clear and /bin/stty raw and cooked
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int realedit(char *buffer,int len,int fd,char *arg)
{
  write(1,buffer,len);
  char ch;
  int x=len;
  while(x>=0 && x<=len)
    {
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
