#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	
	//open file
	int fd;
	fd = open("input.txt", O_RDONLY);
	
	//read from file
	read(fd, input, strlen(input));
	
	//print to terminal
	printf("Your input has been written to output.txt");
	
	//close file
	close(fd);
	
	return 0;
}
