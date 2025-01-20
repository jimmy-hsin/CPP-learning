#include <iostream>
#include <string>
using namespace std;

int main(){
  //Part1: getline of C++ string
    cout<<"----------------Part 1--------------\n";
    string str;
    getline(cin, str, '#');   //字串來源(cin)，儲存的容器(str), 其他delimiters('#') (預設是只有空白鍵)
                            //普通cin的時候，cin會用空白鍵切割字串，所以我們只會看到空白鍵之前輸入的內容
    cout<<str<<endl;
  
  //Part2:substr()
    cout<<"----------------Part 2--------------\n";
    //原始函數長這樣: string string::substr(size_t pos = 0, size_t len = npos) const;
    //其中npos 代表size_t這個data type的最大值，用在string 裡面則代表字串結尾
    string s = "abcdefg";
    cout << s.substr(2, 3) << endl; // "cde" , substr 的使用方法就使從s[pos]的位置開始，向後取到長度為len的字串 
    cout << s.substr(2) << endl; // "cdef" , 如果沒有輸入len，則預設是取到底
  
  //Part3:find()
    cout<<"----------------Part 3--------------\n";
    string t = "abcdefg";
    if(t.find("bcd") != string::npos) //如果有找到的話，回傳以哪個位置為開頭找到的，否則會回傳npos
        cout << t.find("bcd")<<endl; // 1
    cout << t.find("bcdi"); // 會回傳一個很大的數字，也就是當前的npos，通常為2^64-1，也就是18446744073709551615
  
  //Part4: comparison
    cout<<"----------------Part 4--------------\n";
    //基本上就是按照字典順序比較，用一些比較子(>, >=, <, <=, ==, !=)就能實作因為都被overload 過了，
    //字典順序越後面的越大(ASCII 編碼值越大)
    //但使用上有一個前提，就是至少有一邊要是c++ string，C++的Library才有辦法被呼叫
    string a="aba";
    string b="abc";
    cout<< (a<b) <<endl; //回傳true;
  
  //Part5: 其他好用function: insert replace, erase
    cout<<"----------------Part 5--------------\n";
    string myStr = "Today is not my day.";
    myStr.insert(9, "totally ");    // Today is totally not my day.  插入
    cout << myStr << endl;
    myStr.replace(17, 4, "NOT");    // Today is totally NOT my day.
    cout << myStr << endl;
    myStr.erase(17, 3);             // Today is totally my day.
    cout << myStr << endl;
    return 0;
//Part6: Conversion
    cout<<"----------------Part 6--------------\n";
    //1. 轉換成cstring
    string cppStr = "Hello, World!";
    const char* cStr = cppStr.c_str();
    printf("使用 printf 输出: %s\n", cStr); //C語言標準輸出函式，只接受Cstring
    //2.將字串轉成數字 stoi:int, stof:float, stod:double
    string a="-12.33";
    cout<<stod(a)+25<<endl;
    //3.數字轉字串
    double b=12.34;
    string c=to_string(b)+" is a double";
    cout<< c<<endl;
}
