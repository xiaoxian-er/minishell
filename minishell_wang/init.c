#include "init.h"
#include "externs.h"
#include <stdio.h>
#include <signal.h>
#include <string.h>

void sigint_handler(int sig);

//信号的控制
void setup(void)
{
	signal(SIGINT, sigint_handler);
	//signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

//ctrl+c的作用
void sigint_handler(int sig)
{
	printf("\n[minishell]$ ");
	fflush(stdout);
}


//变量的初始化
void init(void)
{
	memset(&cmd, 0, sizeof(cmd));

	//sfdasfdsa
	memset(cmdline, 0, sizeof(cmdline));
}
