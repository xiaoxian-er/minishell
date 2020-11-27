#include<stdio.h>
#include<time.h>
int main()
{
time_t t;
struct tm * lt;
time(&t);
lt= gmtime(&t);
printf("%d年 %d月 %d日 星期%d %d:%d:%d CST\n",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_wday,(lt->tm_hour+8)%24,lt->tm_min,lt->tm_sec);
return 0;

}
