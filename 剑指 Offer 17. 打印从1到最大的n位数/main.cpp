#include<iostream>
#include<vector>
using namespace std;
    vector<int> printNumbers(int n) {
        int ten = 10;
        long long max = 1;
        for(int i = 0; i < n; i++)
        {
            max *= 10;
        }
        max -= 1;
        vector<int> ans;
        for(int i = 1; i <= max; i++)
        {
            ans.push_back(i);
        }
        return ans;
    }