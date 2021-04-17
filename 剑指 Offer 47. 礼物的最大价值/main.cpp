#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector< vector<int>> ans(grid.size());
        for(int i = 0; i < grid.size(); i++)
        {
            ans[i].resize(grid[0].size(), 0);
        }
        ans[0][0] = grid[0][0];
        for(int i = 1; i < ans[0].size(); i++)
        {
            ans[0][i] = grid[0][i] + ans[0][i - 1];
        }
        for(int i = 1; i < ans.size(); i++)
        {
            ans[i][0] = grid[i][0] + ans[i - 1][0];
        }
        for(int i = 1; i < ans.size(); i++)
        {
            for(int j = 1; j < ans[i].size(); j++)
            {
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]) + grid[i][j];
            }
        }
        return ans.back().back();
    }
};
int main()
{

}