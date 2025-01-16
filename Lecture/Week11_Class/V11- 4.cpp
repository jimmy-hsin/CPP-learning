#include <iostream>
using namespace std;

class Myvector
{
private:
    int n;
    int* m;    //為了做動態陣列配置，所以使用ptr以便之後new出一塊空間
public:
    void init();
    void init(int dim);
    void init(int dim,int value);
    void print();
};
void Myvector::init()
{
    n=0;
    m=nullptr;
}
void Myvector::init(int dim)
{
    init(dim,0);   //call下面有兩個argument的function
}
void Myvector::init(int dim, int value)
{
    n=dim;
    m-new int[n];
    for(int i=0;i<n;i++)
        m[i]=value;
}
