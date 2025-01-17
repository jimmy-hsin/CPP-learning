#include <iostream>
#include <cstring>
using namespace std;

void reverse(char p[]);
void print(char* p);
int main()
{
    char s[100]="12345";
    reverse(&s[1]);        //傳入s[1]的地址(所以s[0]的資訊不會被動到)
    print(s);
    return 0;
}
void reverse(char p[])    //基本上就是傳入一個指標
{
    int n=strlen(p);       //取得p的字串長度，也就是傳入的指標 到 陣列結尾(也就是\0) 的長度
    /* 講義寫法:
    char* temp=new char[n];//新增一個字串 temp
    for(int i=0;i<n;i++)   //將p字串 倒著裝進 temp字串
        temp[i]=p[n-1-i];
    for(int i=0;i<n;i++)   //將temp字串重新裝回 p字串
        p[i]=temp[i];
        
    delete [] temp;        //砍掉temp，釋放temp字串的記憶體空間
    */

    //高效寫法:
    for(int i=0;i<n/2;i++)   //將p字串 倒著裝進 temp字串
    {
        swap(p[i], p[n-1-i]);
    }
}

void print(char* p)
{
    cout<<p<<"\n";
}
