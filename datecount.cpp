#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <dos.h>
const int date1[12]={31,28,31,30,31,30,31,31,30,31,30,31};//非闰年的各个月份的天数
const int date2[12]={31,29,31,30,31,30,31,31,30,31,30,31};//如年的各个月份的天数
typedef struct Date
{
    int da_year;  //年
    int da_mon;  //月
    int da_day;  //日
    int ti_hour;   //小时
    int ti_min;   //分钟
    int ti_sec;    //秒
}time_now;//定义一个具体日期的结构体
void getdate(Date *pd)//获取当前日期
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    pd->da_day=st.wDay;
    pd->da_mon=st.wMonth;
    pd->da_year=st.wYear;
    st.wHour=st.wHour+8;
    if(st.wHour>24)
    {
        st.wHour=st.wHour-24;
    }
    pd->ti_hour=st.wHour;
    pd->ti_min=st.wMinute;
    pd->ti_sec=st.wSecond;
}
char putin()//输入函数
{
    char choice;
    scanf("%c",&choice);
    return choice;
}
void menu()//菜单选项
{
    printf("1:what's the date after the days you want\n");
    printf("2:how many days between now and the date you write\n");
}
bool judge(int x)//判断年份是否是闰年
{
    if(x%400==0){return true;}
    else
    {
        if(x%4==0&&x%100!=0){return true;}
        else return false;
    }
}
void function1(time_now *now)//功能1：计算当前日期经用户输入天数之前和之后的日期
{
    int n,i,j;
    time_now before=*now;
    printf("please putin the number of days:");
    scanf("%d",&n);
    i=n,j=n;
    while (j)//以用户输入的天数是否为零为循环条件//计算这么多天之前的日期
    {
        if(judge(before.da_year))//循环到此时的年份是闰年
        {
            if((before.da_day-j)>=1)//简单情况，只有几天的情况
                {
                    now->da_day = now->da_day-j;
                    break;
                }
            //上方的简单情况不能写为一个，因为涉及到闰年二月份的特殊情况，涉及不同的date数组
            if((before.da_day-j)<1)
            {
                j=j- before.da_day;//更新输入天数
                before.da_mon--;
                before.da_day=date2[before.da_mon-1];//上一个月的天数从上一个月的天数开始开始
            }
            if(before.da_mon==0)//如果在月份自增之后超过十二
            {
                before.da_year--;//年份自增
                if(judge(before.da_year))
                {
                before.da_day=date2[11];//年份自增同时天数也会归零重新计算
                }
                else
                {
                before.da_day=date1[11];
                }
                now->da_mon=12;//月份更新
            }
        }
        else//循环到此时的年份是非闰年
        {
             if((before.da_day-j)>=1)//简单情况，只有几天的情况
            {
                before.da_day = before.da_day-j;
                break;
            }
            //上方的简单情况不能写为一个，因为涉及到闰年二月份的特殊情况，涉及不同的date数组
            if((before.da_day-j)<1)
            {
                j=j- before.da_day;//更新输入天数
                before.da_mon--;
                before.da_day=date1[before.da_mon-1];//上一个月的天数从上一个月的天数开始开始
            }
            if(before.da_mon==0)//如果在月份自增之后超过十二
            {
                before.da_year--;//年份自增
                if(judge(before.da_year))
                {
                    before.da_day=date2[11];//年份自增同时天数也会归零重新计算
                }
                else
                {
                    before.da_day=date1[11];
                }
                before.da_mon=12;//月份更新
            }
        }
    }
    while (n)//以用户输入的天数是否为零为循环条件
    {
        if(judge(now->da_year))//循环到此时的年份是闰年
        {
            if((n+now->da_day)<=date2[now->da_mon - 1])//简单情况，只有几天的情况
                {
                    now->da_day = now->da_day+n;
                    break;
                }
            //上方的简单情况不能写为一个，因为涉及到闰年二月份的特殊情况，涉及不同的date数组
            if((n+now->da_day)>date2[now->da_mon - 1])//超过当前月份的情况下
            {
                n=n-(date2[now->da_mon - 1] - now->da_day);//更新输入天数
                now->da_day=0;//下一个月份天数从零开始
                now->da_mon++;//月份+
            }
            if(now->da_mon==13)//如果在月份自增之后超过十二
            {
                now->da_year++;//年份自增
                now->da_day=0;//年份自增同时天数也会归零重新计算
                now->da_mon=1;//月份更新
                //此处年份自增，不用判断是否为闰年，判断会在下一次循环开始时判断
                //下方的非闰年同理
            }
        }
        else//循环到此时的年份是非闰年
        {
            if (n+now->da_day<=date1[now->da_mon - 1])
            {
                now->da_day = now->da_day+n;
                break;
            }
            if((n+now->da_day)>date1[now->da_mon - 1])//超过当前月份的情况下
            {
                n=n-(date1[now->da_mon - 1] - now->da_day);
                now->da_day=0;
                now->da_mon++;
            }
            if(now->da_mon==13)
            {
                now->da_year++;
                now->da_mon=1;
            }
        }
    }
    printf("After %d day(s),the date is:%d/%02d/%02d\n",i,now->da_year,now->da_mon,now->da_day);
    printf("Before %d day(s),the date is:%d/%02d/%02d\n",i,before.da_year,before.da_mon,before.da_day);
}
void function2(time_now *now)//功能2：计算现在的日期与用户输入的日期之间相隔的天数
{
    int das_year,das_month,das_day;
    long long ans1=0,ans2=0,i,ans;
    printf("putin the date(year/month/day) :");
    scanf("%d %d %d",&das_year,&das_month,&das_day);
    for ( i = 1; i <= das_year; i++)
    {
        if(judge(i))
        {
            ans1+=366;
        }
        else
        {
            ans1+=365;
        }
    }
    for ( i = 1; i <= now->da_year; i++)
    {
        if(judge(i))
        {
            ans2+=366;
        }
        else
        {
            ans2+=365;
        }
    }
    for ( i = 1; i < das_month; i++)
    {
        if(judge(das_year))
        {
            ans1+=date2[i-1];
        }
        else
        {
            ans1+=date1[i-1];
        }
    }
    for ( i = 1; i < now->da_mon; i++)
    {
        if(judge(now->da_year))
        {
            ans2+=date2[i-1];
        }
        else
        {
            ans2+=date1[i-1];
        }
    }
    ans1=ans1+das_day;
    ans2=ans2+now->da_day;
    if(ans1>ans2)     {ans=ans1-ans2;}
    else              {ans=ans2-ans1;}
    printf("there are %lld days between now ande the date you writed!\n",ans);
}
void function3()
{
    time_now wanted;
    printf("please input the date:");
    scanf("%d %d %d",&wanted.da_year,&wanted.da_mon,&wanted.da_day);
    menu();
    char choice;
    choice =putin();
    switch (choice)
    {
        case '1': function1(&wanted); break;
        case '2': function2(&wanted); break;
    }
}
int main()
{
    char choice;
    time_now Time;
    getdate(&Time);
    printf("now:%4d/%02d/%02d %02d:%02d:%02d\n",Time.da_year,Time.da_mon,Time.da_day,Time.ti_hour,Time.ti_min,Time.ti_sec);
    menu();
    choice = putin();
    switch (choice)
    {
        case '1': function1(&Time); break;
        case '2': function2(&Time); break;
        case '3': function3();break;
    }
    system("pause");
}