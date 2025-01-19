#include <iostream>
using namespace std;

class MyVector{
  private:
    const int n;
    double* m;
  public:
  //Constructors
    MyVector(int n=0,double m[]=nullptr); 
    MyVector(const MyVector& v);          
  //destructor
    ~MyVector(){    delete [] m;    }
  //function
    void print() const;
    bool operator== (const MyVector& v) const; 
//~~~~~~~~~~~~~~~~~~~~~~這段新增的項目~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    bool operator!= (const MyVector& v) const;
    bool operator<  (const MyVector& v) const;
    
};
MyVector::MyVector(int n, double m[]):n(n){
    this->m=new double[n];  
    for(int i = 0; i < n; i++)
        this->m[i] = m[i];
}
MyVector:: MyVector(const MyVector& v) : n(v.n){
    this->m=new double[n]; 
    for(int i = 0; i < n; i++)
        this->m[i] = v.m[i];
}

void MyVector::print() const{   
    cout << "(";
    for(int i = 0; i < n - 1; i++)
        cout << this->m[i] << ", ";
    cout << this->m[n-1] << ")\n";
}

bool MyVector::operator== (const MyVector& v) const{    
    if(this->n!=v.n)                                
        return false; 
    for(int i=0;i<n;i++)
        if(this->m[i]!=v.m[i])
            return false;          
    return true;
}
//我們寫的新的 !=
bool MyVector::operator!= (const MyVector& v) const{
    return !(*this == v);     //this是指向自己的指標，對她做dereference 就會變成自己
    //我們直接調用 == 的結果，就不用再自己寫一大串
}
//我們寫的新的 <
bool MyVector::operator< (const MyVector& v) const{
    if(this->n!=v.n)                                
        return false; 
    for(int i=0;i<n;i++)
        if(this->m[i] >= v.m[i])    //相較於==，就改這一行
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
    cout << (a1 < a3 ? "Y" : "N") << "\n";
    return 0;
}
