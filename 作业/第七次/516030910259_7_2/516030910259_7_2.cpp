#include <iostream>

using namespace std;

bool perfectNumber(int n){
    if (n==1) return false;
    int i,tot=0;
    for (i=1;i<n;i++) if (n%i==0) tot+=i;
    return (tot==n);
}

int main()
{
    int m,n,i,k=0;
    cin>>m>>n;
    cout<<"Perfect number in["<<m<<","<<n<<"]:";
    for (i=m;i<=n;i++) if (perfectNumber(i)) {cout<<i<<" ";k++;}
    if (!k) cout<<"No such number!";
    return 0;
}
