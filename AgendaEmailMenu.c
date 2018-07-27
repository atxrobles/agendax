/* Hacer un programa en C que agende contactos y tenga un menu con los siguientes
 * elementos:
 * Crear un nuevo archivo y añadir contactos.
 * Añadir mas contactos a un archivo existente
 * Visualizar un archivo con cotactos */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 30

int existente(char opc_datos);
int a_nuevo(char opc_datos);
int visualizar();

struct info_datos{
	char nombre[TAM];
	char apellido[TAM];
	char institucion[TAM + 5];
	char celular[TAM - 15];
	char email[TAM + 10];
}datos;

FILE *fd;

int a_nuevo(char opc_datos){
	char direccion[70];

	printf("Direccion del nuevo archivo: ");scanf("%[^\n]", &direccion);

	fd = fopen(direccion, "wt");

	if(fd == NULL){
		printf("Error: No se pudo crear el archivo");
		return 1;
	}

	fprintf(fd, "\n\t\tAGENDA DE CONTACTOS\n");

	do{
		while(getchar() != '\n');
		printf("\nNombre: ");scanf("%[^\n]", datos.nombre);
		while(getchar() != '\n');
		fprintf(fd, "\n\nNombre: ");
		fwrite(datos.nombre, 1, strlen(datos.nombre), fd);

		printf("\nApellido: ");scanf("%[^\n]", &datos.apellido);
		while(getchar() != '\n');
		fprintf(fd, "\nApellido: ");
		fwrite(datos.apellido, 1, strlen(datos.apellido), fd);

		printf("\nInstitución: ");scanf("%[^\n]", &datos.institucion);
		while(getchar() != '\n');
		fprintf(fd, "\nInstitución: ");
		fwrite(datos.institucion, 1, strlen(datos.institucion), fd);

		printf("\nCelular: ");scanf("%s", &datos.celular);
		while(getchar() != '\n');
		fprintf(fd, "\nCelular: ");
		fwrite(datos.celular, 1, strlen(datos.celular), fd);


		printf("\nE-mail:");scanf("%s", &datos.email);
		while(getchar() != '\n');
		fprintf(fd,"\nE-mail: ");
		fwrite(datos.email, 1, strlen(datos.email), fd);

		printf("\nAñadir un contacto mas (s): ");scanf("%c", &opc_datos);
	}while(opc_datos == 's' || opc_datos == 'S');

	fclose(fd);
}

int existente(char opc_datos){
	char direccion[70];

	printf("Direccion del archivo existente: ");scanf("%[^\n]", &direccion);

	fd = fopen(direccion, "at");

	if(fd == NULL){
		printf("Error: Archivo no encontrado");
		return 1;
	}

	do{
		while(getchar() != '\n');
		printf("\nNombre: ");scanf("%[^\n]", &datos.nombre);
		while(getchar() != '\n');
		fprintf(fd, "\n\nNombre: ");
		fwrite(datos.nombre, 1, strlen(datos.nombre), fd);

		printf("\nApellido: ");scanf("%[^\n]", &datos.apellido);
		while(getchar() != '\n');
		fprintf(fd, "\nApellido: ");
		fwrite(datos.apellido, 1, strlen(datos.apellido), fd);

		printf("\nInstitucion: ");scanf("%[^\n]", &datos.institucion);
		while(getchar() != '\n');
		fprintf(fd, "\nInstitución: ");
		fwrite(datos.institucion, 1, strlen(datos.institucion), fd);

		printf("\nCelular: ");scanf("%[^\n]", &datos.celular);
		while(getchar() != '\n');
		fprintf(fd, "\nCelular: ");
		fwrite(datos.celular, 1, strlen(datos.celular), fd);

		printf("\nE-mail: ");scanf("%s", &datos.email);
		while(getchar() != '\n');
		fprintf(fd, "\nE-mail: ");
		fwrite(datos.email, 1, strlen(datos.email), fd);

		printf("\nAgregar un contacto mas (s): ");scanf("%c", &opc_datos);
	}while(opc_datos == 's' || opc_datos == 'S');

	fclose(fd);
}

int visualizar(){
	int c;
	char direccion[70];

	printf("Direccion del archivo: ");scanf("%[^\n]", &direccion);

	fd = fopen(direccion, "r");

	if(fd == NULL){
		printf("Error: Archivo no encontrado");
		return 1;
	}

	while((c = fgetc(fd)) != EOF){
		if(c == '\n'){
			printf("\n");
		}
		else{
			putchar(c);
		}
	}

	fclose(fd);
}

int main(){
	int opc_menu;
	char opc_datos;

	system("clear");

	printf("\n\t\tAGENDA DE CONTACTOS\n");

	do{
		printf("\n\t\tMENU\n");
		printf("\n1. Nuevo archivo\n2. Añadir mas contactos a un archivo existente\n");
		printf("3. Visualizar mi agenda\n4. Salir");
		printf("\nOpcion: ");scanf("%i", &opc_menu);
		while(getchar() != '\n');

		switch(opc_menu){
			case 1: a_nuevo(opc_datos); break;
			case 2:	existente(opc_datos); break;
			case 3: visualizar(); break;
			default: break;
		}
	}while(opc_menu != 4);

	return 0;
}
