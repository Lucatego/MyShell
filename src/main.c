#include <stdio.h>

#include "resources/io.h"

int main(void){
	char * input = NULL;

	while(1){
		printf("$ ");

		input = readInput(stdin);

		printf("Command not found: %s\n", input);
	}

}