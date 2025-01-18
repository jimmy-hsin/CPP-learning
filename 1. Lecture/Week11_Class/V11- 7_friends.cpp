#include <iostream>
using namespace std;

//   *1.Getter: 去get private variable 的值
//   *2.Setter: 用來modify private variable的值
//   *3.Friends: 可以宣告一些global function或者其他class作為friend
//               ，這些member可以存取class裡的private member
//   *4. 自己的friend應該自己宣告，為了data hiding 不能宣告自己為別人的friend，也不能讓別人自行宣告為自己的friend，這樣不合理 

class MyVector
{
private:
    int n;
    int* m;
public:
    int getN()  //getter: 去get private variable 的值
        { return n;}
    void setN(int v)
        { n=v;    }  //setter: 用來modify private variable的值

//宣告friend (放在private 或public 都沒差)
friend void test();
friend class Test;

};

void test()
{
    MyVector v;
    v.n=100;    //若不是friend，會出現syntax error
    cout<<v.n;
}

class Test
{
public:
    void test(MyVector v)
    {
        v.n=200;
        cout<<v.n;
    }
};
