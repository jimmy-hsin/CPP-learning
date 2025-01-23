#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    /*
        假設我們現在要做一件事: 就是把原本檔案中的Alex 改寫成Alexander，
        由於我們要跟改的長度跟遠使長度不同，無法直接用插入的，
        所以我們要做的其實只能將檔案內容一一複製到一個新的檔案中，
        而當遇到要修改的內容再把他替換成新的內容
    */
    ifstream inFile("score.txt");
    ofstream outFile("test1.txt");
    
    string name;
    int score;
    if(inFile && outFile){  //確認兩個檔案都存在
      //'>>' 跟getline 的差異: >> 會嘗試做 type casting, getline 統一把所有內容作為字串
        while(inFile >> name >> score){  //一一讀入內容
            if(name == "Alex")  //遇到要改的內容，就把他替換成新的內容
                name="Alexander";
            outFile << name << " "<< score << endl;
        }
    }
    inFile.close();
    outFile.close();
    return 0;

}
