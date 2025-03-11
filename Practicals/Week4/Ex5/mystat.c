#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
	struct stat * buf;
	printf("hello world!");
	stat("test.txt", buf);
}
