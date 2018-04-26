// Project Euler Problem 2
// idea : compare each element with 4000000 and plus it
#include <iostream>
#include <math.h>
#include <limits>

using namespace std;
#define k 4000000
int main()
{
    cout<<"Hello World"<<endl;
    double a1,a2,a3,s;
    a1=1; a2=2;a3=3;s=a2;
    while(a1<=k && a2<=k && a3<=k)
    {
        double a4,a5,a6;
        a4=a2+a3;
        a5=a3+a4;
        a6=a4+a5;
        s=s+a5;
        a1=a4;a2=a5;a3=a6;
    }
    cout.precision(20);
    cout<<s<<endl;
    return 0;
}