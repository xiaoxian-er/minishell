#include "init.h"
#include "parse.h"
#include "def.h"

char cmdline[MAXLINE+1];
char avline[MAXLINE+1];
COMMAND cmd;

int main(void)
{
	//初始操作
	setup();
	//shell循环
	shell_loop();
	return 0;
}
