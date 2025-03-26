#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main(){
	//get user input
	char input[50];
	printf("To Write To File: ");
	fgets(input, sizeof(input), stdin);
	
	//open file
	int fd;
	fd = open("output.txt", O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR, S_IWUSR);
	
	//write to file
	write(fd, input, strlen(input));
	printf("Your input has been written to output.txt");
	
	//close file
	close(fd);
	
	//change file to read only
	chmod("output.txt", S_IRUSR|S_IRGRP|S_IROTH);
	
	return 0;
}
