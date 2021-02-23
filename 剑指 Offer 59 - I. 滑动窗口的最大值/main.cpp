#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0)
        {
            vector <int> ans;
            return ans;
            /* code */
        }
        
        int maxpos = 0;
        int head = 0;
        int tail = 0;
        vector<int> ans;
        while (tail < nums.size())
        {
            if(maxpos >= head && maxpos <= tail)//maxpos在窗口中
            {
                if (nums[tail] > nums[maxpos])
                {
                    maxpos = tail;
                }
                ans.push_back(nums[maxpos]);
                if(tail - head + 1 == k)
                {
                    head++;
                }
                tail++;
                continue;
            }
            else
            {
                int temmax = nums[head];
                maxpos = head;
                for(int i = head; i <= tail; i++)
                {
                    if(nums[i] > temmax)
                    {
                        maxpos = i;
                        temmax = nums[i];
                    }
                }
                ans.push_back(nums[maxpos]);
                if(tail - head + 1 == k)
                {
                    head++;
                }
                tail++;
            }
        }
        vector<int> finalans(ans.begin() + k - 1, ans.end());
        return finalans;
    }
};
int main()
{
    vector<int> list = {1,-1};
    Solution a;
    vector<int> ans = a.maxSlidingWindow(list,1);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}