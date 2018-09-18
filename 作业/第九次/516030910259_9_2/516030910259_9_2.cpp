#include <iostream>
#include <cstring>
using namespace std;

char *mystrrchr(char *str,char ch){
    int l,i,n=-1;;
    for (i=0;i<strlen(str);i++){
        if (str[i]==ch) n=i;
    }
    if (n==-1) return NULL;
    else return (str+n);
}

int main()
{
    char s[2000],ch;
    int i;
    cin>>s;
    cin>>ch;
    if (mystrrchr(s,ch)) cout<<mystrrchr(s,ch)<<endl;
    else cout<<"No such letter in the string!"<<endl;
    return 0;
}
