#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
/*
 * abc type = 0 count = 2*abc + 2*aba
 * aba type = 1 count = 2*abc + 3*aba
 */
    int numOfWays(int n) {
        vector <vector<long long>> anslist(2);
        for(int i = 0; i < anslist.size(); i++)
        {
            anslist.at(i).resize(n, -1);
        }
        long long ans = 6 * count(n - 1, 0, anslist) + 6 * count(n - 1, 1, anslist);
        ans %= 1000000007;
        return ans;
    }
    long long count(int n, int type, vector< vector<long long>> &anslist)
    {
        if(n == 0)
        {
            return 1;
        }
        if(anslist.at(type).at(n) != -1)
        {
            return anslist.at(type).at(n) % 1000000007;
        }
        long long abc = 2 * count(n - 1, 0, anslist);
        long long aba = 0;
        if(type == 0)
        {
            aba = 2 * count(n - 1, 1, anslist);
        }
        else
        {
            aba = 3 * count(n - 1, 1, anslist);
        }
        anslist[type][n] = (abc + aba) % 1000000007;
        return anslist[type][n];
    }
};
int main()
{
    Solution a;
    cout << a.numOfWays(5000);
}