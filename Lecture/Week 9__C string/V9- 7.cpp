#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const char *p = "12345";
    cout<<strlen(p)<<"\n";  //5

    char a[100]="1234567890";
    cout<<strlen(a)<<"\n";  //10
    cout<<sizeof(a)<<"\n";  //100
    cout<<sizeof(a+2)<<"\n"; //會理解為從a+2這個地址傳入的pointer，所以答案會為8 (因為這個地址沒有被宣告過)
                             //'a+2' ~ '\0' =8

}
