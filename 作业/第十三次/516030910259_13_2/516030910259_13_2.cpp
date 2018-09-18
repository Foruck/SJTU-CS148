#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class LongLongInt{
    friend LongLongInt operator+(const LongLongInt &x,const LongLongInt &y){
        int l,tmp[1000],a[1000],b[1000],i;
        LongLongInt ans;
        l=x.tot>y.tot?x.tot:y.tot;
        for (i=0;i<l+5;i++) {tmp[i]=0;a[i]=0;b[i]=0;}
        for (i=0;i<x.tot;i++) a[i]=x.a[i];
        for (i=0;i<y.tot;i++) b[i]=y.a[i];
        for (i=0;i<l;i++){
            tmp[i]+=a[i]+b[i];
            tmp[i+1]+=tmp[i]/10;
            tmp[i]%=10;
        }
        l+=2;
        while (tmp[l]==0) l--;
        ans.a=new int[l+1];ans.tot=l+1;
        for (i=0;i<=l;i++) ans.a[i]=tmp[i];
        return ans;
    }
    friend LongLongInt operator-(const LongLongInt &x,const LongLongInt &y){
        int l,tmp[1000],a[1000],b[1000],i;
        LongLongInt ans;
        l=x.tot>y.tot?x.tot:y.tot;
        for (i=0;i<l+5;i++) {tmp[i]=0;a[i]=0;b[i]=0;}
        for (i=0;i<x.tot;i++) a[i]=x.a[i];
        for (i=0;i<y.tot;i++) b[i]=y.a[i];
        for (i=0;i<l;i++){
            tmp[i]+=a[i]-b[i];
            while (tmp[i]<0) {tmp[i]+=10;tmp[i+1]-=1;};
        }
        l+=2;
        while (tmp[l]==0) l--;
        ans.a=new int[l+1];ans.tot=l+1;
        for (i=0;i<=l;i++) ans.a[i]=tmp[i];
        return ans;
    }
    friend bool operator>=(const LongLongInt &x,const LongLongInt &y){
        if (x.tot>y.tot) return true;
        if (x.tot<y.tot) return false;
        for (int i=x.tot-1;i>=0;i--){if (x.a[i]<y.a[i]) return false;}
        return true;
    }
    friend bool operator==(const LongLongInt &x,const LongLongInt &y){
        if (x.tot!=y.tot) return false;
        for (int i=0;i<x.tot;i++) if (x.a[i]!=y.a[i]) return false;
        return true;
    }
    friend ostream &operator<<(ostream &os,const LongLongInt &x){
        for (int i=x.tot-1;i>=0;i--) os<<x.a[i];
        return os;
    }
