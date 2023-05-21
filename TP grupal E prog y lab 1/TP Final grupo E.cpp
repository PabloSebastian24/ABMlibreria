/*
_________________________________________________________________________________________________________________________________________________________________________________
--------------------------------------------------------------------------------------------------------------------------
6- ADMINISTRACION DE BIBLIOTECAS DE LIBROS                                                                               
• GRUPO E : ESPINOLA PABLO, FERNANDO CENTENO,DIANA  GALARZA SOTO, MARCOS CORIA, HUGO BARRETO 
---------------------------------------------------------------------------------------------------------------------------
_________________________________________________________________________________________________________________________________________________________________________________

*/

//Librerias : 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>                                                    
#include <ctype.h>
#include <time.h>
#include <conio.h>//libreria para getch()
#include<windows.h>//libreria para sleep
#define MAX 30
#define MAXIMO 50
#define AUXILIAR 1000
//funciones declaradas. 

void crear ();
void cargar();
void modificacion();
void bajas ();
void listado();
void consulta();
void maximocantidad();
void maximoestante();
void minimocantidad();
void minimoestante();
void ordenamientoabc();
void ordenamientoautor();
void ordenamientoeditorial();
void menumaxmin();
void menua();
void menuPrincipal();
char linea[MAX];
void estetica();
void gotoxy(int , int); //para ubicar datos en la pantalla


//Estructuras :
struct datosLibreria
{
	char titulo[MAX];
	char autor [MAXIMO];
	int estante;
	char editorial[MAX];                                                     
 	char ubicacion[MAX] ;
 	char estado[MAX];
 	int cantidad;
 	char reponer;
 
}dat; //instanciamos la estructura



void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  //para que el gotoxy funcione

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Funciones:
//0.0_
int option(char *cad, int n) //
{
	int i, c;
	c = getchar();
	if (c == EOF) {
		cad[0] = '\0';
		return 0;
	}
	if (c == '\n') {
		i = 0;
	} else {
	
		cad[0] = c;
		i = 1;
	}
	
	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		cad[i] = c;
	}
	cad[i] = '\0';
 
	/*3. LIMPIEZA DEL BUFFER */
 
	/* Finalmente limpiamos el buffer si es necesario */
	if (c != '\n' && c != EOF) /* es un caracter */
		while ((c = getchar()) != '\n' && c != EOF);
 
	return 1;
}

// 0.1
void presentacion()
{
		int i;
	for (int i= 0 ; i<=95 ; i++){
			gotoxy(i,1); 
		printf("%c", 254); //es el codigo ASCII
	}
	gotoxy(28,2);
		printf("*ADMINISTRACION  DE  LIBROS  DE BIBLIOTECA* \n");
	gotoxy(40,3);
		printf("   G R U P O   E \n");
	gotoxy(28,4);
		printf("Fecha de realizacion: 31/07/2022 a 22/08/2022\n");
		for (int i= 0 ; i<=95 ; i++){
			gotoxy(i,5); 
		printf("%c", 254); //es el codigo ASCII
	}
	i = 0;
	putchar('\n');

	}

//0.2
void menuPrincipal()
{
char repite = 1;
int opcion = -1;
/* Cuando el usuario ingresa texto en lugar de ingresar una opción. El programa no modifica
	el valor de opcion. En ese caso, no se debe de ingresar a ninguno de los case, por eso se está
	inicializando la variable opcion con un valor que no permita ejecutar ningún case. Simplemente,
	volver a interar y pedir nuevamente la opción. */
do{
	
     system("CLS");
     presentacion();
     printf(" \n\n\t\t\t 1. Crear archivo binario. \n");
     printf(" \t\t\t 2. Cargar un libro . \n");
     printf(" \t\t\t 3. Modificar libro. \n");
     printf(" \t\t\t 4. Bajas de libros. \n");
     printf(" \t\t\t 5. Ordenamiento de libros (MIN/Max). \n");
     printf(" \t\t\t 6. Informacion de todos los libros.  \n");
     printf(" \t\t\t 7. Informacion de un libro en particular.  \n");
     printf(" \t\t\t 8. Salir del programa. \n");
     printf("\n\t\t Ingrese su opcion: [ ]\b\b");
     option(linea, MAX);
     sscanf(linea, "%d", &opcion);
     switch(opcion)
        {
	     case 1 :
	             system("CLS");
	             crear();	        	
	     break;
	
	     case 2 :  
	             system("CLS");
			     cargar();
	     break;
	
	     case 3 :
	     	     system("CLS");
	     	     modificacion();
	     break;
	
	     case 4 :
	             system("CLS");
	     	     bajas();
	     break;
	     
	     case 5 :  
		     	system("CLS");
	  		   	menumaxmin();
		 
	     break;
	
	     case 6:
	     	     system("CLS");
	     	     listado();
	     break;
	     
	     case 7:
				system("cls");
				menua();
	     		break;
	
	     case 8 :
	     	 	system("cls");
	     		int i;
		for (int i= 0 ; i<=95 ; i++){
			gotoxy(i,8); 
		printf("%c", 205); //es el codigo ASCII
	     }
	     	gotoxy(26,10);
	     	printf(" H A S T A   L A   P R  O X I M A !!!");
	     		for (int i= 0 ; i<=95 ; i++){
			gotoxy(i,12); 
		printf("%c", 205); //es el codigo ASCII
	     }
	     	getch();
	     		repite = 0;
	     break;
	     
        }
    } while(repite);
 
}

