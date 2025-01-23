#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream inFile("score.txt");// 創建一個ifstream 的物件
    //每個檔案的結尾其實存著一個特殊符號 "EOF" (end of file)
    if(inFile){
        string name;
        int score = 0;
        int sumScore = 0;
        int scoreCount = 0;
    
        while(inFile >> name >> score){    //這段就跟cin的邏輯差不多，會把遇到第一個空格(或換行、tab)之前的資料存入name, 第二個空格之前的資料存入score
            sumScore += score;
            scoreCount++;
        }
        if(scoreCount != 0)
            cout << static_cast<double> (sumScore) / scoreCount;
        else
            cout << "no grade!"; 
    }
    else 
        cout<<"no file!";
    inFile.close();
    //Part 2
    while(!inFile.eof()){    //判斷讀寫頭指的位置是不是EOF
        inFile >> name;
        inFile >> score;
        sumScore += score;
        scoreCount++; 
    }
    return 0; 
}
