#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout<<"请输入文件名:";
    char s[2333];
    ifstream is;
    while (true){
        cin>>s;
        try{
            is.open(s,ifstream::in);
            if (is==0) throw 2;
            else throw 'a';
        }
        catch (int) {
            cout<<"错误."<<endl;
            is.close();
            cout<<"请重新输入文件名:";
        }
        catch (char){
            cout<<"成功."<<endl;
            is.close();
            break;
        }

    }
    return 0;

}
