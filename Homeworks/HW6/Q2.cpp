#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num;      //選第幾大的數字
    string a;     //要輸入的數字
    cin>>a>>num;
    int n=a.length();              //去看輸入的數字長度有多少
    char x[4]={48,48,48,'\0'};          //先設一個陣列都為0(ascii code:48)
    for(int i=n;i>=0;i--)          //把數字從尾巴塞進x
        x[i+3-n]=a[i];

    for(int j=0;j<3-1;j++)          //bubble sorting
        for(int i=0;i<3-j;i++)
            if(x[i]<x[i+1])
            {   char temp=x[i];
                x[i]=x[i+1];
                x[i+1]=temp;
            }
    
    char x2[6][4];
    if(x[0]==x[1] || x[1]==x[2]) //有兩個重複的話
    {
        x2[0][1]=x2[2][0]=x2[2][2]=x2[4][1]= x[1];
        x2[0][0]=x2[4][2]= x[0];
        x2[0][2]=x2[4][0]= x[2];
        if(x[0]>x[1])
            x2[2][1]=x[0];
        else
            x2[2][1]=x[2];

        for(int i=0;i<3;i++)
        {
            x2[1][i]=x2[0][i];
            x2[3][i]=x2[2][i];
            x2[5][i]=x2[4][i];
        }    
    }
    else
    {
        x2[0][0]=x2[1][0]=x2[2][1]=x2[3][2]=x2[4][1]=x2[5][2]= x[0];
        x2[0][1]=x2[1][2]=x2[2][0]=x2[3][0]=x2[4][2]=x2[5][1]= x[1];
        x2[0][2]=x2[1][1]=x2[2][2]=x2[3][1]=x2[4][0]=x2[5][0]= x[2];
        x2[0][3]=x2[1][3]=x2[2][3]=x2[3][3]=x2[4][3]=x2[5][3]= '\0';
    }


    cout<<atoi(x2[num-1]);  
}