#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout<<"Please input a string:";
    bool appear[200];
    int i;
    char s[100];
    for (i=0;i<200;i++) appear[i]=false;
    cin.getline(s,100,'\n');
    for (i=0;i<strlen(s);i++) appear[int(s[i])]=true;
    for (i=199;i>=0;i--) if (appear[i]) cout<<char(i);
    return 0;
}
