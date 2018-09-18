#include <iostream>

using namespace std;

int main()
{
    cout << "Please input m,n:";
    int m,n,i,j,tmp,k,tot=0;
    bool flag=false;
    int a[10][10],line[10];
    cin>>m>>n;
    cout<<"Please input array:"<<endl;
    for (i=0;i<m;i++){
        tmp=0;
        for (j=0;j<n;j++){
            cin>>a[i][j];
            if (a[i][j]>tmp) tmp=a[i][j];
        }
        line[i]=tmp;
    }
    for (i=0;i<m;i++){
        for (j=0;j<n;j++){
            if (a[i][j]>=line[i]){
                flag=true;
                for (k=0;k<m;k++) if (a[k][j]<a[i][j]) {flag=false;break;}
                if (flag) {cout<<"mat["<<i<<"]["<<j<<"]="<<a[i][j]<<endl;tot++;}
            }
        }
    }

    if (!tot) cout<<"Not Found";

    return 0;
}
