#include <iostream>
#include <cassert>
using namespace std;
template <class T>
class cset;

template <class T>
ostream &operator<<(ostream &os,const cset<T> &x);

template <class T>
cset<T> operator*(const cset<T> &x,const cset<T> &y);

template <class T>
cset<T> operator+(const cset<T> &x,const cset<T> &y);

template <class T>
cset<T> operator-(const cset<T> &x,const cset<T> &y);

template <class T>
class cset{
    friend ostream &operator<<(ostream &os,const cset<T> &x){
        for (int i=0;i<x.tot;i++) os<<x.a[i]<<' ';
        return os;
    }
    friend cset<T> operator*(const cset<T> &x,const cset<T> &y){
        T a[2333];
        cset<T> *ans;
        bool flag=false;
        int i,j,k,n=-1;
        for (i=0;i<x.tot;i++){
            flag=true;
            for (j=0;j<y.tot;j++){
                if (x.a[i]==y.a[j]) {flag=false;break;}
            }
            if (flag) {n++;a[n]=x.a[i];}
        }
        for (i=0;i<y.tot;i++) {n++;a[n]=y.a[i];}
        ans=new cset<T>(n+1,a);
        return *ans;
    }
    friend cset<T> operator+(const cset<T> &x,const cset<T> &y){
        T a[2333];
        cset<T> *ans;
        bool flag=false;
        int i,j,k,n=-1;
        for (i=0;i<x.tot;i++){
            flag=false;
            for (j=0;j<y.tot;j++){
                if (x.a[i]==y.a[j]) {flag=true;break;}
            }
            if (flag) {n++;a[n]=x.a[i];}
        }
        ans=new cset<T>(n+1,a);
        return *ans;
    }
    friend cset<T> operator-(const cset<T> &x,const cset<T> &y){
        T a[2333];
        cset<T> *ans;
        bool flag=false;
        int i,j,k,n=-1;
        for (i=0;i<x.tot;i++){
            flag=true;
            for (j=0;j<y.tot;j++){
                if (x.a[i]==y.a[j]) {flag=false;break;}
            }
            if (flag) {n++;a[n]=x.a[i];}
        }
        ans=new cset<T>(n+1,a);
        return *ans;
    }

private:
    T *a;
    int tot;
public:
    cset(int n,T *x):tot(n){
        a=new T[n];
        for (int i=0;i<n;i++) a[i]=x[i];
        return;
    }
    ~cset(){delete[] a;}
};
int main()
{
    int a[10]={0,1,2,3,4,10,11,12,13,14};
    int b[10]={0,1,2,3,4,5,6,7,8,9};
    cset<int> x(10,a),y(10,b);
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<x*y<<endl;
    cout<<x+y<<endl;
    cout<<x-y<<endl;
    return 0;
}
