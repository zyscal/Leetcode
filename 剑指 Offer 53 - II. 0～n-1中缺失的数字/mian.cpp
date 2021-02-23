#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return findans(0, nums.size() - 1, nums);
    }
    int findans(int l, int r, vector<int> nums)
    {
        if(check(nums, r))
        {
            return r + 1;
        }
        if(!check(nums, l))
        {
            return nums[l] - 1;
        }
        if(r - l == 1)
        {
            return l + 1;
        }
        if(check(nums, (l + r) / 2))
        {
            return findans((l + r) / 2, r, nums);
        }
        return findans(l, (l + r) / 2, nums);
    }
    bool check(vector<int> &nums, int i)
    {
        if(i == nums[i])
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Solution a;
    vector<int> aa = {0,1};
    cout << a.missingNumber(aa) << endl;
}
