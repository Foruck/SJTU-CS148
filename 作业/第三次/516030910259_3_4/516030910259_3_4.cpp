#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    cout << "输入一个奇数（1到11）:" ;
    int n,width,m;
    cin >> n;
    m=n;
    width=1;
    for (int i=1;i<=n/2+1;++i){
        for (int j=1;j<=(m-width)/2;++j) printf(" ");
        for (int j=1;j<=width;++j) printf("*");
        width+=2;
        printf("\n");
    }
    width-=4;
    for (int i=n/2+2;i<=n;++i){
        for (int j=1;j<=(m-width)/2;++j) printf(" ");
        for (int j=1;j<=width;++j) printf("*");
        width-=2;
        printf("\n");
    }
    return 0;
}
