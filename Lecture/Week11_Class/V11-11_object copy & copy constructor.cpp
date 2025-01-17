#include <iostream>
using namespace std;

/*為什麼要有copy constructor:
    如果只是用一般的constrcutor的話，在member裡面有ptr的情況下。copy版的ptr(ptr2) 會跟 原本的ptr(ptr1)指向同一塊空間(m1)，
    若我們透過ptr2去修改指標指向(m1)中的值的話，我們在操作ptr1的時候會發現原本的空間(m1)已被更動，這是我們不樂見的情況。
*/
class A
{
  private:
    int i;
  public:
    A()    
        {cout<<"A";}    //constructor
    
    /*
    copy constructor: 
        用來複製object用的，指定傳入值要是reference，
        不然copy的時候會一直call copy constructor，沒完沒了，(想像一下如果是call by value，那這個函數會需要locally新建一個object，而這個動作會呼叫copy constructor，所以會沒完沒了)
        指定要用const，因為你不會希望傳入值被更動到
    */
    A(const A& a)
        {cout<<"a";}
    /*
    如果沒有自己定義copy constructor，那麼系統會幫你做一個default 的 copy constructor，
        The default copy constructor simply copies all member variables one by one, regardless of the variable types (shallow copy) 
        所以member variables中如果有ptr或陣列(底層邏輯仍是ptr)的話，後續操作容易出錯
    因此我們會希望自己能定義copy constructor，來完成deep copy，以避免出錯(也就是如果有ptr的話把ptr的內容寫進正確的位址； 如果有陣列的話，自己重新new一塊空間，再把copy source 的value 寫進去)
    */
};

void f(A a1,A a2,A a3)
{
    A a4;
}

int main()
{
    A a1,a2,a3;   //會呼叫3次constructor
    cout<<"\n===\n";
    f(a1,a2,a3);  //因為要將a1~a3傳入function f，所以會將這些值複製進f裡，會呼叫3次copy constructor(傳入的a1~a3) 然後呼叫1次constructor(a4)
    cout<<"\n===\n";
    
    A a4(a1); //呼叫1次copy constructor
    cout<<"\n===\n";
    
    A a5=a1;  //用assign的方式跟用copy constructor 一樣，所以a4, a5沒有什麼不同
    return 0;
}

