#include <iostream>
#include <cassert>
#include<cstring>
using namespace std;

class sss{
    friend istream &operator>>(istream &is,sss &item){
        char c[10000];
        is>>c;
        item.tot=strlen(c);
        item.s=new char[item.tot];
        for (int i=0;i<item.tot;i++) item.s[i]=c[i];
        return is;
    }

    friend ostream &operator<<(ostream &os,const sss &item){
        for (int i=0;i<item.tot;i++) os<<item.s[i];
        os<<endl;
        return os;
    }

    friend sss operator+(const sss &x,const sss &y){
        sss ans;
        ans.tot=x.tot+y.tot;
        ans.s=new char [ans.tot];
        for (int i=0;i<x.tot;i++) ans.s[i]=x.s[i];
        for (int i=x.tot;i<ans.tot;i++) ans.s[i]=y.s[i-x.tot];
        return ans;
    }

    friend bool operator==(const sss &x,const sss &y){
        int len;
        len=x.tot;
        if (x.tot!=y.tot) return false;
        for (int i=0;i<len;i++) if (x.s[i]!=y.s[i]) return false;
        return true;
    }

    friend bool operator!=(const sss &x,const sss &y){
        return !(x==y);
    }

    friend bool operator>(const sss &x,const sss &y){
        int len;
        len=x.tot>y.tot?y.tot:x.tot;
        for (int i=0;i<len;i++){
            if (x.s[i]>y.s[i]) return true;
            if (x.s[i]<y.s[i]) return false;
        }
        if (x.tot>y.tot) return false;
        return true;
    }

    friend bool operator>=(const sss &x,const sss &y){
        return (x==y | x>y);
    }

    friend bool operator<=(const sss &x,const sss &y){
        return (y>=x);
    }

    friend bool operator<(const sss &x,const sss &y){
        return (y>x);
    }

private:
    char *s;
    int tot;
public:
    sss &operator=(const sss &other){
        if (this==&other) return *this;
        delete [] s;
        s=new char (other.tot);
        tot=other.tot;
        for (int i=0;i<tot;i++) s[i]=other.s[i];
        return *this;
    }

    sss &operator+=(const sss &other){
        int len,i;
        char *c;
        len=other.tot;
        c=new char [len+tot];
        for (i=0;i<tot;i++) c[i]=s[i];
        for (i=tot;i<len+tot;i++) c[i]=other.s[i-tot];
        delete [] s;
        s=new char (len+tot);
        tot+=len;
        for (i=0;i<tot;i++) s[i]=c[i];
        delete [] c;
        return *this;
    }
    ~sss(){delete [] s;}
};

int main()
{
    sss x,y;
    cin>>x;
    cin>>y;
    cout<<(x>y);
    return 0;
}
