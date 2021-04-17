#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero = 0;
        int min = 99;
        int max = 0;
        for(int i = 0; i < 5; i++)
        {
            if(nums[i] == 0)
            {
                continue;
            }
            if(nums[i] < min)
            {
                min = nums[i];
            }
            if(nums[i] > max)
            {
                max = nums[i];
            }
            if(i != 0 && nums[i] == nums[i - 1])
            {
                return false;
            }
        }
        if(max - min > 4)
        {
            return false;
        }
        return true;
    }
};

int main()
{
