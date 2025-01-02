#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"

#define INPUT_SIZE 128

/*
 * Lectura de una archivo, para generar una cadena de tamaño indefinido
 * @param FILE * fp: Puntero al archivo por leer
 */
char * readInput(FILE * fp){
    // Variables para la lectura (Memoria dinamica)
    char * input = NULL, buff[INPUT_SIZE] = {};
    size_t inputLen = 0, buffLen = 0;
    // Lectura en bucle del archivo
    while(1){
        // Lectura del archivo por partes en un buffer, si llega a EOF -> break;
        if(fgets(buff, INPUT_SIZE, fp) == NULL) break;
        buffLen = strlen(buff);
        // Alojamos en memoria las nuevas partes de la cadena
        char * tempInput = realloc(input, inputLen + buffLen + 1);
        if(tempInput == NULL){
            free(input);
            printf("Fatal error: Could not read the input string\n");
            return NULL;
        }
        input = tempInput;
        //Ahora copiamos la cadena al buffer principal
        strcpy(input + inputLen, buff);
        inputLen += buffLen;
        /* 
         * Validaciones para la finalizacion de la entrada
         * 1. Validamos que la lectura del buffer sea menor al maximo posible, 
         * es decir, ya no hay nada más que leer.
         * 2. Si hay un cambio de linea, entonces dejamos de leer
         */
        if(buffLen < INPUT_SIZE - 1 || buff[buffLen - 1] == '\n') break;
    }
    // Retorno de la cadena
    return input;
}

/*
 * Transforma el input en las entradas clasicas de argc y argv.
 * @param const char * input: La entrada
 * @param int * argc: La cantidad de palabras.
 * @param char *** argv: Arreglo de palabras para ser creado
 */
void formatInput(const char * input, int * argc, char *** argv){

}

int validateCommand(const char * input, const char ** comands){
	int idx = -1;
	return idx;
}