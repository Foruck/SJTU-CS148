#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    cout << "����һ����λ������";
    char s[5];
    int a[4];
    int x;
    cin.get(s,5);
    cout << "��������1����������2��";
    cin>>x;
    if (x==1) x=7;
    else x=3;
    a[0]=(int(s[2])-int('0')+x)%10;
    a[1]=(int(s[3])-int('0')+x)%10;
    a[2]=(int(s[0])-int('0')+x)%10;
    a[3]=(int(s[1])-int('0')+x)%10;
    printf("%d%d%d%d",a[0],a[1],a[2],a[3]);
    return 0;
}
