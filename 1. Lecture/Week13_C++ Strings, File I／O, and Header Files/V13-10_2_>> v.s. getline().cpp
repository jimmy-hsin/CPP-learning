#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    //'>>' 跟getline 的差異: >> 會嘗試做 type casting, getline 統一把所有內容作為字串，
    //在使用上應該根據需求搭配使用

  /*
    score.txt:
        Tony Wang: 100
        Alex Chao: 98
        Robin Chen: 95
        Lin: 90
        Mary: 100
        Bob Tsai: 80
  */
    ifstream inFile("score.txt");
    
    string name;
    int score;
    int sumScore = 0;

    if(inFile){
        while(!inFile.eof()) {  //一一讀入內容
            getline(inFile, name, ':'); //我們用getline 讓讀寫頭停在冒號後面
            inFile >> score;    //再用 >> 讓他自動casting成int
            sumScore += score;
        }
        cout << sumScore << endl; 
    }
    inFile.close();
    return 0;

}
