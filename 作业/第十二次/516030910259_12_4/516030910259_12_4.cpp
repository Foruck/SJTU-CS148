#include <iostream>
#include <cassert>
using namespace std;

class Vectorr{
    friend ostream &operator<<(ostream &os,const Vectorr &item){
        for (int i=0;i<item.tot;i++) os<<item.a[i]<<" ";
        return os;
    }

    friend istream &operator>>(istream &is,Vectorr &item){
        is>>item.tot;
        delete [] item.a;
        item.a=new int [item.tot];
        for (int i=0;i<item.tot;i++) is>>item.a[i];
        return is;
    }

    friend Vectorr operator+(const Vectorr &x,const Vectorr &y){
        if (x.tot!=y.tot) cout<<"You made a mistake.";
        Vectorr ans(x.tot);
        for (int i=0;i<x.tot;i++) ans.a[i]=x.a[i]+y.a[i];
        return ans;
    }

    friend Vectorr operator-(const Vectorr &x,const Vectorr &y){
        if (x.tot!=y.tot) cout<<"You made a mistake.";
        Vectorr ans(x.tot);
        for (int i=0;i<x.tot;i++) ans.a[i]=x.a[i]-y.a[i];
        return ans;
    }

    friend Vectorr operator*(const Vectorr &x,const Vectorr &y){
        if (x.tot!=y.tot) cout<<"You made a mistake.";
        Vectorr ans(x.tot);
        for (int i=0;i<x.tot;i++) ans.a[i]=x.a[i]*y.a[i];
        return ans;
    }

private:
    int *a,tot;

public:
    Vectorr()=default;

    Vectorr(int x):tot(x){a=new int [tot];}

    Vectorr &operator=(const Vectorr &x){
        if (this==&x) return *this;
        tot=x.tot;
        delete [] a;
        a=new int [tot];
        for (int i=0;i<tot;i++) a[i]=x.a[i];
        return *this;
    }

    ~Vectorr(){delete[] a;return;}

};
int main()
{
    Vectorr x,y,z;
    cin>>x>>y;
    cout<<x+y;
    return 0;
}
