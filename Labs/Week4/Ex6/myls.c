#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <linux/limits.h>

int main(int argc, char *argv[]){
		
	//no directory argument, no flag given
	if(argc == 1){
		char cwd[PATH_MAX];
		getcwd(cwd, sizeof(cwd));
		printf(cwd);
		DIR *dir = opendir(cwd);
		if(dir == NULL) {
			printf("myls with %s failed\n",argv[1]);
			return(1);
		}

		struct dirent *entry;
		while((entry = readdir(dir)) != NULL) {
			printf("%s\n",entry->d_name);
		}

		closedir(dir);
		return(0);
	}
	
	
	if(argc == 2){
		//flag argument given
		if(strcmp(argv[1],"-l") == 0){
			char cwd[PATH_MAX];
			getcwd(cwd, sizeof(cwd));
			printf("long ls done on %s", cwd);
			return(0);
		}
		//directory argument given
		else{
			printf(argv[1]);
			DIR *dir = opendir(argv[1]);
			if(dir == NULL) {
				printf("myls with %s failed\n",argv[1]);
				return(1);
			}

			struct dirent *entry;
			while((entry = readdir(dir)) != NULL){
			printf("%s\n",entry->d_name);
			}

			closedir(dir);
			return(0);
		}
	}
	// flag and directory argument given
	if (argc == 3){
		printf("running long ls on given directory");
	}
	
	// say which file we are running mystat on
	/*char intro[256] = "File: ";
	strcat(strcat(intro, argv[1]),"\n");
	printf(intro);
	
	struct stat fileinfo;
	stat(argv[1], &fileinfo);
	printf("Size: %d\n", fileinfo.st_size);
	printf("Permissions: %o\n", fileinfo.st_mode);
	printf("Blocks: %o\n", fileinfo.st_blocks);
	printf("Links: %d\n", fileinfo.st_nlink);
	return 0;*/
}
