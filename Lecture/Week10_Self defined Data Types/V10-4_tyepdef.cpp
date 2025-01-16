#include <iostream>
using namespace std;

//typedef: 可用於把一個宣告的datatype 轉換成另一個格式
//相當於幫原本的data type取一個別名，用那個別名包進想要用的格式
//ex: 原本宣告一個幣值單位 dollar是integer，有天想要把他們都改成float，只要改一個地方就好
//typedef跟struct一樣，生命週期都只存在於所在的block中而已

typedef double Dollar;   //通常把type宣告成global variable 比較好用，
//若只在main()裡宣告他，那外面的exchange function就會看不懂dollar是什麼，會compilation error
int exchange(Dollar from, double rate)
{
    return from*rate;
}

//以之前的point 舉例，理論上向量和點的資料型態一樣，但數學概念不同，為了區分兩者我們可以給他一個別名，以區分兩種概念
typedef struct Point{
    int x;
    int y;
}Vector;
//這樣我們就能用Vector當作變數名稱來操作point

int main()
{
    typedef double Dollar;
    Dollar NT, US;
    cin>>US;
    NT=exchange(US,29);
    cout<<NT<<"\n";

    return 0;
}
