#include <iostream>
#include <cstdlib>
using namespace std;

class MyVector{
  private:
    const int n;
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
	bool operator!= (const MyVector& v) const;
	bool operator<  (const MyVector& v) const;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~新增部分~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    double operator[] (int i) const;    //只是要取值的版本
    double& operator[] (int i);         //有可能要更改值的版本，所以回傳值是元素所在的地址，且不宣告為const function
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
bool MyVector::operator!= (const MyVector& v) const{
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~Overloading of index operator: [] ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//只回傳值的function
double MyVector::operator[] (int i) const{
	cout<<"const called"<<endl;
    if(i < 0 || i >= n)
        exit(1); // terminate the program!  這是一個在<cstdlib> 裡定義的函數，他會終止程式並返回狀態碼 1
    return m[i];
}
//可以改值的function
double& MyVector::operator[] (int i) {
	cout<<"non-const called"<<endl;
    if(i < 0 || i >= n)
        exit(1);
    return m[i];
}

int main() // with overloading
{
//-----------------Part 1-------------------------
    double d1[5] = {1, 2, 3, 4, 5};
	MyVector a1(5, d1); 
	cout << a1[3] << endl; 
	a1[1] = 4; // 如果我們沒有call reference 的index overload 版本，那麼a1[1]就只是一個值，相當於對程式說 2=3，左邊只是值而不是容器，當然就會出錯
//-----------------Part 2-------------------------
	double d2[4] = {1, 2, 3, 4};
	MyVector a2(4, d2); 
	const MyVector a3(a1); //把a3 宣告成 constant object
	a2[0] = 999;	//這邊呼叫一次non-const []
	if(a1 == a3)
		cout<< a2[0] << ", " << a3[0]; ////這邊a2又呼叫一次non-const [], 但a3 呼叫的是const []的版本
	//如果我們沒有要修改MyVector的物件的值，那麼在沒有non-const []版本的情況下， a2、a3都會去呼叫const []的版本
	return 0;
}
