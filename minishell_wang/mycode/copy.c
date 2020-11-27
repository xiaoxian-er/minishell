#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#define BUFF_SIZE 4096
#define COPY_MODE 0644
 
void oops(char * s1, char * s2);
 
int main(int ac, char **av)
{
	int  in_fd, out_fd, n_chars;
	char buf[BUFF_SIZE];
 
	/* check args */
	if( ac != 3)  // must three parameters
	{
		fprintf(stderr, "usage: %s source destination\n", *av);
	}
 
	/* open files */
	if( (in_fd = open(av[1], O_RDONLY)) == -1)
	{
		oops("Cannot open ", av[1]);
	}
 
	if( (out_fd = creat(av[2], COPY_MODE)) == -1 )
	{
		oops("Cannot creat ", av[2]);		
	}
 
	/* copy files */
	while( (n_chars = read(in_fd, buf, BUFF_SIZE)) > 0 )
	{
		if(write(out_fd, buf, n_chars) != n_chars )
		{
			oops("Write error from ", av[1]);
		}
	}
 
	if( n_chars == -1 )
	{
		oops("Read error from ", av[1]);
	}
 
	/* close files */
	if(close(in_fd) == -1 || close(out_fd) == -1)
	{
		oops("Error closing files", "");
	}
 
	return 0;
}
 
/**
* abnormal information
*/
void oops(char *s1, char *s2)
{
	fprintf(stderr, "Error: %s ", s1);
	perror(s2);
	exit(1);
}
