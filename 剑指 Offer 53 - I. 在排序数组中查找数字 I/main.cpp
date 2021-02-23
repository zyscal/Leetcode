#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = 0;
        auto iter = nums.begin();
        while (iter != nums.end())
        {
            if(*iter == target)
            {
                count++;
            }
            iter++;
            /* code */
        }
        return count;
        
    }
};