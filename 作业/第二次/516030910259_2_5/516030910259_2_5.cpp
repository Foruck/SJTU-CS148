#include <iostream>

using namespace std;

int main()
{
    cout << "������һ����λ������:";
    char s[6];
    cin.get(s,6);
    if ((s[0]==s[4])&&(s[1]==s[3])) cout<<"Yes";
    else cout<<"No";
    return 0;
}