// 1_

void crear()      //Creamos un archivo 
{
    FILE *archivo; //definimos un puntero en la  estructura file. En este caso archivo es el puntero de la estructura file.
    archivo=fopen("librostp.dat","wb"); // abre un archivo binario para operaciones de escritura.

    if (archivo==NULL) //En caso de detectarse un error devuelve null 
	{
	  exit(1);
	}
	else
	{
     printf("Archivo creado con exito!!\n"); // avisa que el archivo ha sido creado con exito
     fclose(archivo);//cerramos el archivo
	 system("pause");
	}
}

//2 
void cargar()               //Realizamos una funcion en donde se cargan los datos
{
    FILE *archivo;
    archivo=fopen("librostp.dat","a+b"); //  el modo de archivo es ab ya que abre un archivo par añadir datos          
    if (archivo==NULL)
	{
	      exit(1);
    }
    	datosLibreria dat;	
		char seguir;
		 do{   		//Pedimos los datos.
  			printf("Ingrese el titulo de los libros:\n");
     		fflush(stdin);
     		gets(dat.titulo);
     		if(strlen(dat.titulo)<MAX)  
     		{
				printf("Ingrese El autor del libro: \n");
	    		fflush(stdin);
				gets(dat.autor);
				if(strlen(dat.autor)<MAXIMO)
				{
				
		     		printf("Ingrese el editorial del libro: \n");
		     		fflush(stdin);
			 		gets(dat.editorial);
		     		printf("Ingrese la ubicacion de los libros (Sector - Pasillo - Estante): \n");
		    		fflush(stdin);
			 		gets(dat.ubicacion);
			 		printf("ingrese la cantidad de libros: \n");
			 		fflush(stdin);
			 		scanf("%i",&dat.cantidad);
		     		printf("Ingrese el Numero de estante donde ubicara el libro:\n");
		     		fflush(stdin);
			 		scanf("%i",&dat.estante);
			 		printf("Ingrese el estado del libro (Bueno/Malo/Regular):\n");
			 		fflush(stdin);
			 		gets(dat.estado);
					printf( "\n   Desea ingresar otro libro [S/N]?: " ); // preguntamos si desea seguir cargando datos 
		     		fflush( stdin );
		     		scanf( "%c", &seguir);
					fwrite(&dat, sizeof(datosLibreria), 1, archivo);		 			 
   				}else
   				{
   					printf("Ingrese un autor con menos de 50 digitos... \n");
   					system("pause");
				   }
		   
		   	}else
		   	
		   		{
		   			printf("ingrese un titulo con menos de 30 caracteres...\n ");
		   			system("pause");
			   	}
    }
	while(seguir == 's'|| seguir =='S'); //seguira cargando datos si colocamos la letra s 
	fclose(archivo);	//cerramos el archivo 
    
}
         
