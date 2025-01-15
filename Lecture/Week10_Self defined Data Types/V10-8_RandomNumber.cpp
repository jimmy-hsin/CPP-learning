#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //---------------------------------------------Part1---------------------------------------------
    cout<<"-------Part 1----------"<<'\n';
    int rn=0;
    for(int i=0;i<10;i++)
    {
        rn=rand();    //int rand() 會隨機回傳一個0~RAND_MAX之間的整數(Rand_max在<cstdlib>中被設定為32767)
        cout<<rn<<'\n';
    }
    cout<<"\n";

    //---------------------------------------------Part2---------------------------------------------
    cout<<"-------Part 2----------"<<'\n';
    //rand()其實回傳的是一個pseudo-random的整數
    srand(0);//設定一個造成random number的種子，可以產生其他不同的random numbers
    rn=0;
    for(int i=0;i<10;i++)
    {
        rn=rand();    //int rand() 會隨機回傳一個0~RAND_MAX之間的整數(Rand_max在<cstdlib>中被設定為32767)
        cout<<rn<<'\n';
    }
    cout<<"\n";

    //---------------------------------------------Part3---------------------------------------------
    cout<<"-------Part 3----------"<<'\n';
    //為了讓每次操作都可以有一個不同的argument，已產生真的random
    //用現在時間當作輸入是一個不錯的辦法
    //time_t time(time_t* timer);   time這個function，會把現在的秒數存進指標timer所指到的地方
    //time(0) 會回傳一個從1970/1/1 0:00:00到現在所經過的秒數
    cout<<time(nullptr); //通常指標timer的部分會被設成nullptr(沒有要設一個地方存秒數的話)
    time_t t=time(nullptr);  //time_t 是ctime裡面所定義的一個時間的data type(可能是int, doulbe, float....)
    cout<<t<<"\n";

    /*---------------另類寫法:---------------------
    time_t t;  //先設定一個type 為time_t的變數:t
    time(&t);  //把現在的秒數存到t的地址上
    cout<<t<<'\n';  //把秒數印出來
    -----------------------------------------------*/
    
    //good writing
    srand(time(nullptr));
    int rn=0;
    for(int i=0; i<10; i++)
    {
        rn=rand();
        cout<<rn<<" ";
    }

    //bad writing
    /*
    int rn=0;
    for(int i=0; i<10; i++)
    {
        srand(time(nullptr));  //BAD
        rn=rand();
        cout<<rn<<" ";
    }
    //每次進來迴圈都會重新設定seed，但迴圈跑的時間太短，
    //所以會每次都得到一樣的秒數(在<1s的時間內跑完了)
    */
    

    
}