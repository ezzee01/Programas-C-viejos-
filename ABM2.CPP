#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define E 40

struct e_empleado
{
	char nombre[30], direccion[25], localidad[20], categoria;
	long DNI;
	int edad;
	float horas, sueldo;
};

char validarcategoria(char);
char validardireccion(char[]);
char validarlocalidad(char[]);
int validaredad(int);
char validarnombre(char[]);
float calcularsueldo(char,float);
int menu(void);
void alta(e_empleado[]);
void modificacion(e_empleado[]);
void baja(e_empleado[]);
void listar(e_empleado[]);
void porlocalidad(e_empleado[]);
void maxsueldo(e_empleado[]);
void minsueldo(e_empleado[]);
char salir1(void);

void main()
{
	e_empleado empleados[E];
	int i;
	char salir='n';

	clrscr();

	for(i=0;i<E;i++)
	{
	 	empleados[i].DNI = 0;
	}

	do
	{
   	switch(menu())
		{
			case 1:
					alta(empleados);
					break;

			case 2:
           		modificacion(empleados);
               break;

         case 3:
           		baja(empleados);
               break;

         case 4:
           		listar(empleados);
               break;

         case 5:
          		porlocalidad(empleados);
               break;

         case 6:
           		maxsueldo(empleados);
               break;

         case 7:
           		minsueldo(empleados);
               break;

         case 8:
          		salir = salir1();
               break;
      }
   }while(salir=='n');
}

//*****FUNCIONES****

//MENU

int menu(void)
{
	int opcion;

	printf("Elija una opcion\n");
	printf("1.Alta\n");
	printf("2.Modificacion\n");
	printf("3.Baja\n");
	printf("4.Listar");
	printf("5.Buscar por localidad\n");
	printf("6.Buscar empleados con maximo sueldo\n");
	printf("7.Buscar empleados con minimo sueldo\n");
	printf("8.Salir\n");
	printf("Opcion: ");

	scanf("%d", &opcion);

	while(opcion<1 || opcion>8)
	{
		printf("Error, reingrese opcion: ");
		scanf("%d", &opcion);
	}

	return opcion;
}

//ALTA

void alta(e_empleado emp[])
{
	char aux[50], c;
   float auxfloat;
   int i, flag=0,e;
   long dni;

   clrscr();
   printf("Alta de empleado\n\n");
   printf("Ingrese DNI del empleado: ");
	scanf("%ld", &dni);
	for(i=0;i<E;i++)
	{
   	if(emp[i].DNI == dni)
      {
      	flag=1;
      }
   }
   if(flag==1)
   {
   	printf("El empleado ya existe");
      break;
   }
   for(i=0;i<E;i++)
   {
		if(emp[i].DNI == 0)
		{
      	emp[i].DNI = dni;

			printf("Ingrese nombre y apellido del empleado: ");
			fflush(stdin);
			gets(aux);
			//VALIDAR NOMBRE
         emp[i].nombre = validarnombre(aux);
			//strcpy(emp[i].nombre,validarnombre(aux));

			printf("Ingrese direccion del empleado: ");
			fflush(stdin);
			gets(aux);
         //VALIDAR DIRECCION
         emp[i].direccion = validardireccion(aux);
         //strcpy(emp[i].direccion,validardireccion(aux));

			printf("Ingrese localidad del empleado: ");
			fflush(stdin);
			gets(aux);
         //VALIDAR LOCALIDAD
         emp[i].localidad = validarlocalidad(aux);
         //strcpy(emp[i].localidad,validarlocalidad(aux));

			printf("Ingrese edad del empleado: ");
			scanf("%d", &e);
			//VALIDAR EDAD
			emp[i].edad = validaredad(e);

			printf("Ingrese categoria del empleado: ");
			c = toupper(getche());
			printf("\n");
			//VALIDACION CATEGORIA
			emp[i].categoria = validarcategoria(c);

			printf("Ingrese cantidad de horas trabajadas: ");
			scanf("%f", &auxfloat);
			emp[i].horas = auxfloat;
			//CALCULO SUELDO
			emp[i].sueldo = calcularsueldo(emp[i].categoria,emp[i].horas);

         flag=1;
      }
      break;
   }
   if(flag==0)
   {
   	printf("La lista esta completa");
   }else{
   	printf("Operacion realizada");
   }
   getch();
}

