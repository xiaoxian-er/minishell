#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
 
int main(int argc,char *argv[]) 
{
	if(argc != 2)
	{
		printf("mkdir:argc error\n");
		exit(0);
	}
	
	if(mkdir(argv[1],O_CREAT|0600) == -1)
	{
		perror("mkdir error");
	}
	
	exit(0);
}
