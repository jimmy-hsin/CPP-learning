#include <iostream>
using namespace std;

int main()
{
    int x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            bool safe=true;
            if(i==x1 || i==x2 || i==x3)
                safe=false;
            else if (j==y1 || j==y2 || j==y3)
                safe=false;
            else if(abs(i-x1)==abs(j-y1) ||
                    abs(i-x2)==abs(j-y2) ||
                    abs(i-x3)==abs(j-y3) )
                safe=false;
            else
                cout<<i<<" "<<j<<endl;        
        }
    }
}