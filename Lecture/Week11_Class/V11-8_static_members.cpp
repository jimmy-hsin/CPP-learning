#include <iostream>
using namespace std;
/*
*A class contains some instance variables and functions 
---Each objects has its own copy of instance variables and functions
*A member variabel/function may be an atteibute/operation of a class
---如果有一個東西是所有class共有的性質，而不是需要依據各個object在創造時重新設置的話，
(When the attribete/operation is class-specific rather than object-specific.)
---A class-specific attribute/operatiob should be identical for all objects.
*這些變數/方法就被叫做static member     
(These variable/functions are called static members.)

Example: windows 程式上方header/title bar 的顏色/字型/大小......
每個程式開起來都會是一樣的東西，就是Class-specific 的屬性
*/



class Window
{
private:
    int width;
    int height;
    static int barColour;
public:
    static int getBarColour();
    
    static void setBarColour(int colour);
};

int Window::barColour=0; //static variable應該要被globally initialize

int Window::getBarColour()
    {    return barColour;   }

void Window::setBarColour(int color)
    {    barColour=color;   }

class A
{
private:
    static int count;
public:
    A()
        {A::count++;}
    ~A()
        {A::count--;}
    static int getCount()
        {return A::count;}
};
int A::count=0;

int main()
{
    Window w;
    cout<<Window::getBarColour()<<"\n";//如果要存取static member
                                     //格式是 class name::member name
                                     //而不是 class name.member name
    Window::setBarColour(1);
    //如果要在instance member中access static member 是被允許的，我們也很常這麼做
    //但若要在static member中access instance member則會出現compilation error
    //雖然不建議，但我們可以透過object來access static member(如下面一行)
    cout<<w.getBarColour()<<"\n";
/*
    1.若某個屬性對所有object來說都是一樣的，他需要被宣告成static variable
        請不要將它弄成instance variable，這樣一致性比較好維護
    2.雖然可以，但請不要用object來呼叫static member
        這會讓程式閱讀者c混淆成instance member
    3.請使用 class name::member name格式，even是在member function的操作裡面
        這會比較好的show出哪個變數是 static member
    4.請不要用static function讀取其他instance member的屬性，理論上static function是大家可以一起共用的
        不能access其他object的東西
*/
    A a4;
    if(true)
        A a1,a2,a3;             //存在於block中的 variable 會在block結束之後被消滅
    cout<<A::getCount()<<"\n";  //可以搭配constructor來獲知object被建立幾次，或者有幾個active object

    return 0;
}