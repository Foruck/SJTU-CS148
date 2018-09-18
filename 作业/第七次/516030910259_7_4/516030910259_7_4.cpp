#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int random_int(){
    srand(time(NULL));
    return (rand()%100+1);
}

void game(int ans){
    int a;
    cout<<"I have a number between 1 and 100."<<endl;
    while (true){
        cout<<"Please input your guess:";
        cin>>a;
        if (a>ans) cout<<"Too high!Try again:";
        if (a<ans) cout<<"Too low!Try again:";
        if (a==ans) {cout<<"Excellent!You guessed the number!"<<endl;break;}
    }
    return;
}

int main()
{
    int ans;
    char ch;
    while (true){
        ans=random_int();
        game(ans);
        cout<<"Would you like to play again(y or n)?";
        cin>>ch;
        if (ch!='y') break;
    }
    return 0;
}
