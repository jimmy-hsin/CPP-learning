#include <iostream>
using namespace std;

int main()
{

}


class MyVector
{
  private:
    int n;
    int* m;
  public:
    MyVector(); //default constructor
    MyVector(int dim,int value=0); //若只傳一個參數進來，第二個的default value為0
    MyVector(int d,int v[]);
    void print();
    int const getN()
        {return n;}
    int getM(int i)
        {return m[i];}
   
    //  ----------------------Passing Value into a function-----------------------------------------
    MyVector sum1(MyVector v1,MyVector v2,MyVector v3)        //比較不好，因為這種方法每次呼叫都會需要多新建3個object
    {
        int n=v1.getN();
        int* sov=new int[n];
        for(int i=0;i<n;i++)
            sov[i]=v1.getM(i)+v2.getM(i)+v3.getM(i);
        MyVector sumOfVec(n,sov);
        return sumOfVec;
    }
    
    //  ----------------------Passing object pointer into a function-----------------------------
    MyVector sum2(MyVector* v1,MyVector* v2,MyVector* v3)    //稍微好一點，但需要創建3個pointer
    {
        int n=v1->getN();
        int* sov=new int[n];
        for(int i=0;i<n;i++)
            sov[i]=v1->getM(i)+v2->getM(i)+v3->getM(i);
        MyVector sumOfVec(n,sov);
        return sumOfVec;
    }
        /*
          關於使用object pointer並進行保護的寫法:
          void myFunction(const MyVector* const ptr)
            第一個const 是確保ptr指向的物件不被修改，第二個const 是確保ptr本身的內容(即指向的位址不被修改)
            可以根據自己的需要來做調整
        */

    //  ----------------------Passing object reference into a function----------------------
    MyVector sum3(MyVector& v1,MyVector& v2,MyVector& v3)   //比較好，要什麼值直接去object的位置取。  這個情況下只會建立一個MyVector的object(也就是回傳值sumOfVec)，
    {
        int n=v1.getN();
        int* sov=new int[n];
        for(int i=0;i<n;i++)
            sov[i]=v1.getM(i)+v2.getM(i)+v3.getM(i);
        MyVector sumOfVec(n,sov);
        return sumOfVec;
    }

    //  ----------------------Passing constant object reference into a function----------------------
    MyVector sum4(const MyVector& v1,const MyVector& v2,const MyVector& v3)   //最好，因為我們通常需要確保傳入的物件，他不會被修改，所以用const保護他
    {
        int n=v1.getN();
        int* sov=new int[n];
        for(int i=0;i<n;i++)
            sov[i]=v1.getM(i)+v2.getM(i)+v3.getM(i);
        MyVector sumOfVec(n,sov);
        return sumOfVec;
    }


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
MyVector::MyVector(int d,int v[])
{
    n=d;
    m=new int[d];
    for(int i=0;i<n;i++)
        m[i]=v[i];
}
