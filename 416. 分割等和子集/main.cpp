#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_VAL 999999
bool canPartition(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector< vector<int>> ansdp(nums.size());

    int Differ = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        Differ += nums[i];
    }
    for(int i = 0; i < nums.size(); i++)
    {
        ansdp[i].resize(Differ + 1, MAX_VAL);
    }
    ansdp[0][nums[0]] = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        for(int j = 0; j < Differ + 1; j++)
        {
            if(ansdp[i - 1][j] != MAX_VAL)
            {
                ansdp[i][j + nums[i]] = ansdp[i - 1][j];
                if(j <= nums[i])
                {
                    ansdp[i][nums[i] - j] = ansdp[i - 1][j] + j;
                }
                else
                {
                    ansdp[i][j - nums[i]] = ansdp[i - 1][j] + nums[i];
                }   
            }
        }
    }
    // for(int i = 0; i < ansdp.size(); i++)
    // {
    //     for(int j = 0; j <= Differ; j++)
    //     {
    //         cout<<ansdp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(ansdp[nums.size() - 1][0] != MAX_VAL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
int main()
{
    vector<int> a = {1, 2, 3, 5};
    cout<<canPartition(a);
}

