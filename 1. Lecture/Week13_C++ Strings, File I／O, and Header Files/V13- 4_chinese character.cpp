#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "大家好";
    cout << s << endl; // 大家好
    char c[100] = "喔耶";
    cout << c << endl;  // 喔耶
    int n = s.length(); // 6
    string t = s;
    //因為現在的UTF-8中，一個中文字會以3個byte 做編碼，所以單純的到轉字串會出錯
    //Bad
    for (int i = 0; i < n; i++)
        t[n - i - 1] = s[i]; 
    cout << t << endl;    //��嶮姤�
    //Good
    for (int i = 0; i < n - 1; i = i + 3){
        t[n - i - 3] = s[i];
        t[n - i - 2] = s[i + 1];
        t[n - i - 1] = s[i + 2];
    } 
    cout << t << endl; // 好家大
    return 0;
}
