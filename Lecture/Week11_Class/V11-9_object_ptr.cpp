#include <iostream>
using namespace std;
/*
為什麼要使用object pointer:
    1.如果開一個object array的話(ex:MyVector v[5])，每個object都會去呼叫自己的default constructor，
      處理器可能會被擠爆，如果使用pointer array，則會在object被宣告時才會建立，操作上會比較有效率
    2.對function傳入ptr有的時候會比直接傳入object來的輕鬆
      pointer的大小通常會比object小的多
      複製pointer比複製object來的容易

Static object arrays
   當我們創建一個object array時
    1.default constructor 會被呼叫
    2.這個情況下我們沒有辦法呼叫其他constructor
    3.我們必須要寫一些其他的function以便對instance variable的值做指派
  解決方法: Dynamic Object arrays
Dynamic Object arrays


*/


int main()
{
//----------------------Part 1-------------------------
//object pointer
    MyVector v(5);
    MyVector* ptrV=&v;
    v.print();
    (*ptrV).print();  //可以用object pointer來呼叫指到的東西的instance function
    ptrV->print();    //***也可以寫成這種形式***

//----------------------Part 2-------------------------
//static object arrays
    MyVector v2[3];  //an object array
    v2[0].print();   //會出現 run-time error

//----------------------Part 3-------------------------
//Dynamic object arrays
    MyVector* ptrV2=new MyVector(5); //() 圓括弧: call constructor   (建立一個dim=5的MyVector)
    ptrV2->print();
    delete ptrV2;

    MyVector* ptrV3=new MyVector[5];//[] 方括弧: 建立arrays      (建立五個MyVector)
    ptrV3[0].print();
    delete [] ptrV3;

    //正確做法:
    MyVector* ptrArray[5];
    for(int i=0;i<5;i++)
        ptrArray[i]=new MyVector(i+1);//在這邊可以呼叫指定的constructor
    
    ptrArray[0]->print();
    //這條要補 delete statements


    return 0;
}


class MyVector
{
private:
    int n;
    int* m;
public:
    MyVector(); //default constructor
    MyVector(int dim,int value=0); //若只傳一個參數進來，第二個的default value為0
    void print();
};

MyVector::MyVector()
{
    n=0;
    m=nullptr;
}
MyVector::MyVector(int dim,int value)
{
    n=dim;
    m=new int[n];
    for(int i=0;i<n;i++)
        m[i]=value;
}


