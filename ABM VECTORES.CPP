#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define E 3

void validarnombre(char[]);
void validardireccion(char[]);
void validarlocalidad(char[]);
int validaredad(int);
char validarcategoria(char);
float calcularsueldo(char,float);

void main()
{
	long DNI[E],auxdni;
   char nombre[E][30], direc[E][25], loc[E][20], cat[E], aux[50], auxcat, confirm, salir='n';
   int edad[E], auxedad, flag=0, i, j, maxindice, minindice, opcion;
   float sueldo[E], horas[E], auxfloat, maxsueldo, minsueldo;

   for (i = 0; i < E; i++)
   {
   	DNI[i] = 0;
   }

   do
   {
   	clrscr();
   	printf("Elija una opcion\n") ;
      printf("1.Alta\n") ;
      printf("2.Modificacion\n") ;
      printf("3.Listar\n") ;
      printf("4.Buscar por localidad\n") ;
      printf("5.Buscar empleados con maximo sueldo\n") ;
      printf("6.Buscar empleados con minimo sueldo\n") ;
      printf("7.Salir\n") ;
      printf("Opcion: ") ;
      scanf("%d", &opcion);

      while(opcion < 1 || opcion > 7)
      {
         printf("Error, reingrese opcion: ");
         scanf("%d", &opcion);
      }

      switch (opcion)
      {
         case 1:
		clrscr ();
		flag = 0;
		printf ("Alta de empleado\n\n") ;
		printf ("Ingrese DNI del empleado: ") ;
		scanf ("%ld", &auxdni);

	       	for (i = 0; i < E; i++)
		{
			if (DNI[i] == auxdni)
			{
				flag = 1;
				printf ("El empleado ya existe. ") ;
				break;
			}
		}
		for (i = 0; i < E; i++)
		{
			if (DNI[i] == 0)
			{

				DNI[i] = auxdni;

				printf ("Ingrese nombre y apellido del empleado: ") ;
				fflush(stdin) ;
				gets(aux);
				//VALIDAR NOMBRE
				validarnombre(aux);
				strcpy(nombre[i], aux);

				printf ("Ingrese direccion del empleado: ") ;
				fflush(stdin) ;
				gets(aux) ;
				//VALIDAR DIRECCION
				validardireccion(aux);
				strcpy (direc[i], aux);

				printf ("Ingrese localidad del empleado: ") ;
				fflush (stdin) ;
				gets (aux) ;
				//VALIDAR LOCALIDAD
				validarlocalidad(aux);
					strcpy (loc[i], aux);

				printf ("Ingrese edad del empleado: ") ;
				scanf ("%d",&auxedad);
				//VALIDAR EDAD
				edad[i] = validaredad(auxedad);

				printf ("Ingrese categoria del empleado: ") ;
				auxcat = toupper (getche () );
				printf ("\n") ;
				//VALIDACION CATEGORIA
				cat[i] = validarcategoria (auxcat);

				printf ("Ingrese cantidad de horas trabajadas: ") ;
				scanf ("%f", &horas[i]);

				//CALCULO SUELDO
				sueldo[i] = calcularsueldo (cat[i], horas[i]);
				flag = 1;
				break;
		     }

		  }
		  if (flag == 0)
					{
					printf ("La lista esta completa") ;
			}else{
					printf ("Operacion realizada") ;
					}
				getch ();
				break;

         case 2:
         			clrscr ();
                  flag=0;
         			printf ("Ingrese DNI del empleado: ") ;
				scanf ("%ld", &auxdni);

                  for (i = 0; i < E; i++)
         			{
				if(DNI[i] == auxdni)
            			{
               			flag = 1;
               			printf ("DNI: % ld Nombre: % s Localidad: % s Sueldo: % .2f", DNI[i], nombre[i], loc[i], sueldo[i]);

               			printf ("Reingrese nuevas horas trabajadas: ") ;
               			scanf ("%f", &horas[i]);
               			printf ("Confirma el cambio? S / N");
               			confirm = tolower (getche () );
               			while (confirm != 's' && confirm != 'n')
               			{
                  			printf ("Error, reingrese: ");
                  			confirm = tolower (getche () );
               			}

                        if (confirm == 's')
               			{
                  			//CALCULO SUELDO NUEVO
                  			sueldo[i] = calcularsueldo (cat[i], horas[i]);
                        }else{
                  			printf ("Las horas trabajadas no han sido modificadas") ;
               			}

               			break;
            			}

            			if (flag == 0)
            			{
               			printf ("Empleado no encontrado") ;
            			}
         			}

         			getch ();
         			break;

         case 3:
         			clrscr ();
         			for (i = 0; i < E - 1; i++)
         			{
            			for (j = i + 1; j < E; j++)
            			{
               			if (sueldo[i] < sueldo[i])
               			{
                  			strcpy(aux,direc[i]);
                           strcpy(direc[i],direc[j]);
                           strcpy(direc[j],aux);

                           strcpy(aux,nombre[i]);
                           strcpy(nombre[i],nombre[j]);
                           strcpy(nombre[j],aux);

                           strcpy(aux,loc[i]);
                           strcpy(loc[i],loc[j]);
                           strcpy(loc[j],aux);

                           auxcat = cat[i];
                           cat[i] = cat[j];
                           cat[j] = auxcat;

                           auxdni = DNI[i];
                           DNI[i] = DNI[j];
                           DNI[j] = auxdni;

                           auxedad = edad[i];
                           edad[i] = edad[j];
                           edad[j] = auxedad;

                           auxfloat = sueldo[i];
                           sueldo[i] = sueldo[j];
                           sueldo[j] = auxfloat;

                           auxfloat = horas[i];
                           horas[i] = horas[j];
                           horas[j] = auxfloat;
               			}
            			}
         			}

         			for (i = 0; i < E; i++)
         			{
            			if (DNI[i] != 0)
            			{
               			printf ("DNI: % ld Nombre: % s Localidad: % s Sueldo: % .2f", DNI[i], nombre[i], loc[i], sueldo[i]);
            			}
         			}

         			getch ();
         			break;

         case 4:
         			clrscr ();
         			printf ("Ingrese localidad del empleado: ") ;
         			fflush (stdin) ;
         			gets (aux) ;
         			//VALIDAR LOCALIDAD
                  validarlocalidad  (aux);

         			for (i = 0; i < E; i++)
         			{
            			if (strcmp (loc[i], aux)  == 0)
            			{
               			for (i = 0; i < E - 1; i++)
               			{
                  			for (j = i + 1; j < E; j++)
                  			{
                     			if (strcmp (nombre[i], nombre[j])  > 0)
                     			{
                        			strcpy(aux,direc[i]);
                           		strcpy(direc[i],direc[j]);
                           		strcpy(direc[j],aux);

                          			strcpy(aux,nombre[i]);
                           		strcpy(nombre[i],nombre[j]);
                           		strcpy(nombre[j],aux);

                           		strcpy(aux,loc[i]);
                           		strcpy(loc[i],loc[j]);
                           		strcpy(loc[j],aux);

                           		auxcat = cat[i];
                           		cat[i] = cat[j];
                           		cat[j] = auxcat;

                           		auxdni = DNI[i];
                           		DNI[i] = DNI[j];
                           		DNI[j] = auxdni;

                           		auxedad = edad[i];
                           		edad[i] = edad[j];
                           		edad[j] = auxedad;

                           		auxfloat = sueldo[i];
                           		sueldo[i] = sueldo[j];
                           		sueldo[j] = auxfloat;

                           		auxfloat = horas[i];
                           		horas[i] = horas[j];
                           		horas[j] = auxfloat;
                     			}
                  			}
               			}

               			printf ("Empleados de % s\n", loc[i]);
               			printf ("DNI: % ld Nombre: % s Direccion: % s", DNI[i], nombre[i], direc[i]);
               			}else{
               				printf ("No hay empleados de esa localidad") ;
            			}
         			}

                  getch ();
         			break;

         case 5:
         			flag=0;
         			clrscr ();
				for ( i = 0; i < E; i++)
         			{
            			if (DNI[i] != 0 && (flag == 0||sueldo[i] > maxsueldo) )
            			{
               			maxsueldo = sueldo[i];
               			maxindice = i;
               			flag = 1;
            			}

            			if (sueldo[i] == maxsueldo)
            			{
               			printf ("Empleado de maximo sueldo\n") ;
               			printf ("DNI: % ld Nombre: % s Localidad: % s Sueldo: % .2f", DNI[maxindice], nombre[maxindice], loc[maxindice], sueldo[maxindice]);
            			}
				}

         			getch ();
         			break;

         case 6:
         			clrscr ();
                  flag=0;
         			for ( i = 0; i < E; i++)
         			{
           				if (DNI[i] != 0 && (flag == 0 || sueldo[i] < minsueldo) )
            			{
               			minsueldo = sueldo[i];
               			minindice = i;
               			flag = 1;
            			}

            			if (sueldo[i] == minsueldo)
            			{
               			printf ("Empleado de minimo sueldo\n") ;
               			printf ("DNI: % ld Nombre: % s Localidad: % s Sueldo: % .2f", DNI[minindice], nombre[minindice], loc[minindice], sueldo[minindice]);
                     }
         			}

         			getch ();
         			break;

         case 7:
         			clrscr ();
         			printf ("Desea salir? (S / N) \n");
         			salir = tolower (getche () );

         			while (salir != 's'&&salir != 'n' )
         			{
            			printf ("Error, reingrese:  (S / N) \n");
            			salir = tolower (getche () );
         			}

         			printf ("\nPresione una tecla") ;
         			getch ();
         			clrscr ();
         			break;
      }
   }while (salir == 'n');
}

//*****FUNCIONES****
//VALIDACIONES

void validarnombre(char x[])
{
   while (strlen (x) > 30)
   {
      printf ("Error, demasiado largo. Reingrese: ");
      fflush (stdin) ;
      gets (x) ;
   }
}

void validardireccion(char x[])
{
   while (strlen (x) > 25)
   {
      printf ("Error, demasiado largo. Reingrese: ");
      fflush (stdin) ;
      gets (x) ;
   }
}

void validarlocalidad(char x[])
{
   while (strlen (x) > 20)
   {
      printf ("Error, demasiado largo. Reingrese: ");
      fflush (stdin) ;
      gets (x) ;
   }
}

int validaredad(int x)
{
   while(x < 18 || x > 70)
   {
      printf("Error, reingrese edad: ");
      scanf("%d", &x);
   }
   return x;
}

char validarcategoria(char x)
{
   while (x != 'A'&&x != 'B'&&x != 'C')
   {
      printf ("Error, reingrese categoria  (A, B, C) : ");
      x = toupper (getche () );
      printf ("\n") ;
   }

   return x;
}

float calcularsueldo(char L,float x)
{
   float b;

   switch (L)
   {
      case 'A':
      b = (float) 50 * x;
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

