#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define MAX_MOVE 9999999
struct POS
{
    int x;
    int y;
    /* data */
};
POS findPOS(int WORDtoINT)
{
    int hang = WORDtoINT % 6 ? (WORDtoINT / 6) + 1 : WORDtoINT / 6;
    int lie = WORDtoINT % 6 ? WORDtoINT % 6 : 6;
    return{hang , lie};
}

int finddis(int WORDtoINTa , int WORDtoINTb)
{
    if(WORDtoINTa == 0 || WORDtoINTb == 0)
        return 0;
    else
    {
        POS posa = findPOS(WORDtoINTa);
        POS posb = findPOS(WORDtoINTb);
        return (abs(posa.x - posb.x) + abs(posa.y - posb.y));
    }
}

int minimumDistance(string word) 
{
    int LEN = word.length();
    int ***dpmap = (int ***)malloc(sizeof(int **) * LEN + 1);
    for(int i = 0; i < LEN + 1; i++)
    {
        dpmap[i] = (int **)malloc(sizeof(int *) * 27);
        for(int j = 0; j<27; j++)
        {
            dpmap[i][j] = (int *)malloc(sizeof(int) * 27);
            for(int k = 0; k<27; k++)
            {
                dpmap[i][j][k] = MAX_MOVE;
            }
        }
    }

    dpmap[0][0][0] = 0;


    for(int i = 1; i <= LEN; i++)
    {
        int PosOfWord = i - 1;//第i个字符，对应string的i-1位置；
        char WORD = word[PosOfWord];
        int WORDtoINT = (int)WORD - 64;
        cout << "WORD : " << WORD << endl;
        for(int j = 0; j < 27; j++)
        {
            for(int k = 0; k < 27; k++)
            {
                // cout << "j k : " << j << " " << k << endl;
                //针对上一个表中的所有位置
                if( dpmap[i - 1][j][k] != MAX_MOVE)
                {
                    //找到可以继续放置的位置
                    //放左边
                    dpmap[i][WORDtoINT][k] = min(dpmap[i][WORDtoINT][k] , dpmap[i - 1][j][k] + finddis(j,WORDtoINT));
                    dpmap[i][j][WORDtoINT] = min(dpmap[i][j][WORDtoINT] , dpmap[i - 1][j][k] + finddis(k,WORDtoINT));
                    cout<<"disbetween:"<<j<<" "<<WORDtoINT<<":"<<finddis(j,WORDtoINT)<<endl;
                }
            }
        }
            cout<<"-------------"<<endl;
            for(int j = 0 ; j < 27 ; j++)
            {
                for(int k = 0 ; k < 27 ; k++)
                {
                    cout<<dpmap[i][j][k]<<" ";
                }
                cout << endl;
            }
        
    }

    cout<<"ans----"<<endl;
    int minans = MAX_MOVE;
    for(int i = 0 ; i < 27 ; i++)
    {
        for(int j = 0 ; j < 27 ; j++)
        {
            cout << dpmap[LEN][i][j] << " ";
            minans = min(minans , dpmap[LEN][i][j]);
        }
        cout << endl;
    }
    cout << minans << endl;
    return minans;
}

int main()
{
    string s = "HAPPY";
    cout<<minimumDistance(s)<<endl;

    return 0;
}