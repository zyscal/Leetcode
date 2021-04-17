#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;


class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<int> bucket(6 * n + 1, 0);
        int all_pro = pow(6, n);
        vector<int> all_pos(n, 1);
        all_pos[0] = 0;//从0 1 1 1 ... 开始
        int nowcount = n - 1;
        for(int i = 0; i < all_pro; i++)
        {
            for(int j = 0; j < n; j++)
            {
                all_pos[j]++;
                nowcount++;
                if(all_pos[j] == 7)
                {
                    nowcount -= 6;
                    all_pos[j] = 1;
                    continue;
                }
                else
                {
                    break;
                }
            }
            bucket[nowcount]++;
        }
        vector<double> ans;
        for(int i = 0; i < bucket.size(); i++)
        {
            if(bucket[i] == 0)
            {
                continue;
            }
            ans.push_back((double)bucket[i] / (double)all_pro);
        }
        return ans;
    }
};

int main()
{
    Solution a;
    a.dicesProbability(11);
}