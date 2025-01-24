#ifndef MyVector_H
#define MyVector_H

class MyVector{
  private:
    int n;
    double* m;
  public:
  //Constructors
    MyVector(int n=0,double m[]=nullptr); 
    MyVector(const MyVector& v);      //copy constructor    
  //destructor
    ~MyVector();
  //function
    void print() const;
  //Comparison Operator
    bool operator== (const MyVector& v) const; 
    bool operator!= (const MyVector& v) const {    return !(*this == v);     }
    bool operator<  (const MyVector& v) const;
  //Assignment operator
    double operator[] (int i) const;    
    double& operator[] (int i);   
    const MyVector& operator= (const MyVector& v);
    const MyVector& operator+=(const MyVector& v);
//~~~~~~~~~~~~~~~~~因為要取v.n的值，但v.n是private member，所以要宣告friend~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    friend const MyVector operator+ (const MyVector& v, double d);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
};

const MyVector operator+ (const MyVector& v, double d);
const MyVector operator+ (const MyVector& v1, const MyVector& v2);
const MyVector operator+(double d, const MyVector& v);

#endif
