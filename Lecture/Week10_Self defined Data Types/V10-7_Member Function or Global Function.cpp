#include <iostream>
#include <cmath>
using namespace std;

struct Point 
{
    int x;
    int y;
    void reflect();
    void print();
    double distance(Point p);
};

void Point::reflect()  //struct 下的方法，將xy數值互換
{
    int temp=x;
    x=y;
    y=temp;
}

void Point::print() //strcut 下的function, 把x,y印出來
{
    cout<<x<<","<<y<<"\n";
}

double Point::distance(Point p)  //計算被宣告的Point到已存在的點p之間的距離 
{
    double dist=sqrt( pow(x - p.x, 2) + pow(y - p.y, 2) );
    return dist;
}
//千萬不要這樣寫: 
/*
Bad example 1: 
    double Point::distance(Point p)      //只是在計算P點的距離而已，計算結果跟自己沒有關係，沒必要變成一個member function
    {
        double dist=sqrt( pow(p.x, 2) + pow(p.y, 2) );   
        return dist;
    }

Bad example 2: 
    double Point::distance(Point p)      //只是在計算自己點的距離而已，計算結果跟P點沒有關係，沒必要把P點當作傳入的argument
    {
        double dist=sqrt( pow(x, 2) + pow(y, 2) );   
        return dist;
    }

*/

int main()
{
    Point a={20,10};
    Point b={5,2};
    a.print();
    b.print();
    
    a.reflect();
    b.reflect();
    
    a.print();
    b.print();
    cout<<a.distance(b);
    return 0;
}
