#include <iostream>
using namespace std;

int sumArray(int* x,int n,int subN,int bX,int bY);

int main()
{
    int N=0;
    cin>>N;

    int A[N][N]={0};
    int* a = &A[0][0];
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>A[i][j];
       
    int zero_count=0;
    for(int subn=1;subn<=N;subn++)// size of subarray:from 1~N
        for(int i=0; i <=(N-subn) ;i++) //shift of i: from 0 to N-subn
            for(int j=0; j <= (N-subn) ;j++)        
                if(sumArray(a,N,subn,i,j)==0)
                    zero_count++;
            
    cout<<zero_count;
    cout<<","<<sumArray(a,N,N,0,0);  
}

int sumArray(int* x,int n,int subN,int bX,int bY)   //x:address of the array,
{                                                   //n: size of array,  
    int sum=0;                                      //subN:size of sub-array,
    for(int i=0;i<subN;i++)                         //bX:shift of x axis
        for(int j=0;j<subN;j++)                     //bY:shift of y axis
            sum+=x[(i+bX)*n + j+bY];                
    return sum;
}
