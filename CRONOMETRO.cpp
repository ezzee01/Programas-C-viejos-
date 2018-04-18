#include<stdio.h>
#include<conio.h>
#include<dos.h>


void main()
{
	int hora=0, min=0, seg=0;

   for(;;)
   {
   	seg++;
   	if(seg==60)
      {
      	min++;
        	seg=0;
      }
      if(min==60)
      {
      	hora++;
        	min=0;
      }
      if(hora==24)
      {
      	hora=0;
      }
  	 	printf("%d : %d : %d\n", hora, min, seg);
    	sleep(1);
   	clrscr();
   }
}
