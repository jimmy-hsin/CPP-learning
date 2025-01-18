#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
    //這邊設了一個計算point 到原點距離的 function
    double distToOri()  //內部自訂的function，相當於設定一個自訂變數的性質
    {
        return sqrt(pow(x,2)+pow(y,2));//sqrt: 取根號 ;   pow(a,b): 回傳a的b次方的值
    }
    //另類寫法:
    double distToOri_2();   
};
//另類寫法:
double Point::distToOri_2()
{
    return sqrt( pow(x,2) + pow(y,2) );
}



int main()
{
    Point a={3,4};
    cout<<a.distToOri(); //distToOri()相當於Point的子變數

    return 0;

}
