#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
int main(int argc,char* argv[]){
        int rt;
        if(argc!=2){
        exit(2);
        }
        else{
           if((rt=unlink(argv[1]))!=0)
{//unlink从文件系统中删除一个名字（名字所指向的文件），若这个名字是指向这个文件的最后一个链接，并且没有进程处于打开这个文件的状态
//删除这个文件，释放这个文件占用的空间
             fprintf(stderr,"error");
             
           }
        }
        return 0;
}
           
