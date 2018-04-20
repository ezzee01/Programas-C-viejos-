#include<stdio.h>
#include<conio.h>
#include<dos.h>

int esbiciesto(int);
int calculardias(struct date);
int validarfecha(struct date);

void main()
{
	struct date fecha;

   printf("Ingrese dia: ");
   scanf("%d", &fecha.da_day);

   printf("Ingrese mes: ");
   scanf("%d", &fecha.da_mon);

   printf("Ingrese anio: ");
   scanf("%d", &fecha.da_year);

   if(validarfecha(fecha))
   {
   	printf("Fecha valida");
   }else
   {
   	printf("Fecha invalida");
   }
   getch();
}

int esbiciesto(int anio)
{
	if(anio%400 == 0 || (anio%4 == 0 && anio%100 != 0))
   {
   	return 1;
   }else
   {
   	return 0;
   }
}

int calculardias(struct date d)
{
	switch(d.da_mon)
   {
   	case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12:
      			return 31;
               break;

      case 4:
      case 6:
      case 9:
      case 11:
      			return 30;
               break;

      case 2:
      			if(esbiciesto(d.da_year))
               {
               	return 29;
               }else{
               	return 28;
               }
               break;
   }
}

int validarfecha(struct date x)
{
	if(x.da_mon > 0 && x.da_mon <= 12)
   {
   	if(x.da_day > 0 && x.da_day <= calculardias(x))
      {
      	return 1;
      }else{
      	return 0;
      }
   }else{
   	return 0;
   }
}
