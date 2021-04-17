#include<iostream>
#include<vector>

using namespace std;


    class Solution {
    public:
        int reversePairs(vector<int>& nums) {
            if(nums.size() == 1 || nums.size() == 0)
            {
                return 0;
            }
            vector<int> left(nums.begin(), nums.begin() + nums.size()/2);
            vector<int> right(nums.begin() + nums.size()/2, nums.end());
            int left_num = reversePairs(left);
            int right_num = reversePairs(right);
            int pos_left = 0;
            int pos_right = 0;
            vector<int> ans;
            int count = 0;
            while(true)
            {
                while (pos_left != left.size())
                {
                    if(pos_right == right.size())
                    {
                        ans.push_back(left[pos_left]);
                        pos_left++;
                        continue;
                    }
                    if(left[pos_left] > right[pos_right])
                    {
                        count += right.size() - pos_right;
                        ans.push_back(left[pos_left]);
                        pos_left++;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                while (pos_right != right.size())
                {
                    if(pos_left == left.size() || right[pos_right] >= left[pos_left])
                    {
                        ans.push_back(right[pos_right]);
                        pos_right++;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if(pos_left == left.size() && pos_right == right.size())
                {
                    nums = ans;
                    break;
                }
            }
            return left_num + right_num + count;

            // for(int i = 0; i < left.size(); i++)
            // {
            //     cout << left[i] << " ";
            // }
            // cout << endl;
            // for(int j = 0; j < right.size(); j++)
            // {
            //     cout << right[j] << " ";
            // }
            // cout << endl;
            // return 0;
        }
    };
int main()
{
    Solution a;
    vector<int> aa ;
    cout << a.reversePairs(aa);
}