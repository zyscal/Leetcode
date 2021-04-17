#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    struct edges
    {
        int i;
        int j;
        int value;
        edges(int i, int j, int value)
        {
            this->i = i;
            this->j = j;
            this->value = value;
        }
        /* data */
    }; 
    struct cmp
    {
        /* data */
        bool operator()(edges a, edges b)
        {
            return a.value > b.value;
        }
    };
    priority_queue<edges, vector<edges> ,cmp> edges_queue;
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        vector<int> bucket(cost.size() + cost.at(0).size(), 0);
        int ans = 0;
        for(int i = 0; i < cost.size(); i++)
        {
            for(int j = 0; j < cost.at(i).size(); j++)
            {
                edges temp = edges(i, j, cost[i][j]);
                edges_queue.push(temp);
            }
        }
        while(!edges_queue.empty())
        {
            edges temp = edges_queue.top();
            edges_queue.pop();
            if(bucket.at(temp.i) == 0 || bucket.at(temp.j + cost.size()) == 0)
            {
                bucket.at(temp.i)++;
                bucket.at(temp.j + cost.size())++;
                ans += temp.value;
                continue;
            }
        }
        return ans;
    }
};
int main()
{
    Solution a;
    vector< vector<int> > test = {{1,3,5},{4,1,1},{1,5,3}};
    cout << a.connectTwoGroups(test);
}