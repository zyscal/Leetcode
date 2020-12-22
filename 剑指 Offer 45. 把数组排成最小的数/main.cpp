#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums) {
        
    }
    bool check(int numa, int numb)
    {
        string a = to_string(numa);
        string b = to_string(numb);
        if(a + b > b + a)
        {
            return true;
        }
        return false;
    }
};