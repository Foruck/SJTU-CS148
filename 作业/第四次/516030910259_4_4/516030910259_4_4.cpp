#include <iostream>

using namespace std;

int main()
{
    int n,i,day,week,year,month,a[7]={0,0,0,0,0,0,0};
    cin>>n;
    year=1900;month=1;day=1;week=1;
    while (true){
        day++;week=(week+1)%7;
        if (day==13) a[week]++;
        switch(month){
            case 1:
            case 3:
            case 5:
            case 7:
            case 10:
            case 8:if (day==32){day=1;month++;}break;
            case 12:if (day==32){day=1;month=1;year++;}break;
            case 4:
            case 6:
            case 9:
            case 11:if (day==31){day=1;month++;}break;
            case 2:if ((year%4==0 && year%100!=0)|(year%400==0)) {if (day==30){day=1;month++;}}
                   else if (day==29){day=1;month++;}
                   break;
        }
        if (year==1900+n) break;
    }
    for (i=1;i<=6;i++) cout<<a[i]<<" ";
    cout<<a[0];
}
