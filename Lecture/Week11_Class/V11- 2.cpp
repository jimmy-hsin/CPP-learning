#include <iostream>
using namespace std;

struct MyVector{
  int n;
  int* m;
  void init(int dim);
  void print();
}
void MyVector:: init(int dim){
  n=dim;
  m=new int[n];
  for(int i=0;i<n;i++)
      m[i]=0;
}

void MyVector::print(){
  cout<<"(";
  for(int i=0;i<n-1;i++)
      cout<<m[i]<<", ";
  cout<<m[n-1]<<")";
}
