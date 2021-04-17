#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class greater
{
    template <int>
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    vector<int> test = {1,5,6,2,7,7,66,9,6,7};
    sort(test.rbegin(), test.rend());
    for(int i = 0; i < test.size(); i++)
    {
        cout << test.at(i) << " ";
    }
}

class Solution {
public:



    void nextPermutation(vector<int>& nums) {
        int front_serial = find_front(nums);
        if(front_serial == -1)
        {
            return chang_to_ordered(nums);
        }
        int back_serial = find_back(nums, front_serial);
        swap(nums.at(front_serial), nums.at(back_serial));

        sort(nums.begin() + front_serial + 1, nums.end());
    }
    int find_front(vector<int> &nums)
    {
        int before = -1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            if(nums.at(i) >= before)
            {
                before = nums.at(i);
                continue;
            }
            else
            {
                return i;
            }
        }
        return -1;
    }
    int find_back(vector<int> &nums, int front_serial)
    {
        int the_small_one = nums.at(front_serial);
        for(int i = nums.size() - 1; i > front_serial; i--)
        {
            if(nums.at(i) > the_small_one)
            {
                return i;
            }
        }
        return -1;
    }
    void chang_to_ordered(vector<int> &nums)
    {
        vector<int> ans_list;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            ans_list.push_back(nums.at(i));
        }
        nums = ans_list;
    }
};
// int main()
// {
//     Solution a;
//     vector<int> test = {1,1};
//     a.nextPermutation(test);
//     for(int i = 0; i < test.size(); i++)
//     {
//         cout << test.at(i) << " ";
//     }
// }