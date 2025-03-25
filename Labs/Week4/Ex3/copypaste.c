#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	
	//open file
	int fd1, fd2;
	fd1 = open("source.txt", O_RDONLY);
	fd2 = open("destination.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR, S_IWUSR);
	
	//read from source.txt
	char buffer[256];
	ssize_t bytes_read;
	
	while ((bytes_read = read(fd1, buffer, sizeof(buffer))) > 0) { //while bytes_read is > 0
		//write to destination.txt
		write(fd2, buffer, bytes_read);
	}
	
	//close files
	close(fd1);
	close(fd2);
	
	return 0;
}
