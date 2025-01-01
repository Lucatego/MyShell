#ifndef IO_H
#define IO_H

void updateCommands(char * exePath, char * commandsPath);
char ** loadCommands(const char * path);
char * readInput(FILE * fp);

#endif /*IO_H*/