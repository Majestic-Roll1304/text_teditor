//for changing the buffer in realtime
//using system methods like clear and /bin/stty raw and cooked
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int realedit(char *buffer,int len)
{

  
  write(1,buffer,len);
  char ch;
  int x=sizeof(buffer)-2;
  while(x>=0 && x<len)
    {
      system("/bin/stty raw");
      read(1,&ch,1);
      if(ch=='a')
	{
	  buffer[x--]='\0';
	}
      else if(ch=='b')
	{
	  //if x is greater than the length  of the buffer stack  smashed error occurs
	  //unable to print the \n correctly like a text editor
	  //two days later the problem is solved :)
	  buffer[(x++)+1]='\n';
	}
      else
	{
	  //adding the character if not a and b
	  //now i have to find a way to take input character from backspace and enter key
	  buffer[(x++)+1]=ch;
	}
      system("clear");
      system("/bin/stty cooked");
      write(1,buffer,sizeof(buffer));
    }

}
