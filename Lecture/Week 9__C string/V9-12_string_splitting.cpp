#include <iostream>
#include <cstring>
using namespace std;

const int CNT=100;     //限制token數最大為100
const int Word_Len=50; //每個token的長度為50以內
const int Sen_len=1000; //Sentence長度限制在1000個字元以內

int main()
{
    //-----------------------------Part 1---------------------
    //delimiter:逗點、空格等用來指示字串切割點的符號
    //token:大字串分切後的小字串
    //語法strtok:string token
    //char* strtok(char*str, const char* delimiters); str:要被切割的字串；delimiters:用來切割的符號(可以不只一個)
    char url[Sen_len];    //設置要被分切的字串，(這邊以網址當例子)
    cin>>url;             //輸入網址           
    char delim[]=".\\/";   //設置分切符號為'.' 和'\'還有'/'    (兩個\才代表'\'符號)
    char word[CNT][Word_Len]={0}; //設置一個用來儲存token的陣列
    int wordCnt=0;        //設置一個用來數token數的變數

    char* start=strtok(url,delim);
    //strtok在做的事:第一次宣告時(假如第一個字不是delimiters的情況)
    //他會把第一個遇到的delimiter換成\0
    //然後return第一個token的address(以pointer的形式)
    //delimiter+1(第一個分切點後的位置)會被他悄悄記起來
    //第二次呼叫他的時候，str會變成nullptr，這個時候被悄悄記起來的位置會變成輸入
    //成為新的起點，在找下一個delimiter把它變成\0，如此往復。
    while(start != nullptr)
    {
        strcpy(word[wordCnt],start);
        wordCnt++;
        start = strtok(nullptr, delim);
    }

    for(int i=0;i<wordCnt;i++)   //印出儲存在陣列中的元素
        cout<<word[i]<<" ";
    
    return 0;
}