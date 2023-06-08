#include "lab.h"

int main() {
	int size = 0;
	char ch;
	char* args = (char*)malloc(sizeof(char));
	printf("Enter string:");
	while ((ch = getchar()) != '\n'){
		args[size++] = ch;
		args = (char*)realloc(args, size + 1);
		//printf("(%c) ", ch);
	}
	args[size] = '\0';
	//printf("%s \n", args);
	//return 0;
	int argc = 0;
	char** argv = (char**)malloc(sizeof(char**));
	argssplit(args, &argc, argv);
	printf("%d \n", argc);
	//return 0;
	for (int i = 0; i < argc; i++){
		int j = 0; 
		while ((*argv[j] <= 'Z') && (*argv[j] >= 'A') || (*argv[j] <= 'z') && (*argv[j] >= 'a')) {
			printf("%c", *argv[j]);
			j++;
		}
		*argv++;
	}

	/*int size = 0;
	char ch;
	char* args = (char*)malloc(sizeof(char));
	printf("Enter string:");
	while ((ch = getchar()) != '\n'){
		args[size++] = ch;
		args = (char*)realloc(args, size + 1);
	}
	args[size] = '\0';
	int argc = 0;
	char** argv = (char**)malloc(1);
	argssplit(args, &argc, argv);
	printf("%d \n", argc);
	for (int i = 0; i < argc; i++)
		printf("%s\n", argv[i]);*/
	return 0;
}