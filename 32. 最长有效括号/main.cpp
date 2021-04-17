#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int count_left = 0;
        int ans = 0;
        if(s.size() == 0)
        {
            return 0;
        }
        int tem_ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(count_left != 0)
                {
                    count_left--;
                    tem_ans++;
                }
                else
                {
                    ans = max(ans, tem_ans * 2);
                    tem_ans = 0;
                }
            }
            else
            {
                count_left++;
            }
    
        }
        ans = max(ans, tem_ans * 2); 
        return ans;
    }
};