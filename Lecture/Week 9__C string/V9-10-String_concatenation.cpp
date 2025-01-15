#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //****************************************Part1***********************************************
    //String concatenation: 串接字串
    //char* strcat(char* dest, const char* source);
    //會將dest 尾巴的\0換成 source的字首，接起來之後完成串接
    cout<<"-------Part 1----------"<<'\n';
    char a[20]="watermelon";
    char b[20]="orange";
    cout<<a<<'\n';

    strcat(a,b);
    cout<<a<<endl;

    //Achtung!!! 要注意a的空間夠不夠放串接後的字串，否則容易出現memory leak， 造成run-time error
    /* 
    For example:
        char* a;             //a指向一個未知的地方
        char b[100]="orange";
        strcat(a,b);
    */

    //****************************************Part2***********************************************
    cout<<"-------Part 2----------"<<'\n';
    //strncpy:只把source的前n個字複製到dest上面:--> strncpy(dest, source, n)
    //strncat:只把source的前n個字串接到dest上面:--> strncat(dest, source, n)
    //當source的大小<n時，則將全部摳過去，然後補\0
    char c[15]="watermelon";
    char d[20]="orange";
    cout<<sizeof(c)<<","<<strlen(c);
    strncat(c,d,sizeof(c)-strlen(c)-1);  //sizeof(c): c被配置了幾個空格;strlen(c):目前字串佔了幾個空格;(-1):多留一個空格放\0
    cout<<c<<endl;//"watermelonoran"
    
   
}