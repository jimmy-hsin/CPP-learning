#include <iostream>
using namespace std;

/*
    注意!!! 使用c語言的struct會有記憶體對齊的現象，通常以8byte 為一個單位，因此需要謹慎排列struct中的member element的順序
    int: 4byte
    char:1 byte
    bool: 1 byte
    short: 2 byte
    long long : 8 byte
    double: 8 byte
    
*/
 //ex1:以下的排序，一個struct的大小為16byte
    struct mystruct{
        int a;    //4byte
        bool b;   //1byte 第一排8byte還沒塞滿，可以繼續塞
        long long c;    //8byte，第一排塞不下了，換下一排
    };
    
//ex2:以下的排序，一個struct的大小為24byte
    struct mystruct{
        int a; //4byte
        long long c;    //8byte，第一排塞不下了，換下一排
        bool b;    //1byte，第二排塞滿了，換下一排
    };


struct Point
{
    int x;
    int y;
};

void reflect(Point& a)  //設定一個function 負責把Point.x跟Point.y位置中存取的值互換
{                       //相當於把座標對x=y的直線做對稱
    int temp=a.x;
    a.x=a.y;
    a.y=temp;
}

int main()
{
    //-----------------------------Part 1---------------------
    cout<<"-------Part 1----------"<<'\n';

    Point a={10,20};
    cout<<"交換前:"<<a.x<<" "<<a.y<<"\n";

    reflect(a);
    
    cout<<"交換後:"<<a.x<<" "<<a.y<<"\n";
    
    //-----------------------------Part 2---------------------
    cout<<"-------Part 2----------"<<'\n';

    Point b[3];
    cout<<"一個Point的大小: "<<sizeof(Point)
        <<" ; b的大小:"<<sizeof(b)
        <<" ; b的地址:"<<&b<<"\n";
    for(int i=0;i<3;i++) //印出b, b.x, b.y的地址 
        cout<<i<<":"
            <<&b[i]  <<" "
            <<&b[i].x<<" "
            <<&b[i].y<<"\n";
    
    Point* c=new Point[3]; //新創一個存有3個point的陣列
    cout<<sizeof(c)<<"\n"; //印出 Point的指標的大小

    delete [] c;
    c=nullptr;

    return 0;
}
