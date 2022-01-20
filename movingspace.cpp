#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,ans;
    scanf("%d",&n);
    int *p=(int*)malloc(sizeof(int)*n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }
    ans=*(p+0);
    for ( i = 0; i < n; i++)
    {
        if(*(p+i)>ans)
        {
            ans=*(p+i);
        }
    }
    printf("the largest:%d\n",ans);
    free(p);
    p=NULL;
    system("pause");
    return 0;
}