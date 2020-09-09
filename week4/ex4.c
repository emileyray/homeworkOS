#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char command[50];
	printf("Type command \"exit\" to exit the program or use another command\n");
	while(strcmp(command, "exit\n"))
	{
		fgets(command, 50, stdin);
		if (fork() == 0) {
			system(command);
			break;
		}
	}
	return 0;
}
