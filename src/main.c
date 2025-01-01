#include <stdio.h>

#include "resources/io.h"

#define MAX_PATH 1024

int main(void){
	char exePath[MAX_PATH] = {};
	char commandsPath[MAX_PATH] = {};
	// Debemos actualizar los comandos disponibles
	updateCommands(exePath, commandsPath);
	printf("%s\n", exePath);
	printf("%s\n", commandsPath);
	// Carga los comandos disponibles
	char ** commands = loadCommands(commandsPath);
	char * input = NULL;
	char ** argv = NULL;
	int argc = 0;
	// Ejecucion del programa
	while(1){
		printf("$ ");

		input = readInput(stdin);
		formatInput(input, &argc, &argv);
		// Si es que los comandos no son validos
		if(validateCommand(argv[0], commands) == 0){
			printf("Command not found: %s\n", input);
			continue;
		}
		// Si es que encuentra el comando
		//system(...);
	}
}