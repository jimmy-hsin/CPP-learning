#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
    double distToOri()  //內部自訂的function，相當於設定一個自訂變數的性質，
    {
        return sqrt(pow(x,2)+pow(y,2));//sqrt: 取根號 ;   pow(a,b): 回傳a的b次方的值
    }
    //另類寫法:
    double distOri();   
};
//另類寫法:
double Point::distOri()
{
    return sqrt( pow(x,2) + pow(y,2) );
}



int main()
{
    Point a={3,4};
    cout<<a.distToOri(); //distToOri()相當於Point的子變數

    return 0;

}