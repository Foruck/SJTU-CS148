#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1,x2,y1,y2;
    cout << "������x1,y1:";
    cin >> x1 >> y1;
    cout << "������x2,y2:";
    cin >> x2 >> y2;
    printf("(%d,%d)��(%d,%d)֮��ľ���:%.2f",x1,y1,x2,y2,sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
