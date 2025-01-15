#include <iostream>
using namespace std;


//struct 
void vectorA(int x1, int y1, int x2, int y2, int& rx,int& ry) //定義一個計算向量的function
{                                                            //rx,ry 是call by reference，因此會找到原來宣告變數的那個地址，更改他的值
    rx=x2-x1;  //計算X分量
    ry=y2-y1;  //計算y分量
}

//struct 宣告時應首字母大寫，以便一目瞭然
struct Point  //宣告一個新的資料型態叫做 Point，就類似於整數型態叫int一樣
{
    int x;
    int y;
};       //這邊要記得打分號

Point vector(Point A, Point B)   //創建一個function，其中回傳值為Point，傳入值為兩個Point值
{
    Point vecXY; //宣告一個新的變數
    vecXY.x=B.x-A.x;// vecXY的x為傳入值中B的X值減去A的X值
    vecXY.y=B.y-A.y; //同理
    return vecXY; //回傳
}


int main()
{
    int x1= 0, x2= 0;
    int y1=10, y2=20;
    int rx= 0, ry= 0;
    vectorA(x1,y1,x2,y2,rx,ry);
    cout<<rx<<" "<<ry<<"\n";
    //--------------------Part 1------------------------
    Point a={0,0},b={10,20}; //有兩個值的新變數要用{}來包住
    Point vecAB=vector(a,b);
    cout<<vecAB.x<<" "<<vecAB.y<<'\n';
    return 0;
}