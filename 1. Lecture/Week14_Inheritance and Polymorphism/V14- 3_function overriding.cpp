#include <iostream>
#include <cstdlib>
using namespace std;

class MyVector{
/**/protected://讓其他人可以繼承 
    int n;
    double* m;
  public:
  //Constructors
    MyVector(int n=0,double m[]=nullptr); 
    MyVector(const MyVector& v);      //copy constructor    
  //destructor
    ~MyVector();
  //function
    void print() const;
  //Comparison Operator
    bool operator== (const MyVector& v) const; 
    bool operator!= (const MyVector& v) const;
    bool operator<  (const MyVector& v) const;
  //Assignment operator
    double operator[] (int i) const;    
    double& operator[] (int i);   
    const MyVector& operator= (const MyVector& v);
    const MyVector& operator+=(const MyVector& v);
//~~~~~~~~~~~~~~~~~因為要取v.n的值，但v.n是private member，所以要宣告friend~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    friend const MyVector operator+ (const MyVector& v, double d);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
};

const MyVector operator+ (const MyVector& v, double d);
const MyVector operator+ (const MyVector& v1, const MyVector& v2);
const MyVector operator+(double d, const MyVector& v);

//Constructor
MyVector::MyVector(int n, double m[]):n(n){
    this->m=new double[n];  
    for(int i = 0; i < n; i++)
        this->m[i] = m[i];
}
//Copy Constructor
MyVector:: MyVector(const MyVector& v) : n(v.n){
    this->m=new double[n]; 
    for(int i = 0; i < n; i++)
        m[i] = v.m[i];
}
//destructor
MyVector:: ~MyVector(){    
  delete [] m;    
}

//------------------------Functions---------------------------------------------------
void MyVector::print() const{   
    cout << "(";
    for(int i = 0; i < n - 1; i++)
        cout << m[i] << ", ";
    cout << m[n-1] << ")\n";
}

//----------------------------Operator Overload-----------------------------------------
//~~~~~~~~~~~~~~~~~~~~~Comparison overload~~~~~~~~~~~~~~~~~~~~
bool MyVector::operator==(const MyVector& v) const{    
    if(n!=v.n)                                
        return false; 
    for(int i=0;i<n;i++)
        if(m[i]!=v.m[i])
            return false;          
    return true;
}
bool MyVector::operator!= (const MyVector& v) const { 
	return !(*this == v); 
}
bool MyVector::operator< (const MyVector& v) const{
    if(this->n!=v.n)                                
        return false; 
    for(int i=0;i<n;i++)
        if(this->m[i] >= v.m[i])   
            return false;          
    return true;
}
//~~~~~~~~~~~~~~~~~Assignment overload~~~~~~~~~~~~~~~~~
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

//---------------------------------Global functions-----------------------------------
//把 + 相關的operation 都宣告成 global function， 同時把第一個function 宣告成friend of MyVector
const MyVector operator+ (const MyVector& v, double d){ 
	MyVector sum(v);//用copy constructor 複製出一個物件
	for(int i = 0; i < v.n; i++)
        sum[i] += d; // pairwise addition
	return sum;
}
const MyVector operator+ (const MyVector& v1, const MyVector& v2){
    MyVector sum(v1);
    sum += v2;
    return sum;
}

const MyVector operator+(double d, const MyVector& v){
    return v+d; // using the previous definition
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
//主要部分，前面的都是之前的code


class MyVector2D : public MyVector {	
public:

	MyVector2D();
	MyVector2D(double m[]);
//如果定義了一個名稱跟parent一樣的function，那parent的function 就會被覆蓋掉
    void print() const;

};
MyVector2D::MyVector2D()    {     this->n = 2;    }
MyVector2D::MyVector2D(double m[]) : MyVector(2, m) {} 

void MyVector2D::print() const{
    cout << "2D: ";
    MyVector::print();
}

int main() {
    double i[2] = {1, 2};
    MyVector2D v(i);
    v.print();
    cout << endl;
    v.MyVector::print(); //如果還是想用parent的function 也是可以，定義parent的命名域就好

    //但要注意，假如你定義了一個non-const版本的function，但parent中同名稱的function 是const的，則child 的 non-const function 仍會覆蓋 parent的const-function  
    //這會導致子類別的 const 物件找不到const 版本的function，會出現error
    cout << v[1] << endl;
    return 0;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
