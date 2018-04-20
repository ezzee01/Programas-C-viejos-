#include<stdio.h>
#include<conio.h>
#include<string.h>
#define A 3

struct alumno{

	int legajo;
	char apellido[25], nombre[20];
	float promedio;
};

char menu(void);
void alta(alumno losAlumnos[]);
void listar(alumno losAlumnos[]);
void modificar(alumno losAlumnos[]);
void baja(alumno losAlumnos[]);
void mayorPromedio(alumno losAlumnos[]);
int buscaLegajo(alumno losAlumnos[], int leg);
int buscarLibre(alumno losAlumnos[]);
void toString(alumno unAlumno);

void main()
{
	alumno alumnitos[A];
	char seguir='s';
	for(int i=0; i<A; i++)
		alumnitos[i].legajo=0;

	clrscr();
	do
	{
		switch(menu())
		{
			case '1':
				clrscr();
				alta(alumnitos);
				break;
			case '2':
				clrscr();
				listar(alumnitos);
				break;
			case '3':
				clrscr();
				baja(alumnitos);
				break;
			case '4':
				clrscr();
				modificar(alumnitos);
				break;
			case '5':
				clrscr();
				mayorPromedio(alumnitos);
				break;
			case '6':
				seguir='n';
				break;

		}
	}while(seguir=='s');
	getch();
}
//Desarrollo de Funciones//
char menu()
{       char c;
	clrscr();
	printf("MENU\n1. ALTA\n2. LISTAR\n3. BAJA\n4. MODIFICAR\n5. MAYOR PROMEDIO\n6. SALIR\n");
	printf("Elija una opcion: ");
	c=getche();
	return c;
}

int buscarLibre(alumno losAlumnos[])
{
	int index=-1;
	for(int i=0; i<A; i++)
	   if(losAlumnos[i].legajo==0){
		index=i;
		break;
	   }
	return index;
}

void alta(alumno losAlumnos[])
{
	int index;
	float prom;
	int legajo;
	int encontro=0;
	/*Buscamos cual es el primer indice libre dentro del array*/
	index=buscarLibre(losAlumnos);
	if(index!=-1)//si hay lugar:
	{

		printf("INGRESO DE DATOS:\n");
		printf("Ingrese legajo: ");
		scanf("%d", &legajo);
		/*Buscamos si el legajo ya existe*/
		for(int i=0; i<A; i++)
		{
			if(legajo==losAlumnos[i].legajo)
			{
				encontro=1;//encontro en true
				break;
			}
		}
		if(!encontro)//entra si encontro==0
		{
			losAlumnos[index].legajo=legajo;
			printf("Ingrese apellido: ");
			fflush(stdin);
			gets(losAlumnos[index].apellido);
			printf("Ingrese nombre: ");
			fflush(stdin);
			gets(losAlumnos[index].nombre);
			printf("Ingrese promedio: ");
			scanf("%f", &prom);
			losAlumnos[index].promedio=prom;
			clrscr();
		}
		else
		{
			printf("­­El legajo ingresado ya existe!!");
			getch();
		}
	}
	else
	{
		printf("No queda espacio");
		getch();
	}
}

void toString(alumno unAlumno)
{
	printf("%d\t\t%s\t\t%s\t\t%.2f\n", unAlumno.legajo, unAlumno.apellido, unAlumno.nombre, unAlumno.promedio);
}

void listar(alumno losAlumnos[])
{
	int i,j;
	alumno auxAlumno;

	for(i=0; i<A-1;i++)
	{
		for(j=i+1; j<A; j++)
		{
			if(strcmp(losAlumnos[i].apellido,losAlumnos[j].apellido)>0)
			{
				auxAlumno=losAlumnos[i];
				losAlumnos[i]=losAlumnos[j];
				losAlumnos[j]=auxAlumno;
			}
		}
	}

	printf("Legajo\tApellido\tNombre\t\tPromedio\n");
	for(i=0; i<A; i++)
	{
		if(losAlumnos[i].legajo!=0)
		   toString(losAlumnos[i]);

	}
	getch();
}
void baja(alumno losAlumnos[])
{
	int legajo, flag=0;
	char opcion;
	printf("Ingrese legajo a dar de baja: ");
	scanf("%d", &legajo);
	for(int i=0; i<A; i++)
	{
		if(legajo==losAlumnos[i].legajo)
		{
			printf("Datos a eliminar:\n");

			toString(losAlumnos[i]);

			printf("\nLegajo encontrado. ¨Seguro desea dar de baja?");
			opcion=getche();
			if(opcion=='s')
			{
				losAlumnos[i].legajo=0;
				printf("­­Registro eliminado!!");
			}
			else
			{
				printf("El registro no fue eliminado!");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Legajo inexistente");
		getch();
	}
}
void modificar(alumno losAlumnos[])
{
	int legajo, flag=0;
	float prom;
	char opcion;
	clrscr();
	printf("Ingrese legajo a modificar: ");
	scanf("%d",& legajo);
	for(int i=0; i<A; i++)
	{
		if(legajo==losAlumnos[i].legajo)
		{
			printf("Datos encontrados:\n");

			toString(losAlumnos[i]);

			printf("\nIngrese el nuevo promedio: ");
			scanf("%f", &prom);
			printf("Esta seguro que desea modificar? ");
			opcion=getche();
			if(opcion=='s')
			{
				losAlumnos[i].promedio=prom;
				printf("Registro modificado");
			}
			else
			{
				printf("El registro no fue modificado");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Legajo inexistente");
		getch();
	}
}
void mayorPromedio(alumno losAlumnos[])
{
	int i, flag=0;
	float maxProm;
	for(i=0; i<A; i++)
	{
		if(losAlumnos[i].legajo!=0)
		  if(flag==0 || losAlumnos[i].promedio>maxProm)
		  {
			maxProm=losAlumnos[i].promedio;
			flag=1;
		  }
	}
	printf("El o los Alumnos con mayor promedio (%.2f) son:\n", maxProm);
	for(i=0; i<A; i++)
	{
		if(losAlumnos[i].legajo!=0)
		  if(losAlumnos[i].promedio==maxProm)
		  {

			toString(losAlumnos[i]);
		  }
	}
	getch();
}




