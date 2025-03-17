#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]){

	// say which file we are running mystat on
	char intro[256] = "File: ";
	strcat(strcat(intro, argv[1]),"\n");
	printf(intro);
	
	struct stat fileinfo;
	stat(argv[1], &fileinfo);
	printf("Size: %d\n", fileinfo.st_size);
	printf("Permissions: %o\n", fileinfo.st_mode);
	printf("Blocks: %o\n", fileinfo.st_blocks);
	printf("Links: %d\n", fileinfo.st_nlink);
	return 0;
}
