#include<stdio.h>
int main()
{
  FILE *ptr=fopen("roshan.c","a");
  fputc('\b',ptr);
  fclose(ptr);
}
