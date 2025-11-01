#include <iostream>
using namespace std;
int main()
{
    long long a,b;
    cin>>a>>b;
    if (a!=0 and b!=0)
    {
        cout<<"1";
    }
    else if (a==0 and b!=0)
    {
        cout<<"3";
        
    }
    else if (a!=0 and b==0)
    {
        cout<<"2";
    }
    else 
    {
        cout<<"0";
    }
    return 0;
} 
