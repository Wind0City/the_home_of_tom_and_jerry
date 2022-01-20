/*
第 2 题
写一个求出小于 n 的正整数有几个为素数的函数，在主函
数中调用。在主函数输入一个正整数 n，输出共有素数的数
量
（至少在主函数中调用一个函数）
*/
#include <stdio.h>
bool judge(int n);//判断是否是素数
int main()
{
    int n,i,ans=0;//ans记录个数(从零开始)
    scanf("%d",&n);
    for ( i =1 ; i < n; i++)
    {
        if(judge(i))//如果是素数
        {
            ans++;//个数自增
        }
    }
    printf("%d",ans);
    return 0;
}
bool judge(int n)
{
    if(n==1)//特判1
    {
        return false;
    }
    else if(n==2)//特判2
    {
        return true;
    }
    else
    {
        int i;
        for ( i = 2; i <n; i++)//从二开始遍历，素数的概念就是除了一和本书没有其他因数
        {
            if(n%i==0)//如果出现一个因数，取模为0
            {
                return false;//程序终止反回false（即不是素数
                break;
            }
        }
        return true;//如果上面没有终止则这个数是素数
    }
}