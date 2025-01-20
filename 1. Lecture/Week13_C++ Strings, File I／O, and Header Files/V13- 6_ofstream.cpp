#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ofstream myfile; // 創建一個ofstream 的物件
    /*File Open 其實有三種模式:
        1. ios::out (default): The window starts at location 0; remove existing data.
        2. ios::app: The window starts at the end; never modify existing data. 
        3. ios::ate: The window starts at the end; can modify existing data. 
    */
    myfile.open("temp1.txt", ios::ate); //如果有這個檔案就打開它，如果沒有的話會先創建它再打開

  
    myfile << "Writing this msg :" << 123.45;   //寫入訊息
    myfile.close();

    //Part2
    cout<<"---------------------Part 2-----------------";
    ofstream scoreFile("temp.txt", ios::out);
    char name[20] = {0};
    int score = 0;
    char notFin = 0;
    bool con = true;
    if(!scoreFile)    //檢查檔案有沒有正確的被打開
        exit(1);
    while(con){
        cin >> name >> score;
        scoreFile << name << " " << score << "\n"; //寫入名字，成績
        cout << "Continue (Y/N)? ";    //詢問是否要繼續
        cin >> notFin;
        con = ((notFin == 'Y') ? true : false);    //如果沒有要繼續(打入除了"Y"以外的鍵) 就會跳出while loop
    }
    scoreFile.close();
    return 0;
}
