#include <iostream>
#include <cstring>
using namespace std;
void bigMoneyAdd(char m1[], char m2[], char sum[], int n);
void bigMoneySub(char m1[], char m2[], char diff[], int n);
int SpaceCount(char m1[], int n);

int main()
{
    int n;
    cin>>n;

    char m1[n+1]={'\0'};
    char m2[n+1]={'\0'};
    char sum[n+1]={'\0'};
    char diff[n+1]={'\0'};
    for(int i=0;i<n;i++)
        m1[i]=m2[i]=sum[i]=diff[i]=48;

    string a,b;
    cin>>a>>b;
    int la=a.length();
    int lb=b.length();
    for(int i=0;i<la;i++)
        m1[n-la+i]=a[i];
    for(int i=0;i<lb;i++)
        m2[n-lb+i]=b[i];

    bigMoneyAdd(m1, m2, sum, n);
    bigMoneySub(m1, m2, diff, n);
    
    cout<<'$';
    for(int i=SpaceCount(sum,n);i<n;i++) //印出sum
    {
        int mo=n%3;
        cout<<sum[i];
        if((4+i-mo)%3==0 && i!=n-1)
            cout<<',';
    }

    cout<<"\n$"; 
    for(int i=SpaceCount(diff,n);i<n;i++) //印出sum
    {
        int mo=n%3;
        cout<<diff[i];
        if((4+i-mo)%3==0 && i!=n-1)
            cout<<',';
    } 
}

int SpaceCount(char m1[], int n)
{
    int x=0;
    for(int i=0;i<n-1;i++)
    {
        if(m1[i]==48)
            x++;
        else
            break;
    }
    return x;
}

void bigMoneyAdd(char m1[], char m2[], char sum[], int n)
{
    int carry=0;
    for(int i=n-1;i>=0;i--)
    {
        if( (m1[i]-48 + m2[i]-48+carry ) >=10)     //char'0' = 48 
        {  sum[i]=m1[i]-48+m2[i]-48+carry-10 +48;
            carry=1;                            }
        else
        {   sum[i]=m1[i]-48+m2[i]-48+carry +48;
            carry=0;                            }
    }       
}

void bigMoneySub(char m1[], char m2[], char diff[], int n)
{
    int carry=0;
    for(int i=n-1;i>=0;i--)
    {
        if(( m1[i] - m2[i] -carry ) < 0)
        {   diff[i]=10+m1[i]-m2[i]-carry+ 48;
            carry=1;                            } 
        else
        {   diff[i]=m1[i] -m2[i] -carry+ 48;
            carry=0;                            }
    }
}