#include <iostream>
using namespace std;

int main()
{
    int g,a;
    cin>>g>>a;
    if(g==1&a>=18 || g==0&a>=16)
        cout<<"Yes";
    else
        cout<<"No";   
}