//MODIFICACION

void modificacion(e_empleado emp[])
{
	long dni;
   char confirm;
   int flag=0,i;
   float auxfloat;

   clrscr();
   printf("Ingrese DNI del empleado: ");
   scanf("%ld", &dni);

   for(i=0;i<E;i++)
   {
   	if(emp[i].DNI == dni)
      {
         flag = 1;
         printf("DNI: %ld Nombre: %s Localidad: %s Sueldo: %.2f",emp[i].DNI,emp[i].nombre,emp[i].localidad,emp[i].sueldo);
      	printf("Reingrese nuevas horas trabajadas: ");
         scanf("%f", &auxfloat);
         printf("Confirma el cambio? S/N");
         confirm = tolower(getche());
         while(confirm !='s' && confirm !='n')
         {
         	printf("Error, reingrese: ");
            confirm = tolower(getche());
         }
         if(confirm == 's')
         {
				emp[i].horas = auxfloat;
         	//CALCULO SUELDO NUEVO
				emp[i].sueldo = calcularsueldo(emp[i].categoria,emp[i].horas);
      	}else{
         	printf("Las horas trabajadas no han sido modificadas");
         }
      	break;
      }
      if(flag==0)
      {
      	printf("Empleado no encontrado");
      }
   }
   getch();
}

//BAJA

void baja(e_empleado emp[])
{
	long dni;
   char confirm;
   int flag=0,i;

   clrscr();
   printf("Ingrese DNI del empleado: ");
   scanf("%ld", &dni);

   for(i=0;i<E;i++)
   {
   	if(emp[i].DNI == dni)
      {
         flag = 1;
         printf("DNI: %ld Nombre: %s Localidad: %s Sueldo: %.2f",emp[i].DNI,emp[i].nombre,emp[i].localidad,emp[i].sueldo);
         printf("Confirma la baja? S/N");
         confirm = tolower(getche());
         while(confirm !='s' && confirm !='n')
         {
         	printf("Error, reingrese: ");
            confirm = tolower(getche());
         }
         if(confirm == 's')
         {
         	emp[i].DNI=0;
            printf("Se dio de baja el empleado");
         }else{
         	printf("No se realizo la baja");
         }
         break;
      }
      if(flag==0)
      {
      	printf("No se encontro empleado");
      }
   }
   getch();
}

//LISTAR

void listar(e_empleado emp[])
{
	e_empleado aux;
   int i,j;

   clrscr();
	for(i=0;i<E-1;i++)
   {
   	for(j=i+1;j<E;j++)
      {
      	if(emp[i].sueldo < emp[j].sueldo)
         {
         	aux = emp[i];
            emp[i] = emp[j];
            emp[j] = aux;
         }
      }
   }
   for(i=0;i<E;i++)
   {
   	if(emp[i].DNI !=0)
      {
      	printf("DNI: %ld Nombre: %s Localidad: %s Sueldo: %.2f",emp[i].DNI,emp[i].nombre,emp[i].localidad,emp[i].sueldo);
      }
   }
   getch();
}

//BUSCAR POR LOCALIDAD

