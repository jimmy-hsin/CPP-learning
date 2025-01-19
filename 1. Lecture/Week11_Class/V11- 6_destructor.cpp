#include <iostream>
using namespace std;

/*   Destructor
    在物件的生命週期要結束的時候會被呼叫
    Destructor must be public and have no parameter
    Compiler也有提供一個default Destructor, which does nothing
    如果有定義Destructor，則compiler不會加 default Destructor
    
    如果在 C++ 中沒有顯式定義 destructor，編譯器會自動生成一個「預設 destructor」，並且它會進行以下操作：
        1. 釋放成員變數的記憶體（若是原始類型）：對於內建類型（如 int、char 等），預設 destructor 不會執行額外的操作，因為這些變數不需要釋放記憶體。
        2. 不處理動態記憶體（new、malloc）：如果物件中有使用 new 或類似的動態記憶體分配，預設 destructor 不會自動釋放這些記憶體。這會導致記憶體洩漏，因此需要手動定義 destructor 並釋放這些記憶體。
        3. 調用成員變數的預設 destructor：對於類型中包含其他物件成員（例如，其他類型的物件或指標）的情況，預設 destructor 會自動調用這些成員變數的 destructor。
    簡單來說，預設的 destructor 只會處理成員變數的基本清理工作，並不會做複雜的記憶體釋放或資源清理。如果你的類別有動態分配的資源，你需要自定義 destructor 來正確釋放這些資源。
    
    *1.Destructor的名稱，則是class的名稱前面加上"~"
    *2.Destructor主要做的事就是將動態配置記憶空間釋出

*/
class MyVector
{
private:
    int n;
    int* m;
public:
    MyVector();
    MyVector(int dim, int value=0);  //Constructor
    ~MyVector(); //Destructor
};

MyVector::MyVector()
{
    n=0;
    m=nullptr;
}
MyVector::MyVector(int dim,int value)
{
    n=dim;
    m=new int[n];
    for(int i=0;i<n;i++)
        m[i]=value;
}
MyVector:: ~MyVector()
{
    delete [] m;
}

int main()
{
    if(true)
        MyVector v1(1); //Destructor要做的就是在block結束前把記憶體釋出
                        //不然就可能程式跑完出現memory leak
    return 0;
}
