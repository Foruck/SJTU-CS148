#ifndef X_H_INCLUDED
#define X_H_INCLUDED
#include <iostream>
using namespace std;
class SavingAccount{
private:
    static int tot;
    int date,account;
    double sum,rate;
private:
    SavingAccount(int a,double b,double c):date(a),sum(b),rate(c){tot++;account=tot;};
    void change_rate(double a){rate=a;return;};
    void calc(int m){for(int i=0;i<m;i++) sum*=(1+m);};
    void display(){cout<<sum<<endl;};
};


#endif // 516030910259_11_5_H_INCLUDED
