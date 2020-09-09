#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	// Each process gets forked into two, so if we foork N times, we get N^2 processes
	// for N=3 it's 8, and for N=5, it's 32


	for (int i = 0; i < 5; i++){
		fork();	
	}
	sleep(5);
	return 0;	
}
