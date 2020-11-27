#include "parse.h"
#include "externs.h"
#include "init.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void command_print(){
	int i=0;
	while(cmd.args[i]!=NULL){
		printf("[%s] ",cmd.args[i]);
		i++;
	}
	
	printf("\n");
}

/*
 * shell主循环
 */
void shell_loop(void)
{
	while (1)
	{
		printf("[minishell]$ ");
		fflush(stdout);//刷新流
		init();//初始化
		if (read_command() == -1)
			break;
		parse_command();//解析命令
		//command_print();//打印命令
		execute_command();//执行命令
	}
	
	printf("\nexit\n");
}

/*
 * 读取命令
 * 成功返回0，失败或读取到(EOF)返回-1
 */
int read_command(void)
{
	if (fgets(cmdline, MAXLINE, stdin) == NULL)
		return -1;
	return 0;
}

/*
 * 解析命令
 * 成功返回0
 */
int parse_command(void)
{
	/* ls -l */
	/* ls\0-l\0 */

	char* cp = cmdline;
	char* avp = avline;
	int i = 0;

	while (*cp != '\0')
	{
		/*遇到空格和制表符跳过  */
		while (*cp == ' ' || *cp == '\t')
		cp++;
		/* 遇到字符串结束和\n结束循环 */
		if (*cp == '\0' || *cp == '\n')
			break;
		//printf("%s\n",avp);
		cmd.args[i] = avp;//这里是把地址传了过去，所以对avp的改变就是就是对acdd.args的改变
		//printf("%s\n",cmd.args[i]);

		/* 解析命令 */
		while (*cp != '\0'
			&& *cp != ' '
			&& *cp != '\t'
			&& *cp != '\n')
			*avp++ = *cp++;
		*avp++ = '\0';//添加字符窜结束表示
		//printf("%d : [%s]\n",i, cmd.args[i]);
		i++;
	}

	return 0;
}

/*
 * ִ执行命令
 *成功返回0 
 */
int execute_command(void)
{
	if(cmd.args[0]==NULL)
		return 0;
	pid_t pid = fork();
	if (pid == -1)
		fprintf(stderr,"fork failed");

	
	char path[128]="/home/wang/minishell_wang/mycode/";
	//printf("[%s]\n",cmd.args[0]);
	strncat(path,cmd.args[0],50);
	//strcpy(cmd.args[0],path);
	//printf("[%s]\n",path);
	if (pid == 0){
	execv(path,cmd.args);
	//printf("1111\n");
}	
	wait(NULL);
	return 0;
}
