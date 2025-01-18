#include <iostream>
using namespace std;
const int GRADE_CNT_MAX = 1000; 

int highGradeCnt(int threshold, int gradeCnt, int grades[])
{
    int count=0;
    for(int i=0;i<gradeCnt;i++)
        if(grades[i]>=threshold)
            count++;
    return count;
}

int mostHighGrades(int thr, int m, int n, int grades[][GRADE_CNT_MAX])
{
    int AssiGroup=0;
    int tempCnt=0;

    for(int i=0;i<m;i++)
    {
        int Cnt=highGradeCnt(thr,n,grades[i]);
        if(Cnt>tempCnt)
        {
            tempCnt=Cnt;
            AssiGroup=i+1;
        }
    }   
    return AssiGroup;
}

int main()
{
    int m, n,thr;
    cin>>m>>n>>thr;
    int x[m][GRADE_CNT_MAX]={0};
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>x[i][j];
   
    cout<<mostHighGrades(thr,m,n,x);
    return 0;
}