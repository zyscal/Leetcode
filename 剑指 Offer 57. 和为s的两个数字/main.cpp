#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int head = 0;
        int tail = nums.size() - 1;
        vector<int> ans;
        while (head < tail)
        {
            if(nums[head] + nums[tail] == target)
            {
                ans.push_back(nums[head]);
                ans.push_back(nums[tail]);
                return ans;
            }
            else if(nums[head] + nums[tail] < target)
            {
                head++;
            }
            else
            {
                tail--;
            }
        }
    }
};