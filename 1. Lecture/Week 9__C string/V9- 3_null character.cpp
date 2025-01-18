#include<iostream>
using namespace std;
int main(){
    char s[3]={'a', 'b', 'c'}; //這樣是合理的寫法
    cout<<s<<endl;
    
    char s1[3]="abc"; //由於 \0 也佔一格，所以我們給的字串實際上是要塞4個元素進去長度只有3的陣列裡，會wrong time error
    cout<<s1<<endl;

    return 0;
}
