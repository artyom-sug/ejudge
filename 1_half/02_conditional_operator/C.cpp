#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    long a,b,c,x,y,z;
    cin>>a>>b>>c;
    long double g;
    long int f[5] {a,b,c,a,b};
    for (int i{0}; i<3;i++)
    {
        if (f[i]>f[i+1] and f[i]>f[i+2])
        {
            x=f[i];
        }
        else if (f[i]<f[i+1] and f[i]<f[i+2]) 
        {
            z=f[i];
        }
        else
        {
            y=f[i];
        }
    }
    g=(x*x*1.0-y*y)/(y*y*1.0-z*z);
    cout<<fixed<<setprecision(9)<<g;
    return 0;
}
