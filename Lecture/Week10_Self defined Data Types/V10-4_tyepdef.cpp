#include <iostream>
using namespace std;

//typedef: 可用於把一個宣告的datatype 轉換成另一個格式
//相當於幫原本的data type取一個別名，用那個別名包進想要用的格式
//ex: 原本宣告一個幣值單位 dollar是integer，有天想要把他們都改成float，只要改一個地方就好
//typedef跟struct一樣，生命週期都只存在於所在的block中而已
typedef double Dollar;   //通常把type宣告成global variable 比較好用
int exchange(Dollar from, double rate)
{
    return from*rate;
}

int main()
{
    typedef double Dollar;
    Dollar NT, US;
    cin>>US;
    NT=exchange(US,29);
    cout<<NT<<"\n";

    return 0;
}
