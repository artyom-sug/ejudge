#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    long a,b,c,d,x1,x2;
    cin>>a>>b>>c;
    d=b*b-4*a*c;
    x1=(-b+sqrt(d))/(2*a);
    x2=(-b-sqrt(d))/(2*a);
    cout<<max(x1,x2)<<" "<<min(x1,x2);
    return 0;
}
