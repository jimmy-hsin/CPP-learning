#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    /*
      在C++ 的library裡，clock_t 被宣告成 long int 的格式:
      typedef long int clock_t;
      在用的時候最好還是使用clock_t，以免未來library更改他的data type
    */
    clock_t sTime = clock();
    for( int i=0;i<1000000000;i++)
    ;
    clock_t eTime = clock();

    cout<<sTime<<" "<<eTime<<"\n";
    cout<<(eTime-sTime)<<"\n";
    cout<<static_cast<double>(eTime-sTime)/CLOCKS_PER_SEC<<"\n";
    return 0;
}
