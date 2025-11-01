#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main ()
{
    long a,b;
    double s,l,pi;
    cin>>a>>b;
    pi=acos(-1.0);
    s=pi*abs(a*a-b*b);
    if (a>b)
    {
        l=2*pi*a;
    }
    else
    {
        l=2*pi*b;
    }
    cout<<fixed<<setprecision(9)<<s<<" "<<l;
    return 0;
}
