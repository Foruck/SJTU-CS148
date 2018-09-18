#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

bool check(const char ch){
    if (int(ch)>=int('A') && int(ch)<=int('Z')) return true;
    if (int(ch)<=int('z') && int(ch)>=int('a')) return true;
    return false;
}

int main()
{
    ifstream in("palindrome.in");
    ofstream out("palindrome.out");
    char str[10500],ch[10000],s[20000];
    int p[20000],mx=0,id=0,ori[20000],i,tot=0,ans=1,pos=0,j;
    str[0]='\0';
    if (!in) {cout<<"Error.";return 0;}
    while (in.getline(ch,10000,'\n')){
        strcat(str,ch);
    }
    tot=0;
    s[0]='#';
    for (i=0;i<strlen(str);i++){
        if (check(str[i])) {
            tot++;s[tot]=str[i];
            if (int(str[i])<'Z') s[tot]=char(int(str[i])-int('A')+int('a'));
            ori[tot]=i;
            tot++;s[tot]='#';
        }
    }
    memset(p,0,tot*sizeof(int));

    for (i=0;i<tot;i++){
        if (mx>i) p[i]=min(p[2*id-i],mx-i);
        else p[i]=1;
        j=0;
        while (p[i]<=i+1 && s[i+p[i]-1]==s[i-p[i]+1]) p[i]++;
        p[i]--;
        if (p[i]+i-1>mx){mx=p[i]+i-1;id=i;}
        if (p[i]>ans) {ans=p[i];pos=i;};
    }
    ans-=1;
    cout<<ans;
    for(i=ori[pos-ans+1];i<=ori[pos+ans-1];i++)
        if (check(str[i])) out<<str[i];
    in.close();
    out.close();

    return 0;
}
