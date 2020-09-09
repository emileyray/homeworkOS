#include <stdio.h>
#include <unistd.h>
int main() {

	// for each new process PID is increased by 1
	// fork() returns the PID of the child process and if it's a child it returns 0;
	// getpid() returns the PID of the process

	int n = fork();
	char *processName;
	if (n == 0) processName = "child";
	else processName = "parent";
	printf("Hello from %s [%d - %d]\n", processName, getpid(), n);
	return 0;
}
