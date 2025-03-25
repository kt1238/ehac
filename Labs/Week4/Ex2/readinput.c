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
	char buffer[256];
	ssize_t bytes_read;
	
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) { //while bytes_read is > 0
		//print to terminal
		write(STDOUT_FILENO, buffer, bytes_read);
	}
	
	//close file
	close(fd);
	
	return 0;
}
