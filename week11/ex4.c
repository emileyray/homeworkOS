#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main()
{	
	int source = open("ex1.txt", O_RDONLY);

	int filesize = lseek(source, 0, SEEK_END);
	
	char *src_map = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, source, 0);
	
	int dest = open("ex1.memcpy.txt", O_RDWR | O_CREAT, (mode_t)0666);

	ftruncate(dest, filesize);	// truncate it to exactly this size
	char *dest_map = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, dest, 0);
	
	// Copying from string to the map
	memcpy(dest_map, src_map, filesize);
	
	// Writing to the disk
	msync(dest_map, filesize, MS_SYNC);
	
	// Removing the mappings
	munmap(src_map, filesize); 
	munmap(dest_map, filesize);

	close(source);
	close(dest);
	return 0;
}