#include<vector>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
        {
            return 0;
        }
        int min_val = prices[0];
        int max_val = prices[0];
        int dif = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < min_val)
            {
                min_val = prices[i];
                max_val = min_val;
                continue;
            }
            if(prices[i] > max_val)
            {
                max_val = prices[i];
                dif = max(dif, max_val - min_val);
                continue;
            }
        }
        return dif;
    }
};