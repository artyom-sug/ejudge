#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int a,b1,b2,b3,b4;
    cin>>a;
    b1=a%10;
    a=(a-b1)/10;
    b2=a%10;
    a=(a-b2)/10;
    b3=a%10;
    a=(a-b3)/10;
    b4=a%10;
    a=(a-b4)/10;
    cout<<b1+b2+b3+b4<<" "<<b1*b2*b3*b4;
    return 0;
}
