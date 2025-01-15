#include <iostream>
#include <cmath>
using namespace std;

int yn(int* row,int up,int down)
{
    int boo=0;
    for(int i=up;i<down;i++)
    {
        if(*(row+i)!=0)
            boo++;
    }
    return boo;
}


int main()
{
   int a[10]={0,1,0,0,0,0,1,0,0,0};
   int *x= &a[0];
   int yy=yn(&a[0],1,6);
   cout<<yy;

   //int a[]={1,2,5};
   //int *x = &a[0];


}
