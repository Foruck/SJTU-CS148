#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout<<"�������ļ���:";
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
            cout<<"����."<<endl;
            is.close();
            cout<<"�����������ļ���:";
        }
        catch (char){
            cout<<"�ɹ�."<<endl;
            is.close();
            break;
        }

    }
    return 0;

}
