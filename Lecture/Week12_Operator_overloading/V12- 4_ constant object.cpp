#include <iostream>
using namespace std;

class MyVector{
  private:
    const int n;
    int* m;
  public:
    MyVector(); 
    MyVector(int dim,int v[]);  //constructor
    MyVector:: MyVector(const MyVector& v); //copy constructor
/*
  如果一個object被宣告成const 的話，那麼他只能呼叫也有被宣告成const 的function
  而const function 的操作也不能修改到class 裡的變數，不然會compilation error
  const function 還是能被一般普通的object呼叫
*/
    void print() const;  
    bool isEqual(const MyVector& v) const;
};

MyVector::MyVector():n(0){  //由於n已經被const 宣告了，所以要用member initializer的寫法
    m=nullptr;
}
//也可以寫成下面這樣:
MyVector::MyVector() : n(0), m(nullptr) {}

//!!!***如果member variable 的初始化都是簡單形式的話，建議都用member initializer的寫法***!!!

MyVector::MyVector(int n, int m[]):n(n)
{
  for(int i = 0; i < n; i++)
    this->m[i] = m[i];
}

MyVector:: MyVector(const MyVector& v) : n(v.n)
{
  m = new double[n];
  for(int i = 0; i < n; i++)
    m[i] = v.m[i];
}

void MyVector::print() const{   //這邊也要記得補const，因為有可能會有overloading (沒有const)的版本，所以要保持一致才知道你在講誰
    cout << "(";
    for(int i = 0; i < n - 1; i++)
        cout << m[i] << ", ";
    cout << m[n-1] << ")\n";
}
//const 放在最左邊跟放在最右邊意思不一樣，放在最左邊的意思是回傳值是一個constant variable，最右邊代表這是一個constant function
bool MyVector::isEqual(const MyVector& v) const{    
    if(n!=v.n)                                
        return false; 
    
    for(int i=0;i<n;i++)
        if(m[i]!=v.m[i])
            return false;          
    return true;
}
//要判斷一個function能不能成為constant function很簡單，看看function 裡面有沒有 '=' (賦值)就知道了
//而其他function操作中我們也要避免 constant variable 被放到 '=' 的左邊

int main()
{
  //有的時候我們會希望建立一個variable都不會被更動的物件，比如說座標原點(dimension和位置都不變動)
  double d[3] = {0, 0, 0};
  const MyVector ORIGIN_3D(3, d);
}
