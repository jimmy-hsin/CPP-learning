#include <iostream>
#include <cstdlib>
#include "MyVector.h"
using namespace std;

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
