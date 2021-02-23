#include<iostream>
#include    <vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector< vector<int>> global_map(n + 1);
        for(int i = 0; i < global_map.size(); i++)
        {
            global_map[i].resize(6 * n + 1, -1);
        }

        int all_pos = pow(6, n);
        vector<double> ans;
        for(int i = n; i < 6 * n + 1; i++)
        {
            int tem = findans(n, i, global_map);

            double temans = (double)tem/(double)all_pos;

            ans.push_back(temans);
        }
        return ans;
    }
    int findans(int n, int k, vector< vector<int>> &global_map)
    {
        if(k > 6 * n || k < n)
        {
            return 0;
        }
        
        if(global_map[n][k] != -1)
        {
            return global_map[n][k];
        }

        if(n == 1)
        {
            global_map[n][k] = 1;
            return 1;
        }
        int ans = 0;
        for(int i = 1; i <= 6; i++)
        {
            ans += findans(n - 1, k - i, global_map);
        }
        global_map[n][k] = ans;
        return ans;
    }
};
int main()
{
    Solution a;
    a.dicesProbability(2);

}