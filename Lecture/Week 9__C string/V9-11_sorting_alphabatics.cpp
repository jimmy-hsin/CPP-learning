#include <iostream>
#include <cstring>
using namespace std;

const int CNT=4;          //總共有4個名字
const int LEN=10;         //字串長度都不超過10
void swapName(char* n1, char* n2)  //設置一個負責交換名字的function
{
    char temp[LEN]={0};
    strcpy(temp,n1);     //把n1的字串copy到temp上，
    strcpy(n1,n2);
    strcpy(n2,temp);
}

void swapPtr(char*& p1, char*& p2)  //設置一個負責交換pointer的function
                                    //必須要有&(call by reference) 否則就只是創造兩個指向p1和p2的指標(會變成指標的指標)，其他內容沒有換到
{
    char* temp=p1;
    p1=p2;
    p2=temp;
}


int main()
{
    char name[CNT][LEN]
        ={"John","Mikasa","Eren","Armin"};  //Data input

    for(int i=0;i<CNT;i++)     //Arrange Names by bubble sorting    
        for(int j=0;j<CNT-i-1;j++)
            if(strcmp(name[j],name[j+1])>0)   //透過strcmp進行comparison，若回傳的數值>0，表示前面的字串應該要排在後面
                swapName(name[j],name[j+1]);  //所以，呼叫swap function，進行字串位置交換

    for(int i=0;i<CNT;i++)     //把排完的名字依序印出來
        cout<<name[i]<<" ";

    //---------------------------------------Part 2-----------------------------------
    //透過使用交換pointer的方式比較省資源，比較有效率

    char* ptr[CNT]                        //先設置一個存取pointer的陣列，pointer存取的都是名字開頭的那個地址
        ={name[0],name[1],name[2],name[3]};

    for(int i=0;i<CNT;i++)                //使用bubble sort，交換pointer
        for(int j=0;j<CNT-i;j++)
            if(strcmp(ptr[j],ptr[j+1])>0)
                swapPtr(ptr[j],ptr[j+1]);
    
    for(int i=0;i<CNT;i++)      //依序印出pointer名字
        cout<<ptr[i]<<" ";      //cout pointer相當於cout 那個地址到遇到第一個'\0'中間的字串        

    return 0;
}