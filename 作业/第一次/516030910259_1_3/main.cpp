#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int x1,x2,y1,y2;
    cout << "请输入x1,y1:";
    cin >> x1 >> y1;
    cout << "请输入x2,y2:";
    cin >> x2 >> y2;
    printf("(%d,%d)和(%d,%d)之间的距离:%.2f",x1,y1,x2,y2,sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
