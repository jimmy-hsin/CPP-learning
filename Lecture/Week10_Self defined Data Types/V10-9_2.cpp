#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Randomizer
{
    int a,b,c;
    int cur;
    int rand();
};
int Randomizer::rand()
{
    cur=(a*cur+b)%c;
    return cur;
}

int main()
{
    Randomizer r1={10,4,31,0};
    Randomizer r2={10,7,32,0};
    for(int i=0 ; i<10 ; i++)
    cout<<r1.rand()<<","<<r2.rand()<<"\n";

    return 0;

}