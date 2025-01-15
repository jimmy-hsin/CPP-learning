#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //---------------------------------------------Part1---------------------------------------------
    cout<<"-------Part 1----------"<<'\n';
    char a[100]="1234567890";
    char* p=strchr(a,'8');
    if(strchr(a,'a')==nullptr)   //字串中找不到字元的時候(會回傳nullptr)
        cout<<"!!!\n";
    cout<<strchr(a,'4')<<"\n";  //回傳4這個字元在記憶體中的位址，
    //但由於char*(某個字串的位址)=傳入字串給cout，因此會print出從4~遇到\0的部分
    cout<<strchr(a,'4')-a<<'\n';      //回傳4這個字元在陣列a的第幾個
    cout<<&p<<'\n';                   //同理 會回傳位址，但用&函式就可以把位址的編碼印出來

    //---------------------------------------------Part2---------------------------------------------
    //在字串中找字元(strchr)
    cout<<"-------Part 2----------"<<'\n';
    char b[100]="this is a book";
    char* q=strchr(b,' ');   //找出字串中的空格
    while(q!=nullptr)//當q有找到空格時
    {
        *q='_';     //q所指向的那個東西(空格的位址)，把它改成底線_
        q=strchr(p,' '); // 後面那個q的value 現在是存成空格的位址，
                         //傳入strchr的效果就會是從那個位址開始往下搜尋下一個空格，
                         //下一個空格的位址再存進q裡面，使之不會成為nullptr，再次進入while迴圈
    }
    cout<<b<<'\n';


    //---------------------------------------------Part3---------------------------------------------
    //在字串中找字串(strstr)
    cout<<"-------Part 3----------"<<'\n';
    char c[100]="this is a book";
    char* r=strstr(c,"is");  //在字串中找is 並改為大寫IS
    while(r!=nullptr)
    {
        *r='I';   //不可以使用*r="IS"，因為傳入字串(而不是字元)給ptr會使系統另外開一個唯讀空間寫入IS，再使ptr指向這個新的空間
        *(r+1)='S';
        r=strstr(r,"is");
    }
    cout<<c<<'\n';

    return 0;
}