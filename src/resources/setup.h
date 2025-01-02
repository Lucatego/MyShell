#ifndef SETUP_H
#define SETUP_H

#include "Command.h"

void executeCommand(const Command * command_row, int argc, char ** argv);
void saveCommand(char *** row, char * exe_path, char * command_name);
void rowToCommand(Command ** commands_csv, char *** rows, size_t size);

int validateCommand(const char * command, const Command * commands_csv);

size_t loadCommands(const char * commandsPath, Command ** commands_csv);

#endif //SETUP_H
