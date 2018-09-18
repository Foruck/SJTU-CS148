#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int main()
{
    char *article[6],*noun[6],*verb[6],*preposition[6];
    article[0]="the";
    article[1]="a";
    article[2]="one";
    article[3]="some";
    article[4]="any";
    noun[0]="boy";
    noun[1]="girl";
    noun[2]="dog";
    noun[3]="town";
    noun[4]="car";
    verb[0]="drove";
    verb[1]="jumped";
    verb[2]="ran";
    verb[3]="walked";
    verb[4]="skipped";
    preposition[0]="to";
    preposition[1]="from";
    preposition[2]="overd";
    preposition[3]="under";
    preposition[4]="on";
    srand(time(NULL));
    int n,m,i,j,k;
    char *s[10],a[10];
    for (i=0;i<20;i++){
        n=rand()%4;
        for (j=0;j<strlen(article[n]);j++) a[j]=article[n][j];
        a[0]=char(int(a[0])-int('a')+int('A'));
        a[strlen(article[n])]='\0';
        s[0]=a;
        n=rand()%4;
        s[1]=noun[n];
        n=rand()%4;
        s[2]=verb[n];
        n=rand()%4;
        s[3]=preposition[n];
        n=rand()%4;
        s[4]=article[n];
        n=rand()%4;
        s[5]=noun[n];
        cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<" "<<s[3]<<" "<<s[4]<<" "<<s[5]<<"."<<endl;
    }
    return 0;
}
