#include <iostream>
#include <cstdlib>
using namespace std;
/*Other issues:
    1. 為了data hiding 和資料保護，我們通常會希望將assignment operator 和 copy constructor 作為private member 藏起來，
       避免被使用者直接在main function 裡就能直接操作
    2. 如果在member variable 有 pointer 的情況下 copy constructor, assignment operator, destructor 才有需要寫
        因為要防止shallow copy, 及釋放記憶體；
        如果沒有用到pointer，則他們都不需要寫
*/
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
    bool operator== (const MyVector& v) const; 
	bool operator!= (const MyVector& v) const {    return !(*this == v);     }
    bool operator<  (const MyVector& v) const;
    double operator[] (int i) const;    
    double& operator[] (int i);   
//Assignment operator
    const MyVector& operator= (const MyVector& v);
    const MyVector& operator+=(const MyVector& v);
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/* Default assignment operator: shallow copy
MyVector& MyVector::operator= (const MyVector& v){ 
    this->n = v.n;
    this->m = v.m;
}
*/
//正確做法，deep copy
const MyVector& MyVector::operator= (const MyVector& v){ //void 的話就只能賦值，如果我們使用MyVector& 作為回傳值就可以允許cascade operation(e.g.: a1=a2=a3)，
//宣告const就代表回傳值不能被放在等號左邊，避免一些奇怪的操作 ex: (a1 = a2) = a3
    //if(this == &v || *this== v) return; //前面那個是比較地址是不是同一個(也就是傳入值是不是自己) ，另外一個是比較傳入值(另一個物件)是否跟自己相等
    if(*this == v) //如果兩者相等，就不用做任何操作
        return *this;
    if(this->n != v.n){        //如果兩的大小不一樣
        delete [] this->m;     //那就要把原本空間release，重新調整所需大小
        this->n = v.n;
        if(v.n == 0)
            this->m = nullptr;
        else
            this->m=new double[this->n];
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
