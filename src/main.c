#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resources/io.h"
#include "resources/setup.h"
#include "resources/Command.h"

#define MAX_BUFFER 1024

int main(void){
	/*
	 * Nota: Sería bueno una función que lea los comandos disponibles desde el
	 * mismo directorio y luego actualice el archivo. Aunque podría ser
	 * inclusive un comando tipo upt_cmds.exe
	 * Nota: Actualizar a futuro, en lugar de usar Command **, usar void *
	 * con un árbol o alguna estructura para árboles.
	 */
	// Abrimos el archivo que contiene los comandos
	const char commandsPath[] = "../data/commands.csv";
	// Debemos leer los comandos disponibles
	Command * commands_csv = NULL;
	size_t commands_csv_size;
	if((commands_csv_size = loadCommands(commandsPath, &commands_csv)) == -1){
		printf("An error ocurred while loading commands from file in %s\n",
			commandsPath);
		exit(1);
	}
	// Varaibles para las entradas
	char * input = NULL;
	char ** argv = NULL;
	int argc = 0, index;
	// Ejecucion del programa
	while(1){
		// Solo para indicar una nueva lectura
		printf("$ ");
		// Obtener la entrada del usuario
		input = readInput(stdin);
		if(strcmp(input, "exit") == 0) exit(0);
		// Darle el formto necesario a la entrada
		formatInput(input, &argc, &argv);
		// Buscar el comando en la lista, y verificar que los sea valido
		if((index = validateCommand(argv[0], commands_csv)) == -1){
			printf("Command not found: %s\n", input);
			printf("To update the command list use upt_cmd\n");
			continue;
		}
		// Ejecutar el comando -> Acá liberamos tambien la memoria de argv
		executeCommand(&commands_csv[index], argc, argv);
		// Liberación de la memoria
		free(input);
	}
}