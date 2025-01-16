#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    //****************************************Part3***********************************************
    //String Comparison
    //strcmp 跟 strncmp
    //int strcmp(const char* str1, const char* str2); 比較兩個字串有沒有一樣
    //int strncmp(const char* str1, const char* str2, unsigned int n); 比較兩個字串的前n個字有沒有一樣，(n須為正整數)
    //若一樣return 0; 若str1的排序比str2前面 return -1; 反之return 1
    cout<<'\n'<<"-------Part 3----------"<<'\n';
    char x[10]="the";
    char y[10]="they";
    char z[10]="them";
    cout<<strcmp(x,y)<<'\n';               //x在y前面，回傳負數(-1)
    cout<<strcmp(y,z)<<" "<<strncmp(y,z,2);//z在y前面，回傳正數(1); y&z的前兩個字元一樣，回傳0

    //****************************************Part4***********************************************
    //String copy
    //char* strcpy(char* destination, const char* source);
    //copy string from source to destination
    cout<<'\n'<<"-------Part 4----------"<<'\n';
    char aa[20]="watermelon";
    char bb[20]="orange";
    cout<<aa<<'\n';   //印出watermelon
    strcpy(aa,bb);    //將orange/0 裝進aa裡
    cout<<aa<<'\n';   //此時會印出orange，但尾巴的lon沒有消失
    cout<<aa+7<<'\n'; //印出lon
    aa[6]='e';        //改掉/0的部分
    cout<<aa;  
}
