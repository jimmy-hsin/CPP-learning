#include <iostream>
using namespace std;

double max(double array[], int len)
{
    if(len==0)
        return array[0];
    else
    {
        double subMax=max(array,len-1);
        if(array[len-1]>subMax)
            return array[len-1];
        else
            return subMax;
    }
}
int main()
{
    double a[8]={5,9,8,7,6,4,3,100};
    cout<<max(a,8);


}