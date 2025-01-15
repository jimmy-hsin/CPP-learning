#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int n=a.length();              //去看輸入的數字長度有多少
    char x[4]={48,48};          //先設一個陣列都為0(ascii code:48)
    for(int i=n;i>=0;i--)          //把數字從尾巴塞進x
        x[3+i-n]=a[i];
        
    for(int j=0;j<3-1;j++)          //bubble sorting
        for(int i=0;i<3-j;i++)
            if(x[i]<x[i+1])
            {
                char temp=x[i];
                x[i]=x[i+1];
                x[i+1]=temp;
            }

    for(int i=0;i<3;i++)            //Print out
        cout<<x[i];
}