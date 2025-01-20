#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream myfile; // 創建一個ofstream 的物件
    myfile.open("temp1.txt"); //如果有這個檔案就打開它，如果沒有的話會先創建它再打開
    myfile << "Writing this msg :" << 123.45;   //寫入訊息
    myfile.close();
}
