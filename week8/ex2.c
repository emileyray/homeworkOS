#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*
	procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
	 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
	 0  0      0 10159672 247972 3147816    0    0   109   137  504 1682 10  5 86  0  0
	 0  0      0 10157364 247972 3150304    0    0     0   236 1183 2753  1  1 97  0  0
	 3  0      0 10159144 247972 3148224    0    0     0     0  857 2159  1  1 99  0  0
	 3  0      0 10159316 247972 3148040    0    0     0    12  965 2204  1  1 98  0  0
	 0  0      0 10159284 247972 3148040    0    0     0     0  964 2185  1  0 98  0  0
	 0  0      0 10159032 247972 3148000    0    0     0     0  962 2224  1  1 98  0  0
	 0  0      0 10159000 247980 3148000    0    0     0    56  865 2210  1  1 99  0  0
	 0  0      0 10159000 247980 3148000    0    0     0     0  838 2142  1  0 99  0  0
	 0  0      0 10159000 247980 3148000    0    0     0     0  858 2152  1  1 98  0  0
	 0  0      0 10158936 247980 3148000    0    0     0     0  892 2141  1  1 98  0  0
*/

int main()
{
	int *data = NULL;
	size_t size = 0;
	for(int i=0; i<10; i++)
	{
		size += 10*1024*1024;
		data = realloc(data, size);
		if(data == NULL)
		{
			printf("Error!\n");
			exit(1);
		}
		memset(data, 0, size);
		// printf("Have %ld MB of memory!\n", size / (1024*1024));
		sleep(1);
	}
	
	free(data);
	
	return 0;
}