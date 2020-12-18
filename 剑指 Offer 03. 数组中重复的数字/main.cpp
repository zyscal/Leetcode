#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int findRepeatNumber(vector<int>& nums) 
{
    unordered_map<int,bool> anslist;
    for(int i = 0; i < nums.size(); i++)
    {
        auto iter = anslist.insert(pair<int ,bool>(nums[i],true));
        if(iter.second)
        {
            continue;
        }
        else
        {
            return iter.first->first;
        }
        
    }
    return 0;
}
int main()
{
    vector<int> a = {2, 3, 1, 0, 2, 5, 3};
    cout<<findRepeatNumber(a);
    return 0;
}