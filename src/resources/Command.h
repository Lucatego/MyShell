#ifndef COMMAND_H
#define COMMAND_H

typedef struct Command{
	char * exe_path;
	char * command_name;
	unsigned long long exe_path_len;
	unsigned long long command_name_len;
} Command;

#endif //COMMAND_H
