#include <stdio.h>
#include <unistd.h>

int main()
{
	char text[7] = "Hello\n";
	
	setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	
	for(int i=0; i<6; i++)
	{
		printf("%c", text[i]);
		sleep(1);
	}
	return 0;
}