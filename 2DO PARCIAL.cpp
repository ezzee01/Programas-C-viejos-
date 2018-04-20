#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

struct producto
{
	int codigo, stock;
   char descripcion[25], marca[15], proveedor[20];
};

int menu(void);
void alta(producto[]);
int obtenerLugar(producto[]);
void validaString(char[], int);
void modificacion(producto[]);
void baja(producto[]);
void listar(producto[]);

void main()
{
	struct producto	productos[10];
   char salir = 'n';

   for(int i=0;i<10;i++)
   {
   	productos[i].codigo = 0;
   }   

   do
   {
   	switch(menu())
      {
      	case 1:
         			clrscr();
                  alta(productos);
                  break;

         case 2:
         			clrscr();
                  modificacion(productos);
                  break;

         case 3:
         			clrscr();
                  baja(productos);
                  break;

         case 4:
         			clrscr();
                  listar(productos);
                  break;

         case 5:
                  salir = 's';
                  break;
      }
   }while(salir == 'n');
}

int menu(void)
{
	int opcion;

   clrscr();

   printf("MENU\n");
   printf("1.Alta\n");
   printf("2.Modificacion\n");
   printf("3.Baja\n");
   printf("4.Listar\n");
   printf("5.Salir\n");
   printf("Ingrese una opcion: ");
   scanf("%d", &opcion);

   while(opcion < 1 || opcion > 7)
   {
   	printf("Error, reingrese opcion: ");
      scanf("%d", &opcion);
   }

   return opcion;
}

int obtenerLugar(producto x[])
{
	int index = -1;

   for(int i=0;i<10;i++)
   {
   	if(x[i].codigo == 0)
      {
   		index = i;
      }
   }
   return index;
}

void validaString(char s[], int c)
{
	while(strlen(s) > c)
   {
   	printf("Demasiado largo, reingrese: ");
      fflush(stdin);
      gets(s);
   }
}

void alta(producto x[])
{
	int index, letras, cod, flag = 0;
   char auxchar[30];

   if(obtenerLugar(x) != -1)
   {
   	index = obtenerLugar(x);

   	printf("Ingrese codigo: ");
      scanf("%d", &cod);

      for(int i=0;i<10;i++)
      {
      	if(cod == x[i].codigo)
         {
         	flag = 1;
            break;
         }
      }
      if(flag == 0)
      {
      	x[index].codigo = cod;

      	printf("Ingrese descripcion: ");
         fflush(stdin);
         gets(auxchar);
         //VALIDAR DESCRIPCION
         letras = 25;
         validaString(auxchar, letras);
         strcpy(x[index].descripcion, auxchar);

         printf("Ingrese stock: ");
  			scanf("%d", &x[index].stock);

  			printf("Ingrese marca: ");
  			fflush(stdin);
  			gets(auxchar);
  			//VALIDAR MARCA
  			letras = 15;
  			validaString(auxchar, letras);
  			strcpy(x[index].marca, auxchar);

  			printf("Ingrese proveedor: ");
  			fflush(stdin);
  			gets(auxchar);
  			//VALIDAR PROVEEDOR
  			letras = 20;
  			validaString(auxchar, letras);
  			strcpy(x[index].proveedor,auxchar);

  			printf("Producto ingresado");
      }else{
      	printf("El producto ya existe");
      }
   }else{
   	printf("Lista completa");
   }
   getch();
}

void modificacion(producto x[])
{
	int cod, flag=0, letras;
   char auxchar[30], rta;

   printf("Ingrese codigo: ");
   scanf("%d", &cod);

   for(int i=0;i<10;i++)
   {
   	if(cod == x[i].codigo)
      {
      	flag = 1;

         printf("Ingrese marca: ");
  			fflush(stdin);
  			gets(auxchar);
  			//VALIDAR MARCA
  			letras = 15;
  			validaString(auxchar, letras);
  			strcpy(x[i].marca, auxchar);

         printf("Confirma modificacion? S/N: ");
         rta = tolower(getche());

         if(rta == 's')
         {
         	printf("Producto modificado");
         }else{
         	printf("No se modifico producto");
         }
         break;
      }
   }
   if(flag == 0)
   {
   	printf("No existe producto");
   }
   getch();
}

void baja(producto x[])
{
	int cod, flag=0;
   char rta;

   printf("Ingrese codigo: ");
   scanf("%d", &cod);

   for(int i=0;i<10;i++)
   {
   	if(cod == x[i].codigo)
      {
      	flag = 1;

         printf("Confirma la baja? S/N: ");
         rta = tolower(getche());

         if(rta == 's')
         {
         	x[i].codigo = 0;
         	printf("Se dio de baja el producto");
         }else{
         	printf("No se dio de baja el producto");
         }
         break;
      }
   }
   if(flag == 0)
   {
   	printf("No existe producto");
   }
   getch();
}

void listar(producto x[])
{
	producto aux;
   int flag=0;

   for(int i=0;i<9;i++)
   {
   	for(int j=i+1;j<10;j++)
      {
      	if(strcmp(x[i].marca, x[j].marca) > 0)
         {
         	aux = x[i];
            x[i] = x[j];
            x[j] = aux;
         }
      }
   }

   for(int i=0;i<10;i++)
   {
   	if(x[i].codigo != 0 && x[i].stock > 120)
      {
      	printf("Codigo: %d Descripcion: %s Marca: %s", x[i].codigo,x[i].descripcion,x[i].marca);
         flag = 1;
      }
   }
   if(flag == 0)
   {
   	printf("No hay productos con stock >120");
   }
   getch();
}

