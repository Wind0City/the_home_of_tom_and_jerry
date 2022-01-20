#include<stdio.h>
#include <stdlib.h>
int a[10001]={0};
int main()
{
    int n,ans=0;//基于桶排序
    while((n=getchar())!='\n')
    {
            a[n-'0']=1;
    }
    for ( int i = 10001; i >=0 ; i--)
    {
        if(a[i]==1)
        {
            ans++;
            printf("%d ",i);
        }
    }
    printf("\n");
    printf("num:%d\n",ans);
    system("pause");
}