#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
	int file = open("ex1.txt", O_RDWR | O_CREAT, (mode_t)0600);

	char text[19] = "This is a nice day";

	// Changing the size
	(lseek(file, 18, SEEK_SET);

	// Writing to get the file to the new size
	write(file, "", 1);

    	char *map = mmap(0, 18 PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);

	// Copying from string to the map
	memcpy(map, text, 18);

	// Writing to the disk
	msync(map, 18, MS_SYNC);

	// Removing the mapping
	munmap(map, 18);

	printf("Successfully done!\n");
	close(file);
	return 0;
}