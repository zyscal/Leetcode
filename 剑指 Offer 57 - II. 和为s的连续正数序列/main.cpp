#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int head = 1;
        int tail = 2;
        int sum = 3;
        vector<vector<int>> ans;
        while (head != tail && tail < target)
        {
            if(sum == target)
            {
                vector<int> temans;
                for(int i = head; i <= tail; i++)
                {
                    temans.push_back(i);
                }
                ans.push_back(temans);
                tail++;
                sum += tail;
            }
            else if(sum < target)
            {
                tail++;
                sum += tail;
            }
            else
            {
                sum -= head;
                head++;
                
            }
            /* code */
        }
        return ans;
        
    }
};
int main()
{
    Solution a;
    a.findContinuousSequence(9);
    return 0;
}