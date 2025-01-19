#include <iostream>
using namespace std;
/*
    Operator overloading:
        1.限制
            a.不是所有的operator都可以做overloading
            b.不能改變Operands的數量，例如除法一定是兩個argument，不能說我現在有一個除法可以傳入三個operands
            c.不能create 新的 operators，只能用已經有的東西 
*/
class MyVector
{
private:
    int n;
    double* m;
public:
  //Constructors
    MyVector();//default constructor
    MyVector(int dim,double v[]);//self define constructor
    MyVector(const MyVector& v);//copy constructor
  //destructor
    ~MyVector(){
        delete [] m;
    }
  //function
    void print();
    bool isEqual(const MyVector& v);//比較現在這個object跟傳入值v
};
//如果有協其他constuctor，那系統就不會幫你做default constuctor，所以如果有寫其他constuctor的話，那default constuctor也應該自己定義好
MyVector::MyVector() //default constuctor
{   n=0;
    m=nullptr;              
}
MyVector::MyVector(int dim, double v[]) //self define constuctor
{   n=dim;
    m=new double[dim];   
    for(int i=0;i<dim;i++)
        m[i]=v[i];          
}
MyVector::MyVector(const MyVector& v)    //copy constuctor
{   n=v.n;
    m=new double[n];    //先new出一塊空間，再把V值傳進去，避免shallow copy
    for(int i=0;i<n;i++)
        m[i]=v.m[i];        
}

void MyVector::print()
{   cout<<"(";
    for(int i=0;i<n-1;i++)
        cout<<m[i]<<",";
    cout<<m[n-1]<<")\n";    
}

bool MyVector::isEqual(const MyVector& v){    //如果不用reference的話，傳入的值會呼叫copy constructor，會耗費很多資源
    if(n!=v.n)                                //而加const 是為了避免reference 被改掉
        return false; 
    
    for(int i=0;i<n;i++)
        if(m[i]!=v.m[i])
            return false;          
    return true;
}

int main()
{
    double d1[5]={1,2,3,4,5};
    MyVector a1(5,d1);

    double d2[4]={1,2,3,4};
    MyVector a2(4,d2);

    MyVector a3(a1);

    cout<<(a1.isEqual(a2)? "Y":"N")<<endl;
    cout<<(a1.isEqual(a3)?"Y":"N")<<endl;

    return 0;
}
