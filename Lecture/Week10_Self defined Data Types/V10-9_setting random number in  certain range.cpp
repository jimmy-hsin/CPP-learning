#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int rn=0;
    int rn2=0;
    for(int i=0; i<10;i++)
    {
        rn=rand()%10+100;  //把random number限定在100~109之間
        rn2=rand()%501;
        cout<<rn<<" "<<static_cast<double>(rn2)/100<<"\n";
    }
    //其他有用的亂數函式，可以去<random>裡面去看

    return 0;
}
