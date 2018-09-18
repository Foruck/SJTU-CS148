#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));

    int a[3],b[3],aa,bb,i,j;
    bool appear[11];

    for (i=0;i<=9;i++) appear[i]=false;

    for (i=0;i<=2;i++){
        a[i]=rand()%10;
        while (appear[a[i]]) a[i]=rand()%10;
        appear[a[i]]=true;
    }

    for (i=7;i>0;i--){
        cout<<"请输入你猜测的数字（还有"<<i<<"次机会）:";
        cin>>b[0]>>b[1]>>b[2];
        aa=0;bb=0;
        for (j=0;j<=2;j++){
            if (a[j]==b[j]) aa++;
            else if (appear[b[j]]) bb++;
        }
        if (aa==3) {cout<<"恭喜，你猜对了。";break;}
        else cout<<aa<<"A"<<bb<<"B"<<endl;
    }
    return 0;
}
