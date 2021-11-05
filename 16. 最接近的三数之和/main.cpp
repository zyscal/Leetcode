#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        auto iterBegin = nums.begin();
        auto iterEnd = nums.end() - 1;
        auto p = nums.begin() + 1;
        int oldsum = *iterBegin + *p + *iterEnd;
        while (p < iterEnd - 1 && calculate(oldsum, *iterBegin, *(p + 1), *iterEnd, target))
        {   
            p++;
            oldsum = *iterBegin + *p + *iterEnd;
        }
        // cout << *iterBegin << endl;
        // cout << *p << endl;
        // cout << *iterEnd << endl;
        // cout << "--------------" << endl;
        while(1){
            bool canMoveLeft = iterBegin < p - 1 && calculate(oldsum, *(iterBegin + 1),*p, *iterEnd, target); 
            bool canMoveRight = iterEnd > p + 1 && calculate(oldsum, *iterBegin, *p, *(iterEnd - 1), target);
            if(canMoveLeft && !canMoveRight){
                iterBegin++;
                oldsum = *iterBegin + *p + *iterEnd;
                moveP(&p, nums, iterBegin, iterEnd, target, oldsum);
            }else if (!canMoveRight && canMoveRight) {
                iterEnd--;
                oldsum = *iterBegin + *p + *iterEnd;
                moveP(&p, nums, iterBegin, iterEnd, target, oldsum);
            } else if (canMoveRight && canMoveRight) {
                int diffLeft = findDiff(*(iterBegin + 1) + *p + *iterEnd, target);
                int diffRight = findDiff(*iterBegin + *p + *(iterEnd + 1), target);
                if (diffLeft < diffRight){
                    iterBegin++;
                    oldsum = *iterBegin + *p + *iterEnd;
                    moveP(&p, nums, iterBegin, iterEnd, target, oldsum);
                }else{
                    iterEnd--;
                    oldsum = *iterBegin + *p + *iterEnd;
                    moveP(&p, nums, iterBegin, iterEnd, target, oldsum);
                }
            }else{
                break;
            }
        }
        // cout << *iterBegin << endl;
        // cout << *p << endl;
        // cout << *iterEnd << endl;
        // cout << "--------------" << endl;
        return oldsum;
    }
    void moveP( vector<int>::iterator *pointer, 
    vector<int> &nums, vector<int>::iterator B, vector<int>::iterator E, int target, int &oldsum){
        while (*pointer + 1 < E && calculate(oldsum, *(*pointer + 1), *B, *E, target)) // 向右
        {
            *pointer++;
            oldsum = **pointer + *B + *E;
        }
        while (*pointer - 1 > B && calculate(oldsum, *(*pointer + 1), *B, *E, target)) // 向左
        {
            *pointer--;
            oldsum = **pointer + *B + *E;
        }
        return;
    }

    bool calculate(int oldsum, int a, int b, int c, int target){
        int sum = a + b + c;
        if (findDiff(oldsum, target) > findDiff(sum, target)) {
            return true;
        }
        return false;
    }
    int findDiff(int sum, int target){
        // if(target - sum > 0){
        //     return target - sum;
        // }
        // return sum - target;

        int diff = target - sum > 0 ? target - sum : sum - target;
        return diff;
    }

};
int main()
{
    Solution c;
    vector<int> testSolution = {-1,2,1,-4};
    cout << c.threeSumClosest(testSolution, 1);
    return 0;
}