#include <iostream>

using namespace std;

int getNumber(){
    int n;
    char s[200];
    cout<<"������һ�����ڵ���10��С��30��������";
    while (true){
        cin.getline(s,199,'\n');
        if (s[0]<='2' && s[0]>='1' && s[1]>='0' && s[1]<='9' && s[2]=='\0') return (int(s[0])-int('0'))*10+int(s[1])-int('0');
        else cout<<"���벻�Ϲ淶�����������룺";
    }
}

int main()
{
    int x;
    x=getNumber();
    return 0;
}
