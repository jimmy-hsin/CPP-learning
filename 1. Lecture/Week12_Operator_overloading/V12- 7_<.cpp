#include <iostream>
using namespace std;

class MyVector{
  private:
    const int n;
    double* m;
  public:
  //Constructors
    MyVector(int n=0,double m[]=nullptr); //self define constructor，(default constructor include version)
    MyVector(const MyVector& v);          //copy constructor
  //destructor
    ~MyVector(){    delete [] m;    }
  //function
    void print() const;
    bool operator== (const MyVector& v) const; //基本上就是把isEqual 的部分換成 operator==，其中'=='是我們想要overload的操作子
};
MyVector::MyVector(int n, double m[]):n(n){
    this->m=new double[n];  
    for(int i = 0; i < n; i++)
        this->m[i] = m[i];
}
MyVector:: MyVector(const MyVector& v) : n(v.n){
    this->m=new double[n]; 
    for(int i = 0; i < n; i++)
        m[i] = v.m[i];
}

void MyVector::print() const{   
    cout << "(";
    for(int i = 0; i < n - 1; i++)
        cout << m[i] << ", ";
    cout << m[n-1] << ")\n";
}
bool MyVector::operator==(const MyVector& v) const{    
    if(n!=v.n)                                
        return false; 
    for(int i=0;i<n;i++)
        if(m[i]!=v.m[i])
            return false;          
    return true;
}

int main() // with overloading
{
    double d1[5] = {1, 2, 3, 4, 5};
    const MyVector a1(5, d1);
    
    double d2[4] = {1, 2, 3, 4};
    const MyVector a2(4, d2);
    const MyVector a3(a1);
  
    //現在我們可以直接把 == 作為一般操作子來用了
    cout << (a1 == a2 ? "Y" : "N") << "\n";
    //我們在做的事，其實是定義了一個名為.operator==()的function，只不過c++ 允許你用==來呼叫這個function 
    cout << (a1.operator==(a3) ? "Y" : "N") << "\n";
    return 0;
}
