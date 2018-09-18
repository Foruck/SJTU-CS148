#include <iostream>

using namespace std;

int main()
{
    cout << "请输入一个字母：" ;
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
        case 'U':cout<<"元音";break;
        default:if (((ch>'a')&&(ch<='z'))|((ch>'A')&&(ch<='Z'))) cout<<"辅音";
                else cout<<"不是英文字母";
                break;
    }
    return 0;
}
