#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char x[233],ch;
    int a=0,b=0,c=0;
    ifstream s1;
    cout << "�����ļ�·��." << endl;
    cin>>x;
    s1.open(x);
    if (!s1) {cout<<"Error."<<endl;return 0;}
    while (s1.get(ch)){
        if (ch>='A' && ch<='Z') {a++;continue;}
        if (ch>='a' && ch<='z') {a++;continue;}
        if (ch>='0' && ch<='9') {b++;continue;}
        c++;
    }
    cout<<"Ӣ����ĸ��"<<a<<endl;
    cout<<"���֣�"<<b<<endl;
    cout<<"������"<<c<<endl;
	s1.close();
    return 0;
}
