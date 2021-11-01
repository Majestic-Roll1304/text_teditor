//for changing the buffer in realtime
//using system methods like clear and /bin/stty raw and cooked
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

  char buffer[]="how are you brother what is up with you\nhow is holding";
  write(1,buffer,sizeof(buffer));
  char ch;
  int x=sizeof(buffer)-2;
  while(x>0 && x<60)
    {  system("/bin/stty raw");
      read(1,&ch,1);
      if(ch=='a')
	{
	  puts("here");
	  buffer[x--]='\0';
	}
      system("clear");
      system("/bin/stty cooked");
      write(1,buffer,sizeof(buffer));
    }

}
