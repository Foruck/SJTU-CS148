#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,m,i,j,k,tot=2,len[100],l;
    bool check[200],dot[200],useless[200],flag,disp[100000],cc;
    char s[1000],alert[100][100],comp[1000];

    strcpy(alert[0],"l4");len[0]=2;
    strcpy(alert[1],"fd");len[1]=2;
    strcpy(alert[2],"d26");len[2]=3;
    tot=2;
    for (i=int('a');i<=int('z');i++) check[i]=true;
    for (i=int('A');i<=int('Z');i++) check[i]=true;
    for (i=int('0');i<=int('9');i++) check[i]=true;
    check[int('@')]=true;
    check[int('#')]=true;
    check[int('$')]=true;
    check[int(' ')]=true;
    useless[int('@')]=true;
    useless[int('#')]=true;
    useless[int('$')]=true;
    useless[int(' ')]=true;
    check[int('"')]=true;
    check[int(',')]=true;
    check[int('.')]=true;
    dot[int('"')]=true;
    dot[int(',')]=true;
    dot[int('.')]=true;

    cout<<"����Ϊ���벻�������ٸ��ַ��ȽϺ��ʣ�";
    cin>>n;

    cin.get();

    while (true){
        cout<<"���ɶ���?(��ֹͣ,����FFFFF)";
        cin.getline(s,6,'\n');
        if (s[0]=='F' && s[1]=='F' && s[2]=='F' && s[3]=='F' && s[4]=='F' && s[5]=='\0') break;
        if (strlen(s)>2 | check[int(s[0])]) {cout<<"����."<<endl;continue;}
        check[int(s[0])]=true;dot[int(s[0])]=true;
    }

    while (true){
        cout<<"���ɶ��Ч�ַ�?(��ֹͣ,����FFFFF)";
        cin.getline(s,6,'\n');
        if (s[0]=='F' && s[1]=='F' && s[2]=='F' && s[3]=='F' && s[4]=='F' && s[5]=='\0') break;
        if (strlen(s)>2 | check[s[0]]) {cout<<"����."<<endl;continue;}
        check[int(s[0])]=true;useless[int(s[0])]=true;
    }

    while (true){
        cout<<"���ɶ���дʣ�(����L4,Fd,D26����ֹͣ,����@@@@@)";
        cin.getline(s,2000,'\n');
        if (s[0]=='@' && s[1]=='@' && s[2]=='@' && s[3]=='@' && s[4]=='@' && s[5]=='\0') break;
        m=strlen(s);flag=true;
        for (i=0;i<m-1;i++)
        if (!check[int(s[i])] | dot[int(s[i])] | useless[int(s[i])]) {flag=false;break;}
        if (!flag) {cout<<"����."<<endl;continue;}
        tot++;
        len[tot]=m;
        for (i=0;i<m-1;i++) {if (s[i]>='A' && s[i]<='Z') alert[tot][i]=s[i]-int('A')+int('a');else alert[tot][i]=s[i];}
    }

    cout<<"�����ַ���:";
    cin.getline(s,20000,'\n');
    while (s[0]!='\0'){
        m=strlen(s);

        if (m>n) {cout<<"���벻��Ҫ��."<<endl;cout<<"�����ַ���:";cin.getline(s,20000,'\n');}
        flag=false;
        for (i=0;i<m;i++) if (!check[int(s[i])]) {cout<<"���벻��Ҫ��."<<endl;cout<<"�����ַ���:";cin.getline(s,20000,'\n');flag=true;break;}
        if (flag) continue;

        for (i=0;i<m;i++){
            if (s[i]>='A' && s[i]<='Z') comp[i]=s[i]-int('A')+int('a');
            else comp[i]=s[i];
            disp[i]=true;
        }

        while (true){
            cc=false;
            for (i=0;i<m;i++){
                if (!disp[i] | dot[comp[i]] | useless[comp[i]]) continue;
                for (j=0;j<=tot;j++){
                    if (i+len[j]>m) continue;
                    l=i;k=0;flag=false;
                    while (k<len[j] && l<m){
                        if (dot[comp[l]]) break;
                        if (useless[comp[l]] | !disp[l]) {l++;continue;}
                        if (comp[l]!=alert[j][k]) break;
                        if (comp[l]==alert[j][k] && k==len[j]-1) {flag=true;break;}
                        k++;l++;
                    }
                    if (flag){
                        for (k=i;k<=l;k++) disp[k]=false;
                        cc=true;
                        break;
                    }
                }
                if (cc) break;
            }
        if (!cc) break;
        }

        cout<<"���˺�:";
        for (i=0;i<m;i++) if (disp[i]) cout<<s[i];
        cout<<endl;

        cout<<"�����ַ���:";
        cin.getline(s,20000,'\n');
    }

    return 0;
}
