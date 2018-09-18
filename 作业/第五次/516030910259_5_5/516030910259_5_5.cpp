#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class node{
public:
    node *next[26],*fa;
    bool tail;
    int ord;
    char letter;
    node(int a=0){
        for (int i=0;i<26;i++) next[i]=NULL;
        tail=false;
        ord=0;
        fa=NULL;
    }
};

bool check(char ch){
    if ((ch>='a' && ch<='z')|(ch=='\'')) return true;
    return false;
}

int main()
{
    char ch[2000],cas1[50],cas2[50];
    node root=node(5),*now,*pos[2000];
    int i,j,k,len,num[2000],tot=-1,l,r,id;
    cin.getline(ch,2000,'\n');
    while (ch[0]!='\0'){
        r=strlen(ch);
        ch[r]='.';
        for (i=0;i<r;i++){
            if (ch[i]>='A' && ch[i]<='Z') ch[i]=char(int(ch[i])-int('A')+int('a'));
        }//Ð¡Ð´

        l=0;

        for (i=0;i<r;i++){
            if ((i!=0)&&(check(ch[i]) && !check(ch[i-1]))) l=i;

            if (check(ch[i]) && !check(ch[i+1])){
                now=&root;

                for (j=l;j<=i;++j){
                    id=int(ch[j])-int('a');
                    if (now->next[id]!=NULL) {
                        now=now->next[id];
                    }
                    else {
                        now->next[id]=new node;
                        now->next[id]->fa=now;
                        now=now->next[id];
                        now->letter=ch[j];
                    }
                }//×ÖÄ¸Ê÷

                if (now->tail) {num[now->ord]++;}
                else {
                    now->tail=true;
                    tot++;now->ord=tot;
                    num[tot]=1;
                    pos[tot]=now;
                }//Î²½Úµã

                continue;
            }

            if (check(ch[i]) && check(ch[i+1])) continue;
        }
        cin.getline(ch,2000,'\n');
    }
    for (i=0;i<=tot;i++){
        now=pos[i];
        len=0;
        while (now!=&root){
            cas1[len]=now->letter;
            len++;
            now=now->fa;
        }
        for (j=len-1;j>=0;j--) cas2[len-j-1]=cas1[j];
        cas2[len]='\0';
        cout<<left<<setw(12)<<cas2<<left<<setw(4)<<num[i];
        if ((i+1)%5==0) cout<<endl;
    }
    return 0;
}
