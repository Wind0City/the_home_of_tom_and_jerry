/*
第 1 题
请编写一个函数，此函数的功能：删除字符串中的所有空
格以及非字母符号，然后将剩余的大写字母变为小写字母，
按照字母表的倒序输出。
例如，输入 “ Welcome to ZZU ! ”，则输出“ zzwutoomleec ”。
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];
int num[26]={0};
void ans(char *str,int n);
int main()
{
    gets(str);
    int n=strlen(str);
    ans(str,n);
    return 0;
}
void ans(char *str,int n)
{
    int i;
     for ( i = 0; i < n; i++)
    {
        if(isalpha(str[i]))//判断是否是字母
        {
            str[i]=towlower(str[i]);//全部转化为小写字母
            num[str[i]-'a']++;//对应的记录次数的int数组自增(记录次数)
        }
    }
    for ( i = 25; i >=0; i--)//对记录次数的数组遍历
    {
        if(num[i]!=0)
        {
            for (int j = 0; j < num[i]; j++)//是多少次输出多少
            {
                printf("%c",i+'a');
            }
        }
    }
    return;
}