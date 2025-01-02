#ifndef COMMAND_H
#define COMMAND_H

typedef struct Command{
	char * exe_path;
	char * file_name;
	char * command_name;
	unsigned long long exe_path_len;
	unsigned long long file_name_len;
	unsigned long long command_name_len;
} Command;

#endif //COMMAND_H
