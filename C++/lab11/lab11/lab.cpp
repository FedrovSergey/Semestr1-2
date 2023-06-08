#include "lab.h"

void argssplit(char* args, int* argc, char* argv[]) {
	int i = 0, j = 0;
	if (((args[i] <= 'Z') && (args[i] >= 'A') || (args[i] <= 'z') && (args[i] >= 'a'))) {
		argv = (char**)realloc(argv, j * sizeof(char*) + sizeof(char*));
		argv[j++] = args;
	}

	while (args[i + 1] != '\0') {
		if (((args[i] <= 'A') || (args[i] >= 'Z') && (args[i] <= 'a') || (args[i] >= 'z')) && ((args[i + 1] <= 'Z') && (args[i + 1] >= 'A') || (args[i + 1] <= 'z') && (args[i + 1] >= 'a'))) {
			argv = (char**)realloc(argv, j * sizeof(char*) + sizeof(char*) * 2);
			argv[j++] = &args[i + 1];
		}
		i++;
	}
	*argc = j;
	/*if (args[0] != ' ') {
		argv = (char**)realloc(argv, *argc * sizeof(char*) + sizeof(char*));
		argv[*argc++] = args;
	}
	for (int i = 0; i < args[i] != 0; i++){
		if (args[i] == ' ' && args[i + 1] != ' '){
			argv = (char**)realloc(argv, *argc * sizeof(char*) + sizeof(char*));
			argv[*argc++] = (args + i + 1);
		}
	}*/
}

/*
void printArray(char* args) {
	int i = 0;
	while (args[i] != '\0') {
		printf("%c", args[i++]);
	}
}*/