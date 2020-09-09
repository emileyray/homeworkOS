#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char command[50];
	printf("Type \"exit\" to exit the program or any other command\n");
	while(strcmp(command, "exit"))
	{
		printf("> ");
		scanf("%50s", command);
		system(command);
	}
	return 0;
}