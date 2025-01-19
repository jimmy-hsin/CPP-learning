#include <iostream>
#include <cstdlib>
using namespace std;

class MyVector{
  private:
    int n;
    double* m;
  public:
  //Constructors
    MyVector(int n=0,double m[]=nullptr); 
    MyVector(const MyVector& v);      //copy constructor    
  //destructor
    ~MyVector(){    delete [] m;    }
  //function
    void print() const;
//Comparison Operator
    bool operator== (const MyVector& v) const; 
    bool operator!= (const MyVector& v) const {    return !(*this == v);     }
    bool operator<  (const MyVector& v) const;
//Assignment operator
    double operator[] (int i) const;    
    double& operator[] (int i);   
    const MyVector& operator= (const MyVector& v);
    const MyVector& operator+=(const MyVector& v);
//Arithmetic operators
    const MyVector& operator+ (const MyVector& v);
    const MyVector& operator+ (double x);
};
//Constructor
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
//Functions
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
bool MyVector::operator< (const MyVector& v) const{
    if(this->n!=v.n)                                
        return false; 
    for(int i=0;i<n;i++)
        if(this->m[i] >= v.m[i])   
            return false;          
    return true;
}
double MyVector::operator[] (int i) const{
    if(i < 0 || i >= n)
        exit(1); 
    return m[i];
}
double& MyVector::operator[] (int i) {
    if(i < 0 || i >= n)
        exit(1);
    return m[i];
}

const MyVector& MyVector::operator= (const MyVector& v){ 
    if(*this == v)      return *this;
    if(this->n != v.n){        //如果兩的大小不一樣
        delete [] this->m;     //那就要把原本空間release，重新調整所需大小
        this->n = v.n;
        if(v.n == 0)    this->m = nullptr;
        else            this->m=new double[this->n];
    }
    for(int i = 0; i < n; i++)
        this->m[i] = v.m[i];
    return *this;
}
const MyVector& MyVector::operator+= (const MyVector& v){
    if(this->n == v.n)
        for(int i = 0; i < n; i++)
            this->m[i] += v.m[i];  
    return *this;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
const MyVector MyVector::operator+ (const MyVector& v){ //回傳一個實體而不是reference是因為如果回傳reference的話，sum 的生命週期只會在這個function裡面，
											  //之後就會被消滅，那之後再對function的結果做其他操作會容易出錯
	MyVector sum(*this);//用copy constructor 複製出一個物件
	sum+=v; 		//再用+=操作把sum跟v 相加之後回傳sum自己
	return sum;
}
const MyVector operator+ (double x){
    MyVector sum(*this);
    for(int i=0;i<n;i++)
        sum.m[i]+=x;
    return sum;
}

int main() // with overloading
{
    double d1[3] = {4, 8, 7};
    double d2[4] = {1, 2, 3, 4};
    MyVector a1(3, d1);
    MyVector a2(4, d2);
    a2 = a1; // 如果沒有自己寫operator=，那系統預設就會是shallow copy，a2、a1的m會指向同一塊空間
    a2.print();
    a2[0]=9;
    
    MyVector a3=a2;
    cout<<a3[0];
}
