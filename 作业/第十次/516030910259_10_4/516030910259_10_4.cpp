#include <iostream>

using namespace std;

struct node{
    int num;
    char name[50];
    bool used;
    node *next;
};

int main()
{
    node *head,*now,*tmp;
    int n=0,m=0,i,j,k,ans=99999999;
    bool b;
    head=new node;
    now=head;
    while (true){
        tmp=new node;
        cin>>tmp->name;
        if (tmp->name[0]=='@'){delete tmp;break;}
        n++;
        cin>>tmp->num;
        tmp->used=false;
        now->next=tmp;
        now=tmp;
    }
    now->next=NULL;
    now=head->next;
    while (now!=NULL){
        if (now->num<ans) {ans=now->num;tmp=now;}
        now=now->next;
    }
    tmp->used=true;
    n--;
    while (true){
        now=head->next;m=0;b=false;
        while (now!=NULL){
            if (now->num>m && !now->used) {m=now->num;tmp=now;b=true;}
            now=now->next;
        }
        if (b) {cout<<tmp->name<<' ';tmp->used=true;n--;}
        if (n==0) break;
    }

    return 0;
}
