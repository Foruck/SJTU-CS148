#include <iostream>

using namespace std;

int main()
{
    cout << "������һ����ĸ��" ;
    char ch;
    cin>>ch;
    switch (ch){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':cout<<"Ԫ��";break;
        default:if (((ch>'a')&&(ch<='z'))|((ch>'A')&&(ch<='Z'))) cout<<"����";
                else cout<<"����Ӣ����ĸ";
                break;
    }
    return 0;
}
