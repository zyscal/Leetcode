#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum6 = 0x00;
        for(int i = 0; i < nums.size(); i++)
        {
            sum6 ^= nums[i];
        }
        int tem_sum6 = sum6;
        int a = 0x01;
        int first1;
        for(int i = 1; i < 50; i++)
        {
            if(tem_sum6 & a == 1)
            {
                first1 = i;
                break;
            }
            else
            {
                tem_sum6 >>= 1;
            }
        }
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < nums.size(); i++)
        {
            if(get_i_byte(first1, nums[i]) == 1)
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }
        int left_sum6 = 0x00;
        int right_sum6 = 0x00;
        for(int i = 0; i < left.size(); i++)
        {
            left_sum6 ^= left[i];
        }
        for(int i = 0; i < right.size(); i++)
        {
            right_sum6 ^= right[i];
        }
        vector<int> ans;
        ans.push_back(sum6^left_sum6);
        ans.push_back(sum6^right_sum6);
        return ans;
    }
    int get_i_byte(int i, int num)
    {
        int a = 0x01;
        for(int j = 1; j < i; j++)
        {
            num >>= 1;
        }
        return a & num;
    }
};
int main()
{
    Solution a;
    vector<int> b = {1,2,10,4,1,4,3,3};
    vector<int> ans = a.singleNumbers(b);
    cout << ans[0] << " " << ans[1] << endl;
    
}
