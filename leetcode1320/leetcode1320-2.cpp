#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_VAL 9999999
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
int findTheOther(int num , string word)
{
    if(num > 0)
    {
        return (int)(word[num - 1]) - 64; 
    }

    else
    {
        return 0;
    }
    
}
int minimumDistance(string word) 
{
    int LEN = word.size();
    vector< vector<int> > ansdp(LEN + 1);
    for(int i = 0 ; i < LEN + 1 ; i++)
    {
        ansdp[i].resize(27 , MAX_VAL);
    }
    ansdp[0][0] = 0;
    for(int i = 1 ; i <= LEN ; i++)
    {
        int PosOfWord = i - 1;//第i个字符，对应string的i-1位置；
        char WORD = word[PosOfWord];
        int WORDtoINT = (int)WORD - 64;
        cout << "WORD : " << WORD << endl;
        for(int j = 0 ; j < 27 ; j++)
        {
            if(ansdp[i - 1][j] != MAX_VAL)
            {
                int biaowai = findTheOther(PosOfWord , word);
                int biaonei = j;
                //把表外那只手放到当前位置
                ansdp[i][biaonei] = min(ansdp[i][biaonei] , ansdp[i - 1][biaonei] + finddis(biaowai , WORDtoINT));
                ansdp[i][biaowai] = min(ansdp[i][biaowai] , ansdp[i - 1][biaonei] + finddis(biaonei , WORDtoINT));
            }
        }
        for(int j = 0 ; j < 27 ; j++)
        {
            cout<<ansdp[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans = MAX_VAL;
    for(int i = 0 ; i < 27 ; i++)
    {
        ans = min(ansdp[LEN][i] , ans);
    }
    return ans;
}

int main()
{
    string s = "YEAR";
    cout<<minimumDistance(s);
}