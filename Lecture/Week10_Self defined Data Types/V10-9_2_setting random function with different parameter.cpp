#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//先創建一個用來當作亂數的data type
struct Randomizer
{
    int a,b,c;
    int cur;
    int rand();    //用來回傳亂數的function
};
int Randomizer::rand()
{
    cur=(a*cur+b)%c;    //每次執行random function後，都會把新產生的亂數存回cur中，以讓他繼續產生不同的亂數
    return cur;
}

int main()
{
    Randomizer r1={10,4,31,0};    //設定a, b, c, cur的初始值
    Randomizer r2={10,7,32,0};
    for(int i=0 ; i<10 ; i++)
    cout<< r1.rand() << "," << r2.rand() << "\n";

    return 0;

}
