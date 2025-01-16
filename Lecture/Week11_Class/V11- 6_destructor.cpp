#include <iostream>
using namespace std;

/*   Destructor
    在物件的生命週期要結束的時候會被呼叫
    Destructor must be public and have no parameter
    Compiler也有提供一個default Destructor, which does nothing
    如果有定義Destructor，則compiler不會加 default Destructor
    
    *1.Destructor的名稱，則是class的名稱前面加上"~"
    *2.Destructor主要做的事就是將動態配置記憶空間釋出

*/

class MyVector
{
private:
    int n;
    int* m;
public:
    MyVector();
    MyVector(int dim, int value=0);  //Constructor
    ~MyVector(); //Destructor
};

MyVector:: ~MyVector()
{
    delete [] m;
}
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

int main()
{
    if(true)
        MyVector v1(1); //Destructor要做的就是在block結束前把記憶體釋出
                        //不然就可能程式跑完出現memory leak
    return 0;
}