//3_
void modificacion() // creamos una funcion para modificar los datos
{ 
    FILE *archivo;
    archivo=fopen("librostp.dat","r+b"); // el modo de archivo es r+b ya que abre un archivo para operaciones de lectura escritura 
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el titulo del libro a modificar: \n");
    char auxiliar1[30];
    char respuesta[30];
    fflush(stdin);
    gets(auxiliar1);
    datosLibreria dat;
    int existe=0;                    
    fread(&dat, sizeof(datosLibreria), 1, archivo); //
    while(!feof(archivo))
    {
        if (strcmp(auxiliar1,dat.titulo)==0) // hacemos una comparacion entre el titulo que solicitamos cambiar con los que cargamos en el campo de la estructura 
        {   
			 printf("\t\t Titulo: %s \n ",dat.titulo);  //imprimimos los datos del libro 
	 		 printf("\t\t Autor: %s \n ",dat.autor);
	 		 printf("\t\t Editorial: %s \n ",dat.editorial);
	 		 printf("\t\t Ubicacion: %s \n ",dat.ubicacion);
	 		 printf("\t\t Estante: %i\n ",dat.estante);
	 		 
             printf("\n Elija los datos a modificar:\n "); // Preguntamos que solicita cambiar 
             fflush(stdin);
          
		  	//MODIFICACION DE TITULO
             printf("\n\t Titulo actual: %s\n", dat.titulo);  
			printf("\tDesea modificar el titulo del libro? [S/N]: ");
             gets(respuesta);
             if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			printf("\tNuevo titulo del libro: ");
			gets(dat.titulo);
			}
		   
		    //MODIFICACION DE AUTOR	
			printf("\n\t Autor actual: %s\n", dat.autor);
			printf("\tDesea modificar el autor del libro? [S/N]: ");
             gets(respuesta);
             if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			 printf("\tNuevo autor del libro: ");
		 	 gets(dat.autor);
			 }
			
			//MODIFICACION DE EDITORIAL
			printf("\n\t Editorial actual: %s\n", dat.editorial);
			printf("\tDesea modificar la editorial del libro? [S/N]: ");
             gets(respuesta);
             if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			 printf("\tNueva editorial del libro: ");
			 gets(dat.editorial);
			 }
			 
			 //MODIFICACION DE UBICACION
			printf("\n\t Ubicacion actual: %s\n", dat.ubicacion);
			printf("\tDesea modificar la ubicacion del libro? [S/N]: ");
             gets(respuesta);
             if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			 printf("\tNueva ubicacion del libro: ");
			 gets(dat.ubicacion);
			 }
			  //MODIFICACION DE CANTIDAD
			 printf("\n\t Cantidad actual: %i\n", dat.cantidad);
			printf("\tDesea modificar la cantidad? [S/N]: ");
             gets(respuesta);
             if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			 printf("\tNueva cantidad de libros: ");
			 scanf("%i",&dat.cantidad);
			 }
             
			 //MODIFICACION DE ESTANTE
			printf("\n\t Estante actual: %i\n", dat.estante);
			printf("\tDesea modificar el estante del libro? [S/N]: ");
             gets(respuesta);
             if (strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0) {
			 printf("\tNuevo estante del libro: ");
			 scanf("%i",&dat.estante);
			 }
    	     
    	     int pos=ftell(archivo)-sizeof(datosLibreria);
           	 fseek(archivo,pos,SEEK_SET);
             fwrite(&dat, sizeof(datosLibreria), 1, archivo); //Esta funcion sirve para escribir archivos binarios
             printf("Sus modificaciones fueron cargadas.\n"); 
             existe=1;
             break;
             
        }
        fread(&dat, sizeof(datosLibreria), 1, archivo); //Esta funcion sirve para leer el archivo.
    }
    if (existe==0) 
        printf("el libro no existe.\n");
    fclose(archivo); //Cerramos el archivo.
    system ("pause");
}