void porlocalidad(e_empleado emp[])
{
	char loc[20], auxchar[50];
   e_empleado aux;
   int i,j;

   clrscr();
   printf("Ingrese localidad del empleado: ");
   fflush(stdin);
	gets(auxchar);
   //VALIDAR LOCALIDAD
   strcpy(loc,validarlocalidad(auxchar));
	for(i=0;i<E;i++)
   {
   	if(strcmp(emp[i].localidad,loc) ==0)
      {
      	for (i=0;i<E-1;i++)
   		{
   			for(j=i+1;j<E;j++)
      		{
      			if(strcmp(emp[i].nombre,emp[j].nombre) >0)
         		{
         			aux = emp[i];
            		emp[i] = emp[j];
            		emp[j] = aux;
         		}
      		}
         }
      	printf("Empleados de %s\n",emp[i].localidad);
      	printf("DNI: %ld Nombre: %s Direccion: %s",emp[i].DNI,emp[i].nombre,emp[i].direccion);
      }else{
         printf("No hay empleados de esa localidad");
      }
   }
   getch();
}

//MAXIMO SUELDO

void maxsueldo(e_empleado emp[])
{
	int flag =0, maxindice;
   float maxsueldo;

   clrscr();
	for(int i=0;i<E;i++)
   {
   	if(emp[i].DNI !=0 && ( flag==0 || emp[i].sueldo >maxsueldo))
      {
      	maxsueldo = emp[i].sueldo;
         maxindice = i;
         flag=1;
      }
      if(emp[i].sueldo == maxsueldo)
      {
      	printf("Empleado de maximo sueldo\n");
      	printf("DNI: %ld Nombre: %s Localidad: %s Sueldo: %.2f",emp[maxindice].DNI,emp[maxindice].nombre,emp[maxindice].localidad,emp[maxindice].sueldo);
      }
   }
   getch();
}

//MINIMO SUELDO

void minsueldo(e_empleado emp[])
{
	int flag =0, minindice;
   float minsueldo;

   clrscr();
	for(int i=0;i<E;i++)
   {
   	if(emp[i].DNI !=0 && ( flag==0 || emp[i].sueldo <minsueldo))
      {
      	minsueldo = emp[i].sueldo;
         minindice = i;
         flag=1;
      }
      if(emp[i].sueldo == minsueldo)
      {
      	printf("Empleado de minimo sueldo\n");
      	printf("DNI: %ld Nombre: %s Localidad: %s Sueldo: %.2f",emp[minindice].DNI,emp[minindice].nombre,emp[minindice].localidad,emp[minindice].sueldo);
      }
   }
   getch();
}

//SALIR

char salir1(void)
{

   char salir;

   clrscr();
 	printf("Desea salir? (S/N)\n");

 	salir = tolower(getche());

 	while(salir!='s' && salir!='n')
 	{
 		printf("Error, reingrese: (S/N)\n");

  		salir = tolower(getche());
 	}

 	printf("\nPresione una tecla");

 	getch();

  	clrscr();

   return salir;

}

//VALIDACIONES

char validarnombre(char x[])
{
	while(strlen(x) >30)
   {
		printf("Error,demasiado largo. Reingrese: ");
      fflush(stdin);
		gets(x);
   }

   return x;
}

char validardireccion(char x[])
{
	while(strlen(x) >25)
   {
   	printf("Error,demasiado largo. Reingrese: ");
      fflush(stdin);
		gets(x);
   }

   return x;
}

char validarlocalidad(char x[])
{
	while(strlen(x) >20)
   {
		printf("Error,demasiado largo. Reingrese: ");
      fflush(stdin);
		gets(x);
   }

   return x;
}

int validaredad(int x)
{
	while(x<10 || x>70)
   {
		printf("Error, reingrese edad: ");
      scanf("%d", &x);
   }
   return x;
}


char validarcategoria(char x)
{
	while(x!='A' && x!='B' && x!='C')
	{
		printf("Error, reingrese categoria (A,B,C): ");
		x = toupper(getche());
		printf("\n");
	}
   return x;
}

float calcularsueldo(char L,float x)
{
	float b;

	switch(L)
	{
		case 'A':
				b = (float)50 * x;
				break;

		case 'B':
				b = 30.50 * x;
				break;

		case 'C':
				b = 20.67 * x;
				break;
	}
   return b;
}
