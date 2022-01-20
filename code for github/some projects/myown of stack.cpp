#include <stdio.h>
#include<string.h>
#define SIZE 30
typedef struct stack{
    int elem[SIZE];
    int top;
}STACK;
//初始化，入栈，出栈，判断是否满，是否空，取栈顶元素。
void init(STACK *s)//初始化
{
    s->top=0;
}
bool  isempty(STACK *s)//判空
{
    return s->top==0;
}
bool  isfull(STACK *s)//判满
{
    return s->top==SIZE;//数组下标是从0 - SIZE-1
}
//入栈：
bool push(STACK *s,int ch)//入栈
{
    if(isfull(s))
    {
        return false;
    }
    else 
    {
        s->elem[s->top++]=ch;
    }
    return true;
}
//出栈：
bool pop(STACK *s)//出栈的内容放到*pch中
{
    if(isempty(s))
    {
        return false;
    }
    else
    {
        s->top--;
      //  *pch = s->elem[s->top];
    }
    return true;
}
int peek(STACK *s)//查看栈顶元素
{
    return s->elem[s->top-1];
}
int main()
{
    STACK mine;
    init(&mine);
    int ele,num=0;
    while(1)
    {
        scanf("%d",&ele);
        if(ele==0)
        {
            break;
        }
        else
        {
            num++;
            push(&mine,ele);
        }
    }
    if(num>2)
    {
        pop(&mine);
        pop(&mine);
        push(&mine,100);
    }
    while(!isempty(&mine))
    {
        printf("%d\n",peek(&mine));
        pop(&mine);
    }
    printf("the stack is empty!\n");
    return 0;
}