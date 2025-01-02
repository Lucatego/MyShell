#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Command.h"

#include "setup.h"

#define MAX_SIZE 1024
#define AVG_SIZE 10
#define EXE_PATH 0
#define COMMAND_NAME 1

/*
 * Carga de los comandos a través del archivo en la carpeta data
 * @param
 */
size_t loadCommands(const char * commandsPath, Command ** commands_csv){
	// Apertura del archivo
	FILE * file;
	if((file = fopen(commandsPath, "r")) == NULL){
		printf("Unable to open file in %s\n", commandsPath);
		exit(1);
	};
	// Inicio
	char *** rowsTemp = (char ***) malloc(AVG_SIZE * sizeof(char **));
	size_t size = 0;
	char * exe_path = NULL, * command_name = NULL;
	char buffer[MAX_SIZE];
	// Descartamos la cabezera
	if(fgets(buffer, MAX_SIZE, file) == NULL) return -1;
	// Lectura del archivo
	while(1){
		// Nota: Falta validar el caso cuando la fila del csv sea mayor a 1024
		if(fgets(buffer, MAX_SIZE, file) == NULL) break;
		// Lectura de las cadenas
		exe_path = strtok(buffer, ",");
		command_name = strtok(NULL, ",");
		if(exe_path == NULL || command_name == NULL) return -1;
		// Guardamos los comandos
		saveCommand(&rowsTemp[size], exe_path, command_name);
		// Contamos los comandos
		if(++size == AVG_SIZE){

		}
	}
	// Fin
	rowToCommand(commands_csv, rowsTemp, size);
	fclose(file);
	return size;
}

void saveCommand(char *** row, char * exe_path, char * command_name){
	(*row) = (char **) malloc(2 * sizeof(char **));
	(*row)[EXE_PATH] = exe_path;
	(*row)[COMMAND_NAME] = command_name;
}

void rowToCommand(Command ** commands_csv, char *** rows, size_t size){
	if(size == 0) return;
	// Segun la cantidad de comandos leidos
	(*commands_csv) = (Command *) malloc(size * sizeof(Command *));
	// Una iteración
	for(int i = 0; i < size; i++){
		(*commands_csv)[i].command_name = rows[i][COMMAND_NAME];
		(*commands_csv)[i].exe_path = rows[i][EXE_PATH];
	}
}

int validateCommand(const char * command, const Command * commands_csv){
	int index = -1;
	return index;
}

void executeCommand(const Command * command_row, int argc, char ** argv){

}