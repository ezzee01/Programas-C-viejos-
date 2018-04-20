/* Apellido:
   Nombre:
   Division:
*/
/*
CONSIGNA:
* El codigo fuente que se presenta tiene errores logicos y sintacticos.
  Modificar las lineas de codigo necesarias para eliminar todos los errores.
* Documentar los errores encontrados en cada linea de codigo a traves de
  comentarios
* No se podran realizar modificaciones en el codigo, que vayan en contra del
  enunciado.
* No deben existir variables que no se usen ni tampoco eliminar las que se
  entregan predefinidas.
* No se podra inicializar la variable maxMonto para el calculo del mayor monto


ENUNCIADO:
Una empresa que se dedica a la comercializacion de articulos para el
hogar, registra de cada articulo la siguiente informacion:
* Codigo
* Descripcion
* Precio unitario
* Stock disponible
Se sabe que la empresa cuenta con 15 articulos distintos.
Se pide:
-Realizar la carga de datos para cada articulo. Por cada articulo se debe
 calcular el monto por articulo, resultante del producto entre el stock y el
 precio unitario.
-Calcular el/los productos con mayor monto. PUEDE SER MAS DE UNO.
-Calcular la cantidad de productos cuyo stock supere las 20 unidades
 exclusive.
-Realizar las lineas de codigo necesarias para validar:
	   -Descripcion del producto no mayor a 50 caracteres. Utilizar un
	    auxiliar.
-Ordenar por descripcion del producto
*/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#define P 3

void main(void)                                                                 //falta void y tenia mayus
{
float maxMonto, precio[P], monto[P], auxPrecio;                                 //falta indice y ;
char descripcion[P][50], auxProd[100];                                          //mal indices y ; y variable maxProd inutil
int codigo[P], i, j, stock[P], auxCod, cont=0, flag=0;                          //falta indice y ;

clrscr();

for(i=0;i<P;i++)                                                                //1 de mas en el for
{

	printf("Ingrese descripcion del producto: ");

	fflush(stdin);
	gets(auxProd);

/* *****VALIDACION DESCRIPCION***** */

	while(strlen(auxProd) >50 )
   {
    	printf("Descripcion demasiado larga, reingrese: ");
      fflush(stdin);
      gets(auxProd);
   }

   strcpy(descripcion[i],auxProd);

	printf("Ingrese codigo del producto: ");
	scanf("%d",&codigo[i]);                                                      //falta indice y &

	printf("Ingrese precio del producto");
	scanf("%f",&precio[i]);                                                      //falta indice y &

	printf("Ingrese stock disponible del producto: ");
	scanf("%d",&stock[i]);                                                       //falta indice y &

	monto[i] = precio[i] * stock[i];                                             //falta indices
                             				
	if(flag==0 || monto[i]>maxMonto)                                            //mal signo en 1er condicion, falta condicion de flag y tiene ;
	{
    	maxMonto = monto[i];
    	flag=1;
	}

	if(stock[i]>20)                                                              //mal condicion
		cont++;

	//getch();
}                                                                               //falta cerrar 1er for

	printf("El Monto mayor es: $%.2f y los productos son:\n", maxMonto);
	printf("Codigo\tDescripcion\n");

	for(i=0;i<P;i++)
	{
		if(monto[i]==maxMonto)
		{
			printf("%d\t%s\n",codigo[i],descripcion[i]);                           //mal mascaras
		}
	}

	getch();
	clrscr();                                                                     //funcion mal escrita

/* *****ORDENAMIENTO***** */

   for(i=0;i<P-1;i++)
   {
    for(j=i+1;j<P;j++)
    {
    	if(strcmp(descripcion[i],descripcion[j]) >0)
      {
      	strcpy(auxProd,descripcion[i]);
         strcpy(descripcion[i],descripcion[j]);
         strcpy(descripcion[j],auxProd);

         auxPrecio=precio[i];
         precio[i]=precio[j];
         precio[j]=auxPrecio;

         auxCod=codigo[i];
         codigo[i]=codigo[j];
         codigo[j]=auxCod;
      }
    }
   }

	printf("Porductos ordenados por descripcion\n");
	printf("Codigo\tDescripcion\tPrecio");
	for(i=0;i<P;i++)                                                             //for con ,
		printf("\n%d\t%s\t\t%.2f\n", codigo[i], descripcion[i], precio[i]);

	getch();
	printf("La cantidad de productos con stock mayor a 20 unidades es: %d", cont);
	getch();

}






