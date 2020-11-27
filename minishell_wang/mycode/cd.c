#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define PATH_SIZE 100
#define BUF_SIZE 64
int cds(char *p)
{
        char path[PATH_SIZE];
        char *start;
        char *end;
        int res;
        int n= 0;
	*(p+strlen(p)-1)='\0';
        memset(path,'\0',PATH_SIZE); // 空字符
        start = strchr(p,' '); //在参数p所指向的字符串中搜索第一次出现字符 '' 
	if(start!=NULL)
	{
	strcpy(path,start+1);
	res=chdir(path);
	}
	else
	{
	res=chdir(p);
	}

        if(res != 0)
                printf("%s is not a path,please check again \n",path);

        return res;
}
int main(int argc, char *argv[])
{
char buf[BUF_SIZE];
printf("|->");
fflush(stdout);
fgets(buf,BUF_SIZE,stdin);//从输入流stdin即输入缓冲区中读取BUF_SIZE个字符到字符数组buf中（包括\0)
if(cds(buf)==0)
{
char pwd[BUF_SIZE];
getcwd(pwd,sizeof(pwd));//将当前工作目录的绝对路径复制到pwd
printf("you have cd successful,the directory is:%s\n",pwd);
}

}
