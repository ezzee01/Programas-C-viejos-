//CARRANZA EZEQUIEL 1§A

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

struct producto
{
 int codigo, stock;
 char descripcion[25], marca[15], proveedor[20];
};

int ObtenerLugar(producto[]);
void validaString(char[],int);
int menu(void);
void alta(producto[]);
void modificacion(producto[]);
void baja(producto[]);
void listar(producto[]);

void main()
{

 producto productos[10], aux;
 char salir='n';

 clrscr();

 for(int i=0;i<10;i++)
 {
  productos[i].codigo = 0;
 }

 do
 {
  switch(menu())
  {

   case 1:
	  alta(productos);
	  break;

   case 2:
	  modificacion(productos);
	  break;

   case 3:
	  baja(productos);
	  break;

   case 4:
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
 while(opcion<1 || opcion>5)
 {
  printf("Error, reingrese: ");
  scanf("%d", &opcion);
 }
 return opcion;
}

int ObtenerLugar(producto x[])
{
 for(int i=0;i<10;i++)
 {
  if(x[i].codigo == 0)
  {
   return i;
   break;
  }
 }
 return -1;
}

void validaString(char s[],int c)
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
 int i, c, cod;
 char auxchar[30];

 clrscr();

 if(ObtenerLugar(x) != -1)
 {
  i = ObtenerLugar(x);

  printf("Ingrese codigo: ");
  scanf("%d", &x[i].codigo);

  printf("Ingrese descripcion: ");
  fflush(stdin);
  gets(auxchar);
  //VALIDAR DESCRIPCION
  c = 25;
  validaString(auxchar,c);
  strcpy(x[i].descripcion, auxchar);

  printf("Ingrese stock: ");
  scanf("%d", &x[i].stock);

  printf("Ingrese marca: ");
  fflush(stdin);
  gets(auxchar);
  //VALIDAR MARCA
  c = 15;
  validaString(auxchar, c);
  strcpy(x[i].marca,auxchar);

  printf("Ingrese proveedor: ");
  fflush(stdin);
  gets(auxchar);
  //VALIDAR PROVEEDOR
  c = 20;
  validaString(auxchar,c);
  strcpy(x[i].proveedor,auxchar);

  printf("Producto ingresado");

 }else{
  printf("La lista esta completa");
 }
 getch();
}

void modificacion(producto x[])
{
 int cod, c;
 char auxchar[30], confirm;

 clrscr();

 printf("Ingrese codigo: ");
 scanf("%d", &cod);

 for(int i=0; i<10 ;i++)
 {
  if(x[i].codigo == cod)
  {
   printf("Ingrese nueva marca: ");
   fflush(stdin);
   gets(auxchar);
   //VALIDAR MARCA
   c = 15;
   validaString(auxchar,c);
   strcpy(x[i].marca,auxchar);
   printf("Confirma el cambio? S/N: ");
   confirm = tolower(getche());
   if(confirm == 's')
   {
    printf("Se modifico el producto");

   }else{
    printf("No se modifico el producto");
    break;
   }
  }else{
   printf("El producto no existe");
   break;
  }
 }
 getch();
}

void baja(producto x[])
{
 int cod;
 char confirm;

 clrscr();

 printf("Ingrese codigo: ");
 scanf("%d", &cod);

 for(int i=0;i<10;i++)
 {
  if(x[i].codigo == cod)
  {
   printf("Confirma la baja= S/N: ");
   confirm = tolower(getche());

   if(confirm == 's')
   {
    x[i].codigo = 0;
    printf("Se dio de baja el producto");
   }else{
    printf("No se dio de baja el producto");
    break;
   }
  }else{
   printf("El producto no existe");
   break;
  }
 }
 getch();
}

void listar(producto x[])
{
 producto aux;
 int i;

 clrscr();

 for(i=0;i<10;i++)
 {
  for(int j=0;j<10;j++)
  {
   if(strcmp(x[i].marca, x[j].marca) > 0)
   {
    aux = x[i];
    x[i]=x[j];
    x[j]=aux;
   }
  }
 }
 for(i=0;i<10;i++)
 {
  if(x[i].stock >120 && x[i].codigo !=0)
  {
   printf("Codigo: %d Descripcion: %s Marca: %s", x[i].codigo,x[i].descripcion,x[i].marca);
   break;
  }else{
   printf("No hay productos con stock >120");
   break;
  }
 }
 getch();
}






