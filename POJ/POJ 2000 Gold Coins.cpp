#include <iostream>
// #include <array>
// #include <cassert>
#include <cmath>
using namespace std;

// #define assertm(exp, msg) assert(((void)msg, exp))

unsigned long int calculate_value(unsigned long int test_day)
{
    long double x_1 = (-1 + sqrt((long double)(1 + 8 *test_day)))/2.0;
    unsigned long int epoch = floorl(x_1);
    unsigned long int days = epoch * (epoch+1) /2;
    unsigned long int resi = test_day - days;
    unsigned long int total_value = epoch*(epoch+1)*(2*epoch+1)/6 + resi*(epoch+1);
    return total_value;
}   

int main()
{
    unsigned long int test_day;
    cin>>test_day;
    while(test_day>0)
    {
        unsigned long int total_value = calculate_value(test_day);
        cout<<test_day<<" "<<total_value<<endl;
        cin>>test_day;
    }
    return 0;
}
// int main()
// {

//     std::array<unsigned long int, 12> test_case = {10, 6, 7, 11, 15, 16, 100, 10000, 1000, 21, 22, 0};
//     std::array<unsigned long int, 12> results = {30, 14, 18, 35, 55, 61, 945, 942820, 29820, 91, 98};
//     for(int i=0; i < 12; i++)
//     {
//         unsigned long int test_day = test_case[i];
//         unsigned long int total_value = calculate_value(test_day);
//         if (total_value!=results[i])
//         {
//             cout<<total_value<<" "<<" "<<results[i]<<endl;
//             return 0;    
//         }
//         else
//         {
//             cout<<"pass"<<endl;
//         }
//     }
    
//     return 0;
// }
