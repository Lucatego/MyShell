#ifndef IO_H
#define IO_H

void formatInput(const char * input, int * argc, char *** argv);

char * readInput(FILE * fp);

int validateCommand(const char * input, const char ** comands);

#endif /*IO_H*/