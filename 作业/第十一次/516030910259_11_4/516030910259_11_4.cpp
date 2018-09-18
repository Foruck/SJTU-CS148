#include <iostream>
#include <cstring>
using namespace std;

class LongLongInt{
private:
    int *a,tot;
public:
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
    void add(const LongLongInt &other){
        int l,tmp[1000],i;
        l=tot>other.tot?tot:other.tot;
        for (i=0;i<l+5;i++) tmp[i]=0;
        for (i=0;i<l;i++){
            tmp[i]+=a[i]+other.a[i];
            tmp[i+1]+=tmp[i]/10;
            tmp[i]%=10;
        }
        l+=2;
        while (tmp[l]==0) l--;
        delete[] a;
        a=new int[l+1];tot=l+1;
        for (i=0;i<=l;i++) a[i]=tmp[i];
        return;
    }
    void display(){
        for (int i=tot-1;i>=0;i--) cout<<a[i];
        cout<<endl;
        return;
    }
    ~LongLongInt(){
        delete[] a;
        return;
    }
};

int main()
{
    cout<<"Hello world."<<endl;
    cout<<"你可以输入两个数字。空格或回车分离。"<<endl;
    char s1[1000],s2[1000];
    cin>>s1>>s2;
    LongLongInt x(s1),y(s2);
    cout<<"display:";x.display();
    cout<<"display:";y.display();
    return 0;
}
