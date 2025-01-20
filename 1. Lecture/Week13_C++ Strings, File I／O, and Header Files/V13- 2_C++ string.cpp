#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    string mystring="mystr";        //使用constructor, 用"mystr"初始化
    string yourstring(mystring);    //使用string 內部的copy constructor
    cout<< yourstring<<endl;
    
    cout << mystring.max_size() << endl;    //4611686018427387903
    
    
    string myString = "my string"; //使用constructor, 用"mystr"初始化
    string yourString = myString;  //使用constructor, 用myString初始化
    string herString;   //空字串
    
    //我們這邊會看到三種傳入值: string Literal("a new string"), string(yourString), 和cString(hisString[100])
    //由於前人幫我們寫好了許多function overloads of operator= 所以我們才可以方便地使用
    herString = yourString = "a new string";    //這邊才是在使用operator overloading=
    char hisString[100] = "oh ya";  
    myString = hisString;                       //使用operator overloading=
    
    //其他的Operator Overload
    myString=yourString+"123"+hisString;        //使用operator overloading+
    myString+=yourString                        //使用operator overloading+=
    cout<<myString[3];                          //使用operator overloading[]
    
}