//4_
void bajas()
{
	
	 FILE *archivo;
     archivo=fopen("librostp.dat","r+b"); // el modo de archivo es r+b ya que abre un archivo para operaciones de lectura escritura 
     if (archivo==NULL)
        exit(1);
        char repite = 1;
        do{
     printf("Ingrese el titulo del libro a dar de baja: \n"); //Pide el titulo para dar de baja 
     char auxiliar2[30];
     char respuesta[30];
     fflush(stdin);
     gets(auxiliar2);
     datosLibreria dat;
     int existe=0;                    
     fread(&dat, sizeof(datosLibreria), 1, archivo); //Realzia la lectura de un archivo 
      while(!feof(archivo))
         {
             if (strcmp(auxiliar2,dat.titulo)==0) //Compara el titulo pedido con los datos del campo de la estructura. si Esto es cierto borra los datos.
             {  printf("BORRANDO DATOS DEL LIBRO...");
                strcpy(dat.titulo," ");
			    strcpy(dat.autor," ");
			    strcpy(dat.editorial," ");
			    strcpy(dat.ubicacion," ");
			    dat.cantidad=0;
			    dat.estante=0;
			    int pos=ftell(archivo)-sizeof(datosLibreria); 
           	    fseek(archivo,pos,SEEK_SET);
                fwrite(&dat, sizeof(datosLibreria), 1, archivo);
                printf("El libro se borro correctamente...");   
                existe=1;
	            break;
	         }
			 fread(&dat, sizeof(datosLibreria), 1, archivo);
			}
		   if (existe==0)
        		printf("el libro no existe.\n");
       			printf("\n\tDesea dar de baja otro libro? [S/N]: ");
				gets(respuesta);
 
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}
         }while(repite);
             fclose(archivo);
             system ("pause");
}
//6_
 void maximocantidad()
{
	
	
	struct datosLibreria auxiliarlibro[MAXIMO];
	struct datosLibreria auxiLibro;
	int contador=0,y,x,z;
	FILE *archivo;
	archivo=fopen("librostp.dat","rb");
	if (archivo==NULL)exit(1);
	fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
			{
    			auxiliarlibro[contador]=dat;
    			fread(&dat, sizeof(datosLibreria), 1, archivo);
        		contador=contador+1;
   		 	}
   		
   	
  			for( x=0; x<contador-1; x++)
			{
    			for(y=x+1; y<contador; y++)
				{
    			if(auxiliarlibro[x].cantidad<auxiliarlibro[y].cantidad)
						{
    						auxiLibro=auxiliarlibro[x];
    						auxiliarlibro[x]=auxiliarlibro[y];
    						auxiliarlibro[y]=auxiLibro;
						}
				}
			}
			for(z=0; z<contador; z++)
			{
    		printf("\ntitulo y autor : %s | %s \t Cantidad: %i\n", auxiliarlibro[z].titulo, auxiliarlibro[z].autor, auxiliarlibro[z].cantidad);
    		}
    		printf("\nMAXIMO: titulo y autor : %s| %s \t Cantidad: %i\n", auxiliarlibro[0].titulo, auxiliarlibro[0].autor, auxiliarlibro[0].cantidad);
    		printf("\nMINIMO: titulo y autor : %s| %s \t Cantidad: %i\n", auxiliarlibro[contador-1].titulo, auxiliarlibro[contador-1].autor, auxiliarlibro[contador-1].cantidad);
    		contador=0;
  			fclose(archivo);
  		 	system("PAUSE");
}
 
void maximoestante()
{
	struct datosLibreria auxiliarlibro[MAXIMO];
	struct datosLibreria auxiLibro;
	int contador=0,y,x,z;
	FILE *archivo;
	archivo=fopen("librostp.dat","rb");
	if (archivo==NULL)exit(1);
	fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
			{
    			auxiliarlibro[contador]=dat;
    			fread(&dat, sizeof(datosLibreria), 1, archivo);
        		contador=contador+1;
   		 	}
   		
   	
  			for( x=0; x<contador-1; x++)
			{
    			for(y=x+1; y<contador; y++)
				{
    			if(auxiliarlibro[x].estante<auxiliarlibro[y].estante)
						{
    						auxiLibro=auxiliarlibro[x];
    						auxiliarlibro[x]=auxiliarlibro[y];
    						auxiliarlibro[y]=auxiLibro;
						}
				}
			}
			for(z=0; z<contador; z++)
			{
    		printf("\nTitulo y Autor : %s | %s \t Estante: %i\n", auxiliarlibro[z].titulo, auxiliarlibro[z].autor, auxiliarlibro[z].estante);
    		}
    		printf("\nMAXIMO: Titulo y Autor : %s| %s \t Estante: %i\n", auxiliarlibro[0].titulo, auxiliarlibro[0].autor, auxiliarlibro[0].estante);
    		printf("\nMINIMO: Titulo y Autor : %s| %s \t Estante: %i\n", auxiliarlibro[contador-1].titulo, auxiliarlibro[contador-1].autor, auxiliarlibro[contador-1].estante);
    		contador=0;
  			fclose(archivo);
  		 	system("PAUSE");
}

 void minimoCantidad()
{
	
	
	struct datosLibreria auxiliarlibro[MAXIMO];
	struct datosLibreria auxiLibro;
	int contador=0,y,x,z;
	FILE *archivo;
	archivo=fopen("librostp.dat","rb");
	if (archivo==NULL)exit(1);
	fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
			{
    			auxiliarlibro[contador]=dat;
    			fread(&dat, sizeof(datosLibreria), 1, archivo);
        		contador=contador+1;
   		 	}
   		
   	
  			for( x=0; x<contador-1; x++)
			{
    			for(y=x+1; y<contador; y++)
				{
    			if(auxiliarlibro[x].cantidad>auxiliarlibro[y].cantidad)
						{
    						auxiLibro=auxiliarlibro[x];
    						auxiliarlibro[x]=auxiliarlibro[y];
    						auxiliarlibro[y]=auxiLibro;
						}
				}
			}
			for(z=0; z<contador; z++)
			{
    		printf("\ntitulo y autor : %s | %s \t Cantidad: %i\n", auxiliarlibro[z].titulo, auxiliarlibro[z].autor, auxiliarlibro[z].cantidad);
    		}
            printf("\nMINIMO: titulo y autor : %s| %s \t Cantidad: %i\n", auxiliarlibro[contador-1].titulo, auxiliarlibro[contador-1].autor, auxiliarlibro[contador-1].cantidad);
            printf("\nMAXIMO: titulo y autor : %s| %s \t Cantidad: %i\n", auxiliarlibro[0].titulo, auxiliarlibro[0].autor, auxiliarlibro[0].cantidad);
    		contador=0;
  			fclose(archivo);
  		 	system("PAUSE");
}

