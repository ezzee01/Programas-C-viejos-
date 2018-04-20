#include<stdio.h>
#include<conio.h>
#include<dos.h>
//#include<ctype.h>
//#include<string.h>
//#define X 4

void main()
{
	struct date fecha;
   struct time hora;

   getdate(&fecha);

   gettime(&hora);

   clrscr();

   printf("La fecha es: %d/%d/%d \n\n", fecha.da_day, fecha.da_mon, fecha.da_year);

   printf("La hora es: %d:%d:%d:%d", hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund);

   getch();
}