public:
    int *a,tot;
    LongLongInt(const char* s){
        tot=strlen(s);
        a=new int[tot];
        int i;
        for (i=tot-1;i>=0;i--) a[tot-i-1]=int(s[i])-int('0');
        return;
    }
    LongLongInt(const LongLongInt &other){
        tot=other.tot;
        a=new int [tot];
        int i;
        for (i=0;i<tot;i++) a[i]=other.a[i];
        return;
    }
    LongLongInt(){a=NULL;tot=0;return;};
    LongLongInt &operator=(const LongLongInt &y){
        if (this==&y) return *this;
        if (a) delete [] a;
        tot=y.tot;
        a=new int[y.tot];
        for (int i=0;i<y.tot;i++) a[i]=y.a[i];
        return *this;
    }
    virtual ~LongLongInt(){
        delete[] a;
        return;
    }
};
class t1{
    friend istream& operator>>(istream& is,t1 &x){
        char s[1000];
        cin>>s;
        if (s[0]==-1){
            x.pos=false;
            LongLongInt tmp(s+1);
            x.v=tmp;
        }
        else {
            x.pos=true;
            LongLongInt tmp(s);
            x.v=tmp;
        }
        return is;
    }
    friend ostream& operator<<(ostream& os,const t1 &x){
        if (!x.pos) os<<"-";
        os<<x.v;
        return os;
    }
    friend t1 operator+(const t1 &x,const t1 &y){
        t1 tmp;
        if (x.pos && y.pos) {
            tmp.pos=true;
            tmp.v=x.v+y.v;
            return tmp;
        }
        if (x.pos && !y.pos){
            if (x.v>=y.v){
                tmp.pos=true;
                tmp.v=x.v-y.v;
                return tmp;
            }
            else {
                tmp.pos=false;
                tmp.v=y.v-x.v;
                return tmp;
            }
        }
        if (!x.pos && y.pos){
            if (x.v>=y.v){
                tmp.pos=false;
                tmp.v=x.v-y.v;
                return tmp;
            }
            else {
                tmp.pos=true;
                tmp.v=y.v-x.v;
                return tmp;
            }
        }
        if (!x.pos && !y.pos){
            tmp.pos=false;
            tmp.v=x.v+y.v;
            return tmp;
        }
    }
    friend t1 operator-(const t1 &x,t1 &y){
        t1 tmp;
        y.pos=!y.pos;
        tmp=x+y;
        y.pos=!y.pos;
        return tmp;
    }
    friend bool operator>=(const t1 &x,const t1 &y){
        if (x.pos && y.pos) return x.v>=y.v;
        if (x.pos && !y.pos) return true;
        if (!x.pos && y.pos) return false;
        if (!x.pos && !y.pos) return y.v>=x.v;
    }
    friend bool operator==(const t1 &x,const t1 &y){
        return ((x.pos==y.pos)&&(x.v==y.v));
    }
    friend bool operator!=(const t1 &x,const t1 &y){
        return !(x==y);
    }
    friend bool operator>(const t1 &x,const t1 &y){
        return (x>=y)&&(x!=y);
    }
    friend bool operator<=(const t1 &x,const t1 &y){
        return !(x>y);
    }
    friend bool operator<(const t1 &x,const t1 &y){
        return !(x>=y);
    }

private:
    LongLongInt v;
    bool pos;
public:
    t1()=default;
    t1(char *s){
        if (s[0]=='-') {
            pos=false;
            LongLongInt y(s+1);
            v=y;
        }
        else {
            pos=true;
            LongLongInt y(s);
            v=y;
        }
    }
    t1 &operator=(const t1 &y){
        if (this==&y) return *this;
        pos=y.pos;
        v=y.v;
        return *this;
    }
    t1 operator++(){
        t1 s("1");
        *this=*this+s;
        return *this;
    }
    t1 operator++(int c){
        t1 tmp,s("1");
        tmp=*this;
        *this=*this+s;
        return tmp;
    }
    t1 operator--(){
        t1 s("1");
        *this=*this-s;
        return *this;
    }
    t1 operator--(int c){
        t1 s("1"),tmp;
        tmp=*this;
        *this=*this-s;
        return *this;
    }

};
class t2:public LongLongInt{
    friend t2 pus(const t2 &x,const t2 &y){
        int l,tmp[1000],a[1000],b[1000],i;
        t2 ans;
        l=x.tot>y.tot?x.tot:y.tot;
        for (i=0;i<l+5;i++) {tmp[i]=0;a[i]=0;b[i]=0;}
        for (i=0;i<x.tot;i++) a[i]=x.a[i];
        for (i=0;i<y.tot;i++) b[i]=y.a[i];
        for (i=0;i<l;i++){
            tmp[i]+=a[i]+b[i];
            tmp[i+1]+=tmp[i]/10;
            tmp[i]%=10;
        }
        l+=2;
        while (tmp[l]==0) l--;
        ans.a=new int[l+1];ans.tot=l+1;
        for (i=0;i<=l;i++) ans.a[i]=tmp[i];
        return ans;
    }
    friend t2 mus(const t2 &x,const t2 &y){
        int l,tmp[1000],a[1000],b[1000],i;
        t2 ans;
        l=x.tot>y.tot?x.tot:y.tot;
        for (i=0;i<l+5;i++) {tmp[i]=0;a[i]=0;b[i]=0;}
        for (i=0;i<x.tot;i++) a[i]=x.a[i];
        for (i=0;i<y.tot;i++) b[i]=y.a[i];
        for (i=0;i<l;i++){
            tmp[i]+=a[i]-b[i];
            while (tmp[i]<0) {tmp[i]+=10;tmp[i+1]-=1;};
        }
        l+=2;
        while (tmp[l]==0) l--;
        ans.a=new int[l+1];ans.tot=l+1;
        for (i=0;i<=l;i++) ans.a[i]=tmp[i];
        return ans;
    }
    friend t2 operator+(const t2 &x,const t2 &y){
        t2 tmp;
        if (x.pos && y.pos) {
            tmp.pos=true;
            tmp=pus(x,y);
            return tmp;
        }
        if (x.pos && !y.pos){
            if (x>=y){
                tmp.pos=true;
                tmp=mus(x,y);
                return tmp;
            }
            else {
                tmp.pos=false;
                tmp=mus(y,x);
                return tmp;
            }
        }
        if (!x.pos && y.pos){
            if (x>=y){
                tmp.pos=false;
                tmp=mus(x,y);
                return tmp;
            }
            else {
                tmp.pos=true;
                tmp=mus(y,x);
                return tmp;
            }
        }
        if (!x.pos && !y.pos){
            tmp.pos=false;
            tmp=pus(x,y);
            return tmp;
        }
    }
    friend t2 operator-(const t2 &x,t2 &y){
        y.pos=!y.pos;
        t2 tmp;
        tmp=x+y;
        y.pos=!y.pos;
        return tmp;
    }
    friend bool operator>=(const t2 &x,const t2 &y){
        if (x.pos && !y.pos) return true;
        if (!x.pos && y.pos) return false;
        if (x.pos && y.pos) {
            if (x.tot>y.tot) return true;
            if (x.tot<y.tot) return false;
            for (int i=x.tot-1;i>=0;i--) if (x.a[i]<y.a[i]) return false;
            return true;
        }
        if (!x.pos && !y.pos){
            if (x.tot>y.tot) return false;
            if (x.tot<y.tot) return true;
            for (int i=x.tot-1;i>=0;i--) if (x.a[i]>y.a[i]) return false;
            return true;;
        }
    }
    friend bool operator==(const t2 &x,const t2 &y){
        if (x.pos!=y.pos) return false;
        if (x.tot!=y.tot) return false;
        for (int i=0;i<x.tot;i++) if (x.a[i]!=y.a[i]) return false;
        return true;
    }
    friend bool operator!=(const t2 &x,const t2 &y){return !(x==y);}
    friend bool operator>(const t2 &x,const t2 &y){return (x>=y && x!=y);}
    friend bool operator<(const t2 &x,const t2 &y){return !(x>=y);}
    friend bool operator<=(const t2 &x,const t2 &y){return !(x>y);}
    friend istream &operator>>(istream& is,t2 &x){
        char s[1000];
        int i,k=0;
        is>>s;
        x.tot=strlen(s);
        x.a=new int [x.tot];
        if (s[0]=='-') {for (i=1;i<x.tot;i++) x.a[i]=int(s[x.tot-i])-int('0');x.tot--;}
        else {for(i=0;i<x.tot;i++) x.a[i]=int(s[x.tot-i-1])-int('0');}
        return is;
    }
private:
    bool pos;
public:
    t2(const t2 &y):LongLongInt(y){
        pos=y.pos;
    }
    t2(char *s):LongLongInt(s){
        if (s[0]=='-') for (int i=0;i<tot-1;i++) a[i]=a[i+1];
        tot--;
    }
    t2()=default;
    t2 operator++(){
        t2 s("1");
        *this=*this+s;
        return *this;
    }
    t2 operator++(int c){
        t2 tmp,s("1");
        tmp=*this;
        *this=*this+s;
        return tmp;
    }
    t2 operator--(){
        t2 s("1");
        *this=*this-s;
        return *this;
    }
    t2 operator--(int c){
        t2 s("1"),tmp;
        tmp=*this;
        *this=*this-s;
        return *this;
    }
};
int main()
{
    cout<<"Hello world."<<endl;
    cout<<"你可以输入两个数字。空格或回车分离。"<<endl;
    char s1[1000],s2[1000];
    cin>>s1>>s2;
    t1 x(s1),y(s2);
    cout<<x<<endl;
    cout<<y<<endl;
    cout<<x-y;
    return 0;
}
