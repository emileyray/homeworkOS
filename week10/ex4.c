#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

struct file
{
	unsigned long inode;
	char filenames[10][10];
	int file_count;
};

int main()
{
	DIR *dir = opendir("./tmp");
	dirent *entry;
	
	struct file files[10];
	int file_count = 0;
	for(int i=0; i<10; i++)
	{
		files[i].inode = 0;
		files[i].file_count = 0;
	}
	
	while((entry = readdir(dir)) != NULL)
	{
		if(entry->d_name[0] == '.') continue;
		
		struct stat s = {};
		char dirname[14] = "tmp/";

		int found = 0;
		for(int i=0; i<10; i++)
		{
			if(files[i].inode == s.st_ino)
			{
				strncpy(files[i].filenames[files[i].file_count], entry->d_name, 10);
				files[i].inode = s.st_ino;
				files[i].file_count++;
				found = 1;
				break;
			}
		}
		if(found == 0)
		{
			files[file_count].inode = s.st_ino;
			strncpy(files[file_count].filenames[0], entry->d_name, 10);
			files[file_count].file_count++;
			file_count++;
		}
	}
	closedir(dir);
	
	printf("Found %d files with more than 2 hard links:\n", file_count);
	for(int i=0; i<file_count; i++)
	{
		printf("I-node: %lu (%d files)\n", files[i].inode, files[i].file_count);
		for(int j=0; j<files[i].file_count; j++)
		{
			printf("\t%s\n", files[i].filenames[j]);
		}
		printf("\n");
	}
	
	return 0;
}