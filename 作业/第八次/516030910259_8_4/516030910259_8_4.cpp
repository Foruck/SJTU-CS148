#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char ch[2000000];
    int n,m=0,i,j,k,a[7]{8,7,3,4,9,6,2};
    cin.get(ch,1999999,'\n');
    n=strlen(ch);
    for (i=0;i<n;i++){
        j=int(ch[i])+a[m];
        if (j>122) j=j-91;
        m++;if (m==7) m=0;
        ch[i]=char(j);
    }
    cout<<"加密结果:"<<ch<<endl;
    for (i=0;i<n;i++){
        j=int(ch[i])-a[m];
        if (j<32) j+=91;
        m++;if (m==7) m=0;
        ch[i]=char(j);
    }
    cout<<"解密结果:"<<ch;
    return 0;
}
