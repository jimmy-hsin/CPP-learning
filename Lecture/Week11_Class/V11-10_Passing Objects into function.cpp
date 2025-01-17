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
   
    //  --------Passing Value into  a function-----------------------------------------
    MyVector sum1(MyVector v1,MyVector v2,MyVector v3)
    {
        int n=v1.getN();
        int* sov=new int[n];
        for(int i=0;i<n;i++)
            sov[i]=v1.getM(i)+v2.getM(i)+v3.getM(i);
        MyVector sumOfVec(n,sov);
        return sumOfVec;
    }
    
    //  --------Passing object pointer into  a function-----------------------------
    MyVector sum2(MyVector* v1,MyVector* v2,MyVector* v3)
    {
        int n=v1->getN();
        int* sov=new int[n];
        for(int i=0;i<n;i++)
            sov[i]=v1->getM(i)+v2->getM(i)+v3->getM(i);
        MyVector sumOfVec(n,sov);
        return sumOfVec;
    }

    //  --------Passing object reference into  a function----------------------
    MyVector sum3(MyVector& v1,MyVector& v2,MyVector& v3)   //這個情況下只會建立一個MyVector的object
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
