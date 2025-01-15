#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
    int z;
};


int main()
{
    //--------------------Part 1------------------------
    cout<<"-------Part 1----------"<<'\n';
    Point A[20];

    for(int i=0;i<10;i++)
        A[i]={i}; //理論上應該要放三個值，若只放一個的話，只有A[i].x會被宣告，其他剩餘的變數會被設定為0

    for(int i=0;i<20;i++)
        cout<<A[i].x<<" "<<A[i].y<<" "<<A[i].z<<'\n';
    
    return 0;
}