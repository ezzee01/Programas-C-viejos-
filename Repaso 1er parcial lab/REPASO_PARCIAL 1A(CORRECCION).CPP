/* REPASO PRIMER PARCIAL DE LABORATORIO I
* El código fuente que se presenta tiene errores lógicos y sintácticos.
* Modificar las líneas de códigos necesarias para eliminar todos los errores.
* Agregar las líneas de código necesarias para validar que el legajo
* este comprendido entre 1 y 1000
*/

#include <conio.h> 																				  //libreria mal escrita
#include <stdio.h>
#include <string.h>                                                             //falta libreria para manejo de cadenas
#define TOTAL_VECTOR 30 																		  //mal escrito "define"

void main()          																			  //main con punto y coma y mayuscula
{
	int legajo[TOTAL_VECTOR], edad[TOTAL_VECTOR], maxLegajo=0, minEdad=100; 	  //usa ; para separar, mal cargado maxLegajo y minEdad

	char categoria[TOTAL_VECTOR], nya[TOTAL_VECTOR][20], maxNya[20], aux[50];

	for(int i=0; i<TOTAL_VECTOR; i++) 														  //no declarada i. , en vez de ;
	{
		clrscr();                                                                 //funcion mal escrita
		printf("INGRESE NUMERO DE LEGAJO DEL EMPLEADO: ");                        //funcion mal escrita
		scanf("%d", &legajo[i]);                                                  //punto y coma en el medio

		//VALIDACION DE LEGAJO

      while(legajo[i]<1 || legajo[i]>1000)
      {
      	printf("LEGAJO NO VALIDO, REINGRESE: ");
         scanf("%d", &legajo[i]);
      }

		printf("INGRESE EDAD DEL EMPLEADO: ");
		scanf("%d", &edad[i]);                                                    //falta de variable de control

		while( edad[i] < 1 || edad[i] > 120)                                      //no tenia (). Y && en vez de || en la logica, faltan indices
		{
			printf("ERROR, REINGRESE LA EDAD: ");                                  //funcion mal escrita
			scanf("%d", &edad[i]);                                                 //falta de &
		}

		printf("INGRESE NOMBRE Y APELLIDO DEL EMPLEADO: ");
      fflush(stdin);                                                            //falta funcion fflush
		gets(aux);

	//VALIDAR NOMBRE Y APELLIDO

      while(strlen(aux) >20)
      {
      	printf("DEMASIADO LARGO, REINGRESE: ");
         fflush(stdin);
         gets(aux);
      }

      strcpy(nya[i],aux);

		printf("\nINGRESE CATEGORIA\n");                                          //mal escrita la funcion
		printf("A: Junior\n");                                                    //terminacion con ","
		printf("B: Semisenior\n");
		printf("C: Senior\n");
                                                                                //funcion fflush cuando no es necesario
		scanf("%c", &categoria[i]);

		if(legajo[i] > maxLegajo)                                                 //falta variable de control en legajo mal logica
		{
   		maxLegajo = legajo[i];                                                 //mal cargadas las variables
   		strcpy(maxNya,nya[i]);                                                 //falta ;
   	}

		if(edad[i] < minEdad)                                                     //terminacion if con ;
		{
			minEdad = edad[i];
		}
   }                                                                            //falta cerrar for
   printf("\nMaximo legajo: %d\t%s ", maxLegajo, maxNya);                       //falta mascara de int
	printf("\nMinima edad: %d", minEdad);
	getch();

}
