#include<queue>
#include<vector>
using namespace std;



class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int> > ans;
        for(int i = 0; i < arr.size(); i++)
        {
            ans.push(arr[i]);
        }
        vector<int> ansqueue;
        for(int i = 0; i < k; i++)
        {
            ansqueue.push_back(ans.top());
            ans.pop();
        }
        return ansqueue;
    }
};