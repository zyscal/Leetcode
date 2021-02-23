#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> from_begin(a.size() + 1, 1);
        vector<int> from_end(a.size() + 1, 1);
        int mul_begin = 1;
        for(int i = 0; i < a.size(); i++)
        {
            mul_begin *= a[i];
            from_begin[i] = mul_begin;
        }
        int mul_end = 1;
        for(int i = a.size() - 1; i >= 0; i--)
        {
            mul_end *= a[i];
            from_end[i] = mul_end;
        }
        // for(int i = 0; i < from_begin.size(); i++)
        // {
        //     cout << from_begin[i] << "\t";
        // }
        // cout << endl;
        // for(int i = 0; i < from_end.size(); i++)
        // {
        //     cout << from_end[i] << "\t";
        // }
        // cout << endl;
        vector<int> ans(a.size());
        for(int i = 0; i < ans.size(); i++)
        {
            int firstnum = i == 0 ? 1 : from_begin[i - 1];
            ans[i] = firstnum * (from_end[i + 1]);
        }



        return ans;
    }
};
int main()
{
    Solution a;
    vector<int> test = {1,2,3,4,5};
    vector<int> ans = a.constructArr(test);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\t";
    }
}