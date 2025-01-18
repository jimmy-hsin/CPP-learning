#include <iostream>
using namespace std;

int main()
{
    int S, s, co, cu, I; // S=貨艙上限, s=貨艙下限, c0=存貨成本, cu=缺貨成本, I=初始存貨
    cin >> S >> s >> co >> cu >> I;
    int n;
    cin >> n;
    int x[n]; // x=每日需求量
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int mcount = 0;  //缺貨日數
    int cost = 0;    //總成本
    for (int i = 0; i < n; i++)
    {
        I = I - x[i];
        if (I >= 0)
        {
            cost += I * co;
            if (I <= s)
                I = S;
        }
        else
        {
            cost -= I * cu;
            I = S;
            mcount++;
        }
    }
    cout << mcount << "," << cost;
}