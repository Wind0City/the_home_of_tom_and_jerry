#include <stdio.h>
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
int main()
{
    int n;
    scanf("%d",&n);
    printf("n=");
    if(n==1)
    {
        printf("1\n");
    }
    else if(judge(n))
    {
        printf("%d\n",n);
    }
    else
    {
        
    }
}