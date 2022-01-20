/*12-7、(*****)编程序实现个人财务管理，个人的财务项目包括日期、时间、收入、支出四项，程序可以实现输入多笔交易、计算个人的年收入总额、支出总额、存款余额，并能打印输出。
注意：此题用到windows一些函数，需要在windows系统下运行。
也可以在网上查找如何在GCC编译器下获取系统时间。
运行结果如下：
*/
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <Windows.h>
#include <time.h>
#define DEAL	50	/*设计最大交易次数*/

struct Date
{
    int da_year;  //年
    int da_mon;  //月
    int da_day;  //日
};
struct Time
{
    int ti_hour;   //小时
    int ti_min;   //分钟
    int ti_sec;    //秒
};
struct deal
{
    Date dt;						/*每笔交易的日期*/
    Time ti;						/*每笔交易的时间*/
    double earning;						/*每笔交易的收入额度*/
    double payout;						/*每笔交易的支出额度*/
};
typedef struct deal FINANCE;//
FINANCE person[DEAL]={0};    //存放用户每笔的交易信息
void getdate(Date *pd);//已实现，如下所示。获取系统日期，存入pd所指的Date结构体中
void gettime(Time *pt);// 已实现，如下所示。获取系统时间，存入pt所指的Time结构体中
void GetDateTime(FINANCE *per); //调用getdate与gettime函数将获取的时间日期存入per所指的结构体变量中
void Menu();  //显示系统菜单
char bioskey(); //返回用户输入的菜单命令
void InputOneDeal(FINANCE *per);  //执行菜单命令1，输入一笔交易，存入结构体per所指的结构体变量中。注意当输入为整数的时候存入earning中，输入为负数的时候存入payout中。
float Balance(FINANCE *per);  //返回账户中余额。账户person数组中的所有收入与支出之差。
void OneYearBalance(FINANCE *per,int year); //打印某一年的交易信息统计
void PrintBalance(FINANCE *per);  //执行菜单命令2，打印所有年份的所有交易信息
void PrintOneYear(FINANCE *per);//执行菜单命令3，打印某一年的所有交易信息，包括该年交易明细及调用OneYearBalance函数输出交易统计

int main()
{
    char key;
    int i;
    i = 0;
    while(1)
    {
      Menu();
        key=bioskey();
        fflush(stdin);   //清空缓冲区
        switch(key)
        {
            case '1':  InputOneDeal(person+i);
                i++;
                break;
            case '2':  PrintBalance(person);
                break;
            case '3':  PrintOneYear(person);
                break;
            case '4':  exit(0);
            default :  break;
        }
    }
    system("pause");
}

//获取系统日期，存入pd所指的Date结构体中
void getdate(Date *pd)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    pd->da_day=st.wDay;
    pd->da_mon=st.wMonth;
    pd->da_year=st.wYear;
}
//获取系统时间，存入pt所指的Time结构体中
void gettime(Time *pt)
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    st.wHour=st.wHour+8;
    if(st.wHour>24)
    {
        st.wHour=st.wHour-24;
    }
    pt->ti_hour=st.wHour;
    pt->ti_min=st.wMinute;
    pt->ti_sec=st.wSecond;
    
}
void Menu()
{
    printf("1.Input One deal\n");
    printf("2.Print All the Balance\n");
    printf("3.Print One year Balance\n");
    printf("4.Exit to DOS\n");
}
char bioskey()
{
    char ans;
    scanf("%c",&ans);
    return ans;
}
void GetDateTime(FINANCE *per)
{
    getdate(&(per->dt));
    gettime(&(per->ti));
}
void InputOneDeal(FINANCE *per)
{
    float ex;
    printf("Please Input one deal<+/->:\n");
    //getdate(&(per->dt));
    //gettime(&(per->ti));
    GetDateTime(per);
    printf("%02d/%02d/%02d  %02d:%02d:%02d  :",per->dt.da_year,per->dt.da_mon,per->dt.da_day,per->ti.ti_hour,per->ti.ti_min,per->ti.ti_sec);
    scanf("%f",&ex);
    if(ex>0)
    {
        per->earning=ex;
    }
    else
    {
        per->payout=ex;
    }
}
float Balance(FINANCE *per)
{
    int i,ans=0;
    for ( i = 0;(per+i)->dt.da_year; i++)
    {
        ans=ans+(per+i)->earning+(per+i)->payout;
    }
    return ans;
}
void PrintBalance(FINANCE *per)
{
    int i;
    printf("Date\t   Time\t      Earning\tpayout      Balance\n");
    printf("-------------------------------------------------------\n");
    for (size_t i = 0;(per+i)->dt.da_year; i++)
    {
        printf("%4d/%02d/%02d  %02d:%02d:%02d  :",(per+i)->dt.da_year,(per+i)->dt.da_mon,(per+i)->dt.da_day,(per+i)->ti.ti_hour,(per+i)->ti.ti_min,(per+i)->ti.ti_sec);
        printf("%.3f\t%.3f\n",(per+i)->earning,(per+i)->payout);
    }
    printf("--------------------------------------------------------\n");
    printf("\t\t\t\t\t     %.3f\n",Balance(per));
}
void PrintOneYear(FINANCE *per)
{
    int d;
    printf("Input one year:");
    scanf("%d",&d);
    printf("Date\t   Time\t      Earning\tpayout      \n");
    printf("-------------------------------------------------------\n");
    OneYearBalance(per,d);
}
void OneYearBalance(FINANCE *per,int year)
{
    int i;
    float ans_payout=0,ans_earning=0,ans_balance=0;
    for ( i = 0;(per+i)->dt.da_year; i++)
    {
        if((per+i)->dt.da_year==year)
        {
           printf("%d/%02d/%02d  %02d:%02d:%02d  :",(per+i)->dt.da_year,(per+i)->dt.da_mon,(per+i)->dt.da_day,(per+i)->ti.ti_hour,(per+i)->ti.ti_min,(per+i)->ti.ti_sec);
           printf("%.3f\t%.3f\n",(per+i)->earning,(per+i)->payout);  
        }
    }
    printf("--------------------------------------------------------\n");
    printf("param of %d:\n",year);
    printf("sum of earning\tsum of payout\tbalance\n");
    for ( i = 0;(per+i)->dt.da_year; i++)
    {
        if((per+i)->dt.da_year==year)
        {
            ans_balance=ans_balance+(per+i)->earning+(per+i)->payout;
            ans_earning=ans_earning+(per+i)->earning;
            ans_payout=ans_payout+(per+i)->payout;
        }
    }
    printf("%.3f\t        %.3f\t        %.3f\n",ans_earning,ans_payout,ans_balance);
}