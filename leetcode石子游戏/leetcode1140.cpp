#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int stoneGameII(vector<int>& piles) 
{
    int LEN = piles.size();
    vector<int> sumpiles(LEN,0);
    auto iter = sumpiles.end() - 1;
    int temsum = 0;
    for(int i = LEN - 1; i >= 0; i--)
    {
        *iter = temsum + piles[i];
        temsum = *iter;
        iter--;
    }
    vector <vector<int> > ansdp(LEN + 1);
    for(int i = 0; i < LEN + 1; i++)
    {
        ansdp[i].resize(LEN, 0);
    }

    for(int j = LEN - 1; j >= 0; j--)
    {
        int temmax = 0;
        for(int i = 1; i <= LEN; i++)
        {
            if(LEN - j <= i)
            {//只能全拿
                temmax = max(temmax, sumpiles[j]);
                ansdp[i][j] = temmax;
            }
            else
            {
                int take = sumpiles[j] - sumpiles[j + i];
                cout<<"sumpiles["<<j<<"]:"<<sumpiles[j]<<"   sumpiles["<<i + j<<"];"<<sumpiles[j+i]<<endl;
                cout<<"take:"<<take<<endl;

                temmax = max(temmax, take + sumpiles[j + i] - ansdp[min(LEN, 2 * i)][j + i]);
                ansdp[i][j] = temmax;
            }
            
        }
    }

    for(int i = 1; i <= LEN; i++)
    {
        for(int j = 0; j < LEN; j++)
        {
            cout<<ansdp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"ans is:"<<ansdp[2][0]<<endl;
    return 0;
}

int main()
{
    vector<int> test = {8,9,5,4,5,4,1,1,9,3,1,10,5,9,6,2,7,6,6,9};
    stoneGameII(test);
    return 0;
}