#include <iostream>
using namespace std;

class MyVector{
  private:
    const int n;
    double* m;
  public:
  //Constructors
    MyVector(int n=0,double m[]=nullptr);//self define constructor
    MyVector(const MyVector& v);//copy constructor
  //destructor
    ~MyVector(){    delete [] m;    }
  //function
    void print() const;
    bool operator==(const MyVector& v) const; //基本上就是把isEqual 的部分換成 operator==，'=='是我們想要overload的操作子
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
    
    cout << (a1 == a2 ? "Y" : "N") << "\n";
    cout << (a1 == a3 ? "Y" : "N") << "\n";
    return 0;
}

