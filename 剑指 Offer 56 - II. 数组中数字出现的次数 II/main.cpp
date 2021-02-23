#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> anslist(32, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            calculate(anslist, nums[i]);
        }
        bool begin = false;
        int ans = 0;
        for(int i = 31; i >= 0; i--)
        {
            if(begin)
            {
                ans *= 2;
                if(anslist[i] == 1)
                {
                    ans += 1;
                }
            }
            else if(anslist[i] == 1)
            {
                begin = true;
                ans += 1;
            }
        }
        return ans;
    }
    void calculate(vector<int>& anslist, int num)
    {
        for(int i = 0; i < 32; i++)
        { 
            int overflow = num % 2;
            anslist[i] = (anslist[i] + overflow) % 3;
            num >>= 1;
            if(num == 0)
            {
                return;
            }     
        }
    }
};
int main()
{
    Solution a;
    vector<int> nums = {3,4,3,3};
    cout << endl;
    cout << a.singleNumber (nums);
}