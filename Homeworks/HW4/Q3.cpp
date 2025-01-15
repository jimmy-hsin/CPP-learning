#include <iostream>
using namespace std;

int inrow(int* row,int up,int down);     //Function1: 判斷是否有不用換位置的座位
int has(int* row,int up,int down,int n); //Function2: 判斷旅程內皆有座位

int main()
{
    int n,m,k; //位置數、路段數，旅客數
    cin>>n>>m>>k;                                                                                               
    int pos[n+1][m]={0};   //創一個位置矩陣  //多加一行用來存取第t時段內有幾個位置有人

    for(int i=0;i<n;i++) {  //初始化矩陣
        for(int j=0;j<m;j++)
            pos[i][j]=0; }

    for(int i=0;i<k;i++)//處理第i+1個旅客
    {
        int start=0,end=0;
        cin>>start>>end;                                                      
        int num=i+1; //旅客編號=i+1  
        int row=-1;//用來存取哪排有連續的變數
        
        for(int j=0;j<n;j++)//跑過每條位置，抓出有連續的條號  
            if(inrow(&pos[j][0],start,end)==1)  //如果有連續空位的話，
            {
                row=j;//把有連續空位的位置記下來
                break;//跳出for迴圈不要讓他繼續跑  
            }    
        
     //Part 2: 填入數字
        if(row>=0){   //如果有連續的座位
            for(int t=start;t<end;t++){
                pos[row][t]=num;  //把那個位置填上旅客編號
                pos[n][t]+=1;     //統計人數+1
            }
        }
                 
        else if(has(&pos[n][0],start,end,n)==1){   //如果沒有連續座位，但旅程皆有位置
            for(int t=start;t<end;t++)            
                for(int r=0;r<n;r++)            //從上往下找空位          
                    if(pos[r][t]==0){             //若有空位
                        pos[r][t]=num;            //把那個位置填上旅客編號
                        pos[n][t]+=1;             //統計人數+1
                        break;                    //跳出for迴圈，不要讓他填兩遍
                    }
        }
    
    }

    //印出結果
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==(m-1))
                cout<<pos[i][j]<<"\n";
            else
                cout<<pos[i][j]<<",";
        } 
    }
    
    return 0;
}

//Function1: 判斷是否有不用換位置的座位
int inrow(int* row,int up,int down)
{
    bool boo=1;
    for(int i=up;i<down;i++)
        if(*(row+i)!=0)    //當有哪一排的其中一個值!=0，表示有人占用
            boo=0;         //將回傳值改為0

    return boo;
}

//Function2: 判斷旅程內皆有座位
int has(int* row,int up,int down,int n)
{
    bool boo=1;
    for(int i=up;i<down;i++)
        if(*(row+i)>=n)  //當有哪一排的其中一個值>n(總座位數)，表示有人占用
            boo=0;

    return boo;
}