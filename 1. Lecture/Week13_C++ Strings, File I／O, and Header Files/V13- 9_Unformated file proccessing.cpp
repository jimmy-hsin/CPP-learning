#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream inFile("score.txt");
    if(inFile){
        //Part 1，將文字檔印到螢幕上
        while(!inFile.eof()){   //只要還沒到檔案結尾，不管讀到什麼東西都把它印出來(包括空格、換行)
            char c=inFile.get();    //get 會將當前讀寫頭只到的東西存到c裡，然後讀寫頭往後移動一格
            cout<<c;
        }
        //方法2, cstring
        while(!inFile.eof()){
            char name[20];    //創建一個cstring
            inFile.getline(name,20);    //將每一行，最多20個字元存進name中
            cout<<name<<endl;   //將name打印出來
        }
        //方法3, c++ string
        while(!inFile.eof()){
            string name2;
            //我們這邊使用的是<string> 函式庫裡的getline，因為有一個參數是c++ string
            //這麼用的好處是不用擔心每一行字的字數有多少，c++ string 都裝得下，也不用像上面要先宣告一行只能讀多少字
            getline(inFile, name2, ' ');//用空格當delimiter，
            cout<<name<<endl;    //每讀到一個delimeter就會換行， 而一個getline迴圈結束也會換行，所以檔案中的空格 & 換行在顯示時都會換行
        }
    }
    

}
