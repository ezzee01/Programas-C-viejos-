#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define E 3

struct e_empleado
{
	char nombre[30], direccion[25], localidad[20], categoria;
	long DNI;
	int edad;
	float horas, sueldo;
};

char validarcategoria(char);
void validardireccion(char[]);
void validarlocalidad(char[]);
int validaredad(int);
void validarnombre(char[]);
float calcularsueldo(char,float);
void tostring(e_empleado);
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


	for(i=0;i<E;i++)
	{
	 	empleados[i].DNI = 0;
	}

	do
	{
   	clrscr();
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
	printf("4.Listar\n");
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
			printf("El empleado ya existe");
			break;
      }
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
			validarnombre(aux);

			strcpy(emp[i].nombre,aux);

			printf("Ingrese direccion del empleado: ");
			fflush(stdin);
			gets(aux);
         //VALIDAR DIRECCION
	 		validardireccion(aux);
	 		strcpy(emp[i].direccion,aux);

			printf("Ingrese localidad del empleado: ");
			fflush(stdin);
			gets(aux);
         //VALIDAR LOCALIDAD
	 		validarlocalidad(aux);
	 		strcpy(emp[i].localidad,aux);

			printf("Ingrese edad del empleado: ");
			scanf("%d", &e);
			//VALIDAR EDAD
			emp[i].edad = validaredad(e);

			printf("Ingrese categoria del empleado: ");
			c = toupper(getche());
         getch();
			printf("\n");
			//VALIDACION CATEGORIA
			emp[i].categoria = validarcategoria(c);

			printf("Ingrese cantidad de horas trabajadas: ");
			scanf("%f", &auxfloat);
			emp[i].horas = auxfloat;
			//CALCULO SUELDO
			emp[i].sueldo = calcularsueldo(emp[i].categoria,emp[i].horas);

	 		flag=1;
	 		break;
      }
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
   printf("Modificacion de empleado\n\n");
   printf("Ingrese DNI del empleado: ");
   scanf("%ld", &dni);

   for(i=0;i<E;i++)
   {
   	if(emp[i].DNI == dni)
      {
         flag = 1;
         tostring(emp[i]);
      	printf("Reingrese nuevas horas trabajadas: ");
         scanf("%f", &auxfloat);
         printf("Confirma el cambio? S/N: ");
         confirm = tolower(getche());
         getch();
			printf("\n");
         while(confirm !='s' && confirm !='n')
         {
         	printf("Error, reingrese: ");
            confirm = tolower(getche());
            getch();
				printf("\n");
         }
         if(confirm == 's')
         {
				emp[i].horas = auxfloat;
         	//CALCULO SUELDO NUEVO
				emp[i].sueldo = calcularsueldo(emp[i].categoria,emp[i].horas);
            printf("Empleado modificado");
      	}else{
         	printf("Las horas trabajadas no han sido modificadas");
         }
      	break;
      }
   }
   if(flag==0)
   {
     	printf("Empleado no encontrado");
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
   printf("Baja de empleado\n\n");
   printf("Ingrese DNI del empleado: ");
   scanf("%ld", &dni);

   for(i=0;i<E;i++)
   {
   	if(emp[i].DNI == dni)
      {
      	flag=1;
         tostring(emp[i]);
         printf("Confirma la baja? S/N: ");
         confirm = tolower(getche());
         getch();
			printf("\n");
         while(confirm !='s' && confirm !='n')
         {
         	printf("Error, reingrese: ");
            confirm = tolower(getche());
            getch();
				printf("\n");
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
   }
   if(flag==0)
   {
    	printf("No se encontro empleado");
   }
   getch();
}

//LISTAR

void listar(e_empleado emp[])
{
	e_empleado aux;
   int i,j,flag=0;

   clrscr();
   printf("Listado de empleado\n\n");
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
      	tostring(emp[i]);
         flag = 1;
      }
   }
   if(flag==0)
   {
   	printf("No hay empleados cargados");
   }   
   getch();
}

//BUSCAR POR LOCALIDAD

void porlocalidad(e_empleado emp[])
{
	char loc[20], auxchar[50];
   e_empleado aux;
   int i,j,k;

   clrscr();
   printf("Busqueda de empleado\n\n");
   printf("Ingrese localidad del empleado: ");
   fflush(stdin);
	gets(auxchar);
   //VALIDAR LOCALIDAD
   validarlocalidad(auxchar);
   strcpy(loc,auxchar);
	for(i=0;i<E;i++)
   {
   	if(strcmp(emp[i].localidad,loc) ==0)
      {
      	//flag=1;
      	for (j=0;j<E-1;j++)
   		{
   			for(k=j+1;k<E;k++)
      		{
      			if(strcmp(emp[i].nombre,emp[j].nombre) >0)
         		{
         			aux = emp[j];
            		emp[j] = emp[k];
            		emp[k] = aux;
         		}
      		}
         }
      	printf("Empleados de %s\n",emp[i].localidad);
      	tostring(emp[i]);
      }else{
         printf("No hay empleados de esa localidad");
      }
      break;
   }
   getch();
}

//MAXIMO SUELDO

void maxsueldo(e_empleado emp[])
{
	int flag = 0, i;
   float maxsueldo;

   clrscr();
   printf("Empleados con maximo sueldo\n");
	for( i=0;i<E;i++)
   {
   	if(emp[i].DNI !=0 && (flag==0 || emp[i].sueldo > maxsueldo))
      {
      	maxsueldo = emp[i].sueldo;
         flag = 1;
      }
   }
   for(i=0;i<E;i++)
   {
   	if(emp[i].DNI !=0 && emp[i].sueldo == maxsueldo)
   	{
     		tostring(emp[i]);
   	}
   }
   if(flag==0)
   {
   	printf("No se encontraron empleados");
   }
   getch();
}

//MINIMO SUELDO

void minsueldo(e_empleado emp[])
{
	int flag =0, i;
   float minsueldo;

   clrscr();
   printf("Empleado de minimo sueldo\n");
	for(i=0;i<E;i++)
   {
   	if(emp[i].DNI !=0 && ( flag==0 || emp[i].sueldo <minsueldo))
      {
      	minsueldo = emp[i].sueldo;
         flag=1;
      }
   }
   for(i=0;i<E;i++)
   {
      if(emp[i].DNI !=0 && emp[i].sueldo == minsueldo)
      {
      	tostring(emp[i]);
      }
   }
   if(flag==0)
   {
   	printf("No se encontraron empleados");
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

void validarnombre(char x[])
{
	while(strlen(x) >30)
   {
		printf("Error,demasiado largo. Reingrese: ");
      fflush(stdin);
		gets(x);
   }


}

void validardireccion(char x[])
{
	while(strlen(x) >25)
   {
	printf("Error,demasiado largo. Reingrese: ");
      fflush(stdin);
		gets(x);
   }


}

void validarlocalidad(char x[])
{
	while(strlen(x) >20)
   {
		printf("Error,demasiado largo. Reingrese: ");
      fflush(stdin);
		gets(x);
   }


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
      getch();
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

void tostring(e_empleado empl)
{
	printf("DNI: %ld Nombre: %s Direccion: %s Localidad: %s Edad: %d Categoria: %c Horas de trabajo: %.2f Sueldo neto: %.2f \n", empl.DNI, empl.nombre, empl.direccion, empl.localidad, empl.edad, empl.categoria, empl.horas, empl.sueldo);
}
