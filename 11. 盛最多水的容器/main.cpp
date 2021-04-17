#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    typedef pair<int, int> pairtype;
    int maxArea(vector<int>& height) {
        if(height.size() < 2)
        {
            return 0;
        }
        vector<pair<int, int> > left;
        vector<pair<int, int> > right;
        left.push_back(pairtype(0, height.at(0)));
        right.push_back(pairtype(height.size() - 1, height.at(height.size() - 1)));
        for(int i = 0; i < height.size(); i++)
        {
            if(height.at(i) > left.at(left.size() - 1).second)
            {
                left.push_back(pairtype(i, height.at(i)));
            }
        }
        for(int i = height.size() - 1; i >= 0; i--)
        {
            if(height.at(i) > right.at(right.size() - 1).second)
            {
                right.push_back(pairtype(i, height.at(i)));
            }
        }
        int ans = 0;
        int j = 0;
        for(int i = 0; i < right.size(); i++)
        {
            for(; j < left.size(); j++)
            {
                //get ans
                int tem_ans = (right.at(i).first - left.at(j).first) * min(right.at(i).second, left.at(j).second);
                ans = max(ans, tem_ans);
                if(left.at(j).second >= right.at(i).second)
                {
                    break;
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution a;
    vector<int> test_list = {2,3,4,5,18,17,6};
    cout << a.maxArea(test_list);
}