void minimoestante()
{
	struct datosLibreria auxiliarlibro[MAXIMO];
	struct datosLibreria auxiLibro;
	int contador=0,y,x,z;
	FILE *archivo;
	archivo=fopen("librostp.dat","rb");
	if (archivo==NULL)exit(1);
	fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
			{
    			auxiliarlibro[contador]=dat;
    			fread(&dat, sizeof(datosLibreria), 1, archivo);
        		contador=contador+1;
   		 	}
   		
   	
  			for( x=0; x<contador-1; x++)
			{
    			for(y=x+1; y<contador; y++)
				{
    			if(auxiliarlibro[x].estante>auxiliarlibro[y].estante)
						{
    						auxiLibro=auxiliarlibro[x];
    						auxiliarlibro[x]=auxiliarlibro[y];
    						auxiliarlibro[y]=auxiLibro;
						}
				}
			}
			for(z=0; z<contador; z++)
			{
    		printf("\nTitulo y Autor : %s | %s \t Estante: %i\n", auxiliarlibro[z].titulo, auxiliarlibro[z].autor, auxiliarlibro[z].estante);
    		}
    		printf("\nMINIMO: Titulo y Autor : %s| %s \t Estante: %i\n", auxiliarlibro[contador-1].titulo, auxiliarlibro[contador-1].autor, auxiliarlibro[contador-1].estante);
			printf("\nMAXIMO: Titulo y Autor : %s| %s \t Estante: %i\n", auxiliarlibro[0].titulo, auxiliarlibro[0].autor, auxiliarlibro[0].estante);
    		contador=0;
  			fclose(archivo);
  		 	system("PAUSE");
}
void ordenamientoabc()
{
	
	struct datosLibreria auxiliarlibro[MAXIMO];
	struct datosLibreria auxiLibro;
	int contador=0,y,x,z;
	FILE *archivo;
	archivo=fopen("librostp.dat","rb");
	if (archivo==NULL)exit(1);
	fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
			{
    			auxiliarlibro[contador]=dat;
    			fread(&dat, sizeof(datosLibreria), 1, archivo);
        		contador=contador+1;
   		 	}
   		
   	
  			for( x=0; x<contador-1; x++)
			{
    			for(y=x+1; y<contador; y++)
				{
    			if(auxiliarlibro[x].titulo<auxiliarlibro[y].titulo)
						{
    						auxiLibro=auxiliarlibro[x];
    						auxiliarlibro[x]=auxiliarlibro[y];
    						auxiliarlibro[y]=auxiLibro;
						}
				}
			}
			printf("\t\t\t Ordenamiento por titulo :\n");
			printf("\t TITULO \t\t\t AUTOR \t\t\t CANTIDAD\n ");
			for(z=0; z<contador; z++)
			{
    		printf("\n\t %s \t\t\t%s \t\t\t\t%i\n", auxiliarlibro[z].titulo, auxiliarlibro[z].autor, auxiliarlibro[z].cantidad);
    		}
    		contador=0;
  			fclose(archivo);
  		 	system("PAUSE");
}
void ordenamientoautor()
{
	
	struct datosLibreria auxiliarlibro[MAXIMO];
	struct datosLibreria auxiLibro;
	int contador=0,y,x,z;
	FILE *archivo;
	archivo=fopen("librostp.dat","rb");
	if (archivo==NULL)exit(1);
	fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
			{
    			auxiliarlibro[contador]=dat;
    			fread(&dat, sizeof(datosLibreria), 1, archivo);
        		contador=contador+1;
   		 	}
   		
   	
  			for( x=0; x<contador-1; x++)
			{
    			for(y=x+1; y<contador; y++)
				{
    			if(auxiliarlibro[x].autor<auxiliarlibro[y].autor)
						{
    						auxiLibro=auxiliarlibro[x];
    						auxiliarlibro[x]=auxiliarlibro[y];
    						auxiliarlibro[y]=auxiLibro;
						}
				}
			}
			printf("\t\t\t Ordenamiento por autor :\n");
			printf("\t AUTOR \t\t\t TITULO \t\t\t CANTIDAD\n ");
			for(z=0; z<contador; z++)
			{
    		printf("\n\t %s \t\t\t%s \t\t\t\t%i\n", auxiliarlibro[z].autor, auxiliarlibro[z].titulo, auxiliarlibro[z].cantidad);
    		}
           
    		contador=0;
  			fclose(archivo);
  		 	system("PAUSE");
}

