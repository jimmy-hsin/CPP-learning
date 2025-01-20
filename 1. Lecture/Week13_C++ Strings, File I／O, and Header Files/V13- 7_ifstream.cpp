#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream inFile("score.txt");// 創建一個ifstream 的物件
    if(inFile){
        string name;
        int score = 0;
        int sumScore = 0;
        int scoreCount = 0;
    
        while(inFile >> name >> score){
            sumScore += score;
            scoreCount++;
        }
        if(scoreCount != 0)
            cout << static_cast<double> (sumScore) / scoreCount;
        else
            cout << "no grade!"; 
    }
    inFile.close();
    return 0;

   
}
