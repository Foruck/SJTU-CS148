#include <iostream>

using namespace std;

int main()
{
    cout << "请输入一个三位整数：" << endl;
    int n;
    cin >> n;
    cout <<n<<"的百位数字是"<<n/100<<",十位数字是"<<(n/10)%10<<",个位数字是"<<n%10;
    return 0;
}
