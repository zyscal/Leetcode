#include<iostream>
#include<vector>
using namespace std;
vector<int> exchange(vector<int>& nums)
{
    if(nums.size() == 0)
    {
        return nums;
    }
    auto beginnums = nums.begin();
    auto endnums = nums.end() - 1;
    while(beginnums < endnums)
    {
        while(*beginnums % 2 == 1 && beginnums != nums.end() - 1)
        {
            beginnums++;
        }
        while (*endnums % 2 == 0 && endnums != nums.begin())
        {
            endnums--;
            /* code */
        }
        if(beginnums < endnums)
        {
            swap(*beginnums, *endnums);
        }
    }
    return nums;
}
int main()
{
    
}