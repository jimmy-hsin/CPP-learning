#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    clock_t sTime = clock();
    for( int i=0;i<1000000000;i++)
    ;
    clock_t eTime = clock();

    cout<<sTime<<" "<<eTime<<"\n";
    cout<<(eTime-sTime)<<"\n";
    cout<<static_cast<double>(eTime-sTime)/CLOCKS_PER_SEC<<"\n";
    return 0;
}