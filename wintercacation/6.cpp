#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack <char> s;
    char ch;
    while((ch=getchar())!='\n')
    {
        if(ch=='('||ch=='{'||ch=='[')
        {
            s.push(ch);
        }
        if(ch=='}'||ch==')'||ch==']')
        {
            s.pop();
        }
    }
    if(s.empty())
    {
        printf("TRUE\n");
    }
    else
    {
        printf("false");
    }
    return 0;
}