void ordenamientoeditorial()
{
	
	struct datosLibreria auxiliarlibro[MAXIMO];
	struct datosLibreria auxiLibro;
	int contador=0,y,x,z;
	FILE *archivo;
	archivo=fopen("librostp.dat","rb");
	if (archivo==NULL)exit(1);
	fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
			{
    			auxiliarlibro[contador]=dat;
    			fread(&dat, sizeof(datosLibreria), 1, archivo);
        		contador=contador+1;
   		 	}
   		
   	
  			for( x=0; x<contador-1; x++)
			{
    			for(y=x+1; y<contador; y++)
				{
    			if(auxiliarlibro[x].editorial<auxiliarlibro[y].editorial)
						{
    						auxiLibro=auxiliarlibro[x];
    						auxiliarlibro[x]=auxiliarlibro[y];
    						auxiliarlibro[y]=auxiLibro;
						}
				}
			}
			printf("\t\t\t Ordenamiento por editorial :\n");
			printf("\t EDITORIAL \t\t\t TITULO \t\t\t AUTOR\n ");
			for(z=0; z<contador; z++)
			{
				
    		printf("\n\t %s \t\t\t%s \t\t\t\t%s\n", auxiliarlibro[z].editorial, auxiliarlibro[z].titulo, auxiliarlibro[z].autor);
    		}
           
    		contador=0;
  			fclose(archivo);
  		 	system("PAUSE");
}


void menumaxmin()
{

	char repite = 1;
	int opcion = -1;
	do{
		system("CLS");
		printf("\n===============================================================================================\n");
		printf("\t\t\t     *MENU DE ORDENAMIENTO* \n");
		printf("\t\t\t   INGRESE UNA OPCION DE ORDENAMIENTO: \n");

		 printf("\n===============================================================================================\n");	
		 printf("\t\t 1_ Maximo por cantidad: \n");
		 printf("\t\t 2_ Maximo por estante: \n");
		 printf("\t\t 3_ Minimo por cantidad: \n");
		 printf("\t\t 4_ Minimo por estante: \n");
		 printf("\t\t 5_ Ordenamiento por titulo : \n");
		 printf("\t\t 6_ Ordenamiento por autor : \n");
		 printf("\t\t 7_ Ordenamiento por editorial : \n");
		 printf("\t\t 8_ Salir al menu principal : \n");
		 option(linea, MAX);
	     sscanf(linea, "%d", &opcion);
	 switch(opcion)
	 {
		 	case 1: 
		 	system("CLS");
		 	maximocantidad();
		 		break;
		 	
		 	case 2:
		 		system("CLS");
		 		maximoestante();
		 		break;
		 		
		 		 case 3:
		 		 	system("CLS");
		 		 		minimoCantidad();
		 		    
		 		 	break;
		 		 	case 4:
		 		 		system("CLS");
	    						minimoestante();
		 		 		break;
	    					case 5:
	    						system("CLS");	
									  		ordenamientoabc();
		 		 	                    break;	 		 	
	                                       
	 								     case 6:
	 							        	system("CLS");
									         ordenamientoautor();	
									         break;
									  	case 7:
									  		     system("CLS");
									  			ordenamientoeditorial();
										         break;
										  		case 8:
									  			     repite = 0;
										              break;
										   	            
									  			
										  	
						
	 
	 
	 
	 }
	 		 	
	 }while(repite);
	
	
	
}
    

  


 
      
	   



			
//7_
void listado()
{

 FILE *archivo;
    archivo=fopen("librostp.dat","rb");
    if (archivo==NULL)
        exit(1);
    fread(&dat, sizeof(datosLibreria), 1, archivo);	
    
	while(!feof(archivo))
    {	
	 printf("\n Titulo: %s \n" ,dat.titulo); 
	 printf("Autor: %s \n ",dat.autor);
	 printf("Editorial: %s \n ",dat.editorial);
	 printf("Ubicacion: %s \n ",dat.ubicacion);
     printf("Cantidad: %i \n ",dat.cantidad);
 	 printf("Estante: %i\n ",dat.estante);
 	 printf("Estado: %s\n ",dat.estado);
     fread(&dat, sizeof(datosLibreria), 1, archivo);
     }
    fclose(archivo);
   system ("pause");
   
}
void consultatitulo()
{
    FILE *archivo;
    archivo=fopen("librostp.dat","rb");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el titulo del libro:\n");
    char auxiliar2[30];
    fflush(stdin);
    gets(auxiliar2);
     datosLibreria dat;
    int existe=0;
    fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(auxiliar2,dat.titulo)==0)
        {
            printf("Titulo: %s \n ",dat.titulo);
	 		printf("Autor: %s \n ",dat.autor);
	 		printf("editorial: %s \n ",dat.editorial);
	 		printf("Ubicacion: %s \n ",dat.ubicacion);
	 		printf("Estante: %i \n ",dat.estante);
	 		 printf("Estado: %s\n ",dat.estado);
   			existe=1;
             break;   
    		}
			fread(&dat, sizeof(datosLibreria), 1, archivo);           
        }
      
    if (existe==0)
        printf("No existe ese titulo\n");
    fclose(archivo);
    system ("pause");
}
  void consultaautor()
{
    FILE *archivo;
    archivo=fopen("librostp.dat","rb");
    if (archivo==NULL)exit(1);
    printf("Ingrese el autor del libro:\n");
    char auxiliar2[30];
    fflush(stdin);
    gets(auxiliar2);
     datosLibreria dat;
    int existe=0;
    while(!feof(archivo))
    {
    	fread(&dat, sizeof(datosLibreria), 1, archivo);
        	if (strcmp(auxiliar2,dat.autor)==0)
        	{
	
            	printf("Titulo: %s \n ",dat.titulo);
	 			printf("Autor: %s \n ",dat.autor);
	 			printf("editorial: %s \n ",dat.editorial);
	 			printf("Ubicacion: %s \n ",dat.ubicacion);
	 			printf("Estante: %i \n ",dat.estante);
	 			printf("Estado: %s\n ",dat.estado);
             	break;   
    		}
		          
        }
      
    if (existe==0)
        printf("No existe ese titulo\n");
    fclose(archivo);
    system ("pause");
}
void consultaeditorial()
{
    FILE *archivo;
    archivo=fopen("librostp.dat","rb");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese la editorial del libro:\n");
    char auxiliar2[30];
    fflush(stdin);
    gets(auxiliar2);
     datosLibreria dat;
    int existe=0;
    fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(auxiliar2,dat.editorial)==0)
        {
            printf("Titulo: %s \n ",dat.titulo);
	 		printf("Autor: %s \n ",dat.autor);
	 		printf("editorial: %s \n ",dat.editorial);
	 		printf("Ubicacion: %s \n ",dat.ubicacion);
	 		printf("Estante: %i \n ",dat.estante);
	 		 printf("Estado: %s\n ",dat.estado);
   			existe=1;
             break;   
    		}
			fread(&dat, sizeof(datosLibreria), 1, archivo);           
        }
      
    if (existe==0)
        printf("No existe ese titulo\n");
    fclose(archivo);
    system ("pause");
}
void consultaestado()
{
    FILE *archivo;
    archivo=fopen("librostp.dat","rb");
    if (archivo==NULL)
        exit(1);
    printf("Ingrese el estado del libro:\n");
    char auxiliar2[30];
    fflush(stdin);
    gets(auxiliar2);
     datosLibreria dat;
    int existe=0;
    fread(&dat, sizeof(datosLibreria), 1, archivo);
    while(!feof(archivo))
    {
        if (strcmp(auxiliar2,dat.estado)==0)
        {
            printf("Titulo: %s \n ",dat.titulo);
	 		printf("Autor: %s \n ",dat.autor);
	 		printf("editorial: %s \n ",dat.editorial);
	 		printf("Ubicacion: %s \n ",dat.ubicacion);
	 		printf("Estante: %i \n ",dat.estante);
	 		 printf("Estado: %s\n ",dat.estado);
   			existe=1;
             break;   
    		}
			fread(&dat, sizeof(datosLibreria), 1, archivo);           
        }
      
    if (existe==0)
        printf("No existe ese titulo\n");
    fclose(archivo);
    system ("pause");
}
void menua(){
char repite = 1;
int opcion = -1;
	do{
		system("CLS");
		printf("\n===============================================================================================\n");
		printf("\t\t\t     *MENU DE BUSQUEDA \n");
		printf("\t\t\t   INGRESE UNA OPCION DE BUSQUEDA: \n");

		 printf("\n===============================================================================================\n");	
		 printf("\t\t 1_ busqueda por titulo: \n");
		 printf("\t\t 2_ busqueda por autor: \n");
		 printf("\t\t 3_ busqueda por editorial: \n");
		 printf("\t\t 4_ busqueda por estado: \n");
		 printf("\t\t 5_ volver al menu principal: \n");
		 option(linea, MAX);
	     sscanf(linea, "%d", &opcion);
	 switch(opcion)
	 {
		 	case 1: 
		 	system("CLS");
		 	consultatitulo();
		 		break;
		 	
		 	case 2:
		 		system("CLS");
		 		consultaautor();
		 		break;
		 		
		 		 case 3:
		 		 	system("CLS");
		 		 	consultaeditorial();
		 		 	break;
		 		 	case 4:
		 		 		system("CLS");
		 		 		consultaestado();
		 		 		break;
		 		 	case 5:
		 		 			repite = 0;
						  break;
	 }
	 		 	
	 }while(repite);
}


//Programa principal:
main()
{
system("mode con: cols=96 lines=25"); //tamaño del recuadro del menu
	system("COLOR 0b"); //color
	gotoxy(24,5); //posicion de la linea de texto
    printf("=============================================\n");
	gotoxy(40,6);
	printf("G R U P O   E");
	gotoxy(37,7);
	printf("I N T R E G A N T E S\n");
	gotoxy(39,9);
	printf("PABLO ESPINOLA\n");
	gotoxy(39,10);
	printf("FERNANDO CENTENO\n");
	gotoxy(39,11);
	printf("HUGO BARRETO\n");
	gotoxy(39,12);
	printf("DIANA GALARZA SOTO\n");
	gotoxy(39,13);
	printf("MARCOS CORIA\n");
	gotoxy(24,14);
    printf("=============================================\n");
	gotoxy(27,16);
	system("pause"); 
	gotoxy(40,20);
	printf("CARGANDO ...");
	 
	for (int i= 6 ; i<=85 ; i++){       //for para que imprima el codigo ascii de una puta a la otra
			gotoxy(i,22); 
		printf("%c", 177); //es el codigo ASCII

	}
	for (int i= 6 ; i<=85 ; i++){
		gotoxy(i,22); 
		printf("%c", 219);//es el codigo ASCII
		Sleep(5); //para que el segundo codigo ASCII se ejecute cada 5 milisegundos
		
	}
	
gotoxy(3,20);
printf("                                                                                         "); //lineas en blanco para borrar 
gotoxy(3,22);
printf("                                                                                         "); //lineas en blanco para borrar 
 gotoxy(3,23);
 	system("pause");
 	
  menuPrincipal();

}