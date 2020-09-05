#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_VAL 999999
int coinChange(vector<int>& coins, int amount) {
    vector<int> ansdp(amount + 1,MAX_VAL);
    ansdp[0] = 0;
    for(int i = 1 ; i < amount + 1 ; i++)
    {
        int temans = MAX_VAL;
        for(int j = 0 ; j < coins.size() ; j++)
        {
            if(i - coins[j] >= 0)
            {
                temans = min(temans , ansdp[i - coins[j]] + 1);
            }
        }
        ansdp[i] = temans;
    }
    for(int i = 0 ; i < amount + 1 ; i++)
    {
        cout<<ansdp[i]<<" ";
    }
    if(ansdp[amount] != MAX_VAL)
        return ansdp[amount];
    else
    {
        return -1;
    }
    
}

int main()
{
    vector<int> testans = { 2 };
    cout<<endl;
    cout<<coinChange(testans,3);
    return 0;
}