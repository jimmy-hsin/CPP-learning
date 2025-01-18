#include <iostream>
using namespace std;

int highGradeCnt(int threshold, int gradeCnt, int grades[])
{
    int count=0;
    for(int i=0;i<gradeCnt;i++)
        if(grades[i]>=threshold)
            count++;
    return count;
}

int main()
{
    int n,thr;
    cin>>n>>thr;
    int x[n]={0};
    for(int i=0;i<n;i++)
        cin>>x[i];
    cout<<highGradeCnt(thr, n, x);

    return 0;
}