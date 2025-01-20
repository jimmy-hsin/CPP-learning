#include <iostream>
#include <string>
using namespace std;

int main(){
  //Part1: getline of C++ string
    string s;
    getline(cin, s, '#');   //字串來源(cin)，儲存的容器(s), 其他delimiters('#') (預設是只有空白鍵)
                            //普通cin的時候，cin會用空白鍵切割字串，所以我們只會看到空白鍵之前輸入的內容
  //Part2:substr()
    //原始函數長這樣: string string::substr(size_t pos = 0, size_t len = npos) const;
    //其中npos 代表size_t這個data type的最大值，用在string 裡面則代表字串結尾
    string s = "abcdef";
    cout << s.substr(2, 3) << endl; // "cde" , substr 的使用方法就使從s[pos]的位置開始，向後取到長度為len的字串 
    cout << s.substr(2) << endl; // "cdef" , 如果沒有輸入len，則預設是取到底
  //Part3:find()
    string t = "abcdefg";
    if(t.find("bcd") != string::npos) //如果有找到的話，回傳以哪個位置為開頭找到的，否則會回傳npos
        cout << t.find("bcd")<<ednl; // 1
    cout << t.find("bcdi"); // 會回傳一個很大的數字，也就是當前的npos，通常為2^64-1，也就是18446744073709551615
    
    
}
