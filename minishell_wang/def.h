#ifndef _DEF_H_
#define _DEF_H_
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024//命令行最长长度	
#define MAXARG 20		//命令最多的参数个数
#define PIPELINE 5		//命令最多支持的管道个数

typedef struct command
{
	char *args[MAXARG+1];	//命令的参数列表，多个NULL结束
} COMMAND;

/*
char *string="1234";
*string=1 stirng[0]
*(string+1)=2 string[1]
*(string+2)=3 string[2]
string=1234
*/




#endif /* _DEF_H_ */
