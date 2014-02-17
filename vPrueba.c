/*
6. Realice un programa de prueba que llame automáticamente el programa anterior pero con diferentes vectores de prueba.
Dicho programa deberá leer la salida producida con cada vector de prueba y comprobar que el resultado es correcto.
Los vectores de prueba deberán estar almacenados en un archivo.

7. Corra el programa de prueba de así:
$./programa_prueba nombre_programa archivo_vectores_prueba

8. Imprima el resultado de cada vector indicando si pasó o no pasó.

9. Los vectores de prueba deberán ser almacenados por líneas, así:

numero_hilos cantidad_tiempo_a_correr numero_cuentas valor_inicial CANTIDAD_DE_REPETICIONES_DE_ESTE_VECTOR 

El parámetro CANTIDAD_DE_REPETICIONES_DE_ESTE_VECTOR indica la cantidad de veces que se deberá repetir este vector.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

int main(int argc, char*argv[])
{
	FILE *archivo;
	char vector[180];
	archivo=fopen(argv[1],"r");
	char *parametros[20];
	char *valor;
	pid_t hijo;
	int j=0;
	int z=0;
	int status;

	while(fgets(vector,180,archivo)!=NULL)
	{
		int i=0;
		int repeticiones=0;
	
		valor = strtok(vector," ");
		parametros[i]="./tranferencia.exe";
		parametros[i+1]=valor;
		parametros[i+2]=strtok(NULL," ");
		parametros[i+3]=strtok(NULL," ");
		parametros[i+4]=strtok(NULL," ");
		repeticiones = atoi(strtok(NULL," "));
		parametros[i+5]=NULL;
		
		for(j=0;j<repeticiones;j++)
		{
			hijo=fork();
			if(hijo==0)
			{
				execvp("./tranferencia.exe",parametros);//llamado al segundo programa
				exit(1);
			}
		}
		for(z=0;z<repeticiones;z++)
		{
			wait(&status);
		}
		
	}
	return 0;
	
}
