#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    cout << "Enter the width:" ;
    double width,tot,l;
    cin>>width;
    tot=0;l=0;
    while (l<1-width/2){
        tot+=sqrt(4-(l+l+width)*(l+l+width))/2*width;
        l+=width;
    }
    printf("The result is (with six decimal places) %.6f.",tot);
    return 0;
}
