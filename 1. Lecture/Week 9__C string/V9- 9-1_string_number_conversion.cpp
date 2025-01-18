#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //****************************************Part1***********************************************
    cout<<"-------Part 1----------"<<'\n';
    
    //Array to number
    char a[10]="1234";
    cout<<atoi(a)*2<<'\n';  //atoi: array to int
    //限制:只能含有一個負號(-)
    char b[10]="-12.34";
    cout<<atof(b)/2<<'\n';  //atof: array to float
    //限制:只能含有一個負號(-)跟一個小數點(.)

    //****************************************Part2***********************************************
    cout<<'\n'<<"-------Part 2----------"<<'\n';
    //Number to array
    //itoa: integer to array
    //char* itoa(int value, char* str, int base)::-->  vlaue:傳入的整數， str(指標):用來存字串的位址，  base: 底數是使用2進為還是10進位 等
    
    char c[10]={0};   //先開一個array用來存轉換出來的字串
    itoa(123,c,2);     //向c存入 123轉成2進制的結果()
    cout<<c<<'\n';     //印出1111011
    itoa(123,c,10);    //向a存入 123轉成10進制的結果
    cout<<c<<" "<<c[2]<<'\n'; //123 3    //c[2]是c這個array中 第三個位置存的字元，所以是3

}
