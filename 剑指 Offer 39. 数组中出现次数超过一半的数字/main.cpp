#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int zhu = nums[0];
        int count = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == zhu)
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count == -1)
            {
                zhu = nums[i];
                count = 1;
            }
        }
        return zhu;
    }

};