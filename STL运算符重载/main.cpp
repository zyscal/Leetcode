#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;



class Solution {
public:
    struct node
    {
        int x;
        int y;
        int sum;
        /* data */
        node(int x, int y, int sum)
        {
            this->x = x;
            this->y = y;
            this->sum = sum;
        }
        bool operator < (const node a) const
        {
            return this->sum < a.sum;
        }
        bool operator > (const node a) const
        {
            return this->sum > a.sum;
        }
        bool operator == (const node a) const
        {
            return this->sum == a.sum;
        }
        bool operator != (const node a) const
        {
            return this->sum != a.sum;
        }
    };
    int maxValue(vector<vector<int>>& grid) {
        priority_queue<node, vector<node>> ans;
        node begin(0, 0, grid[0][0]);
        ans.push(begin);
        while (true)
        {
            node now = ans.top();
            ans.pop();

        }
        
    }

};    
int main()
    {
        Solution a;
        vector< vector<int>> grid;
        a.maxValue(grid);
    }