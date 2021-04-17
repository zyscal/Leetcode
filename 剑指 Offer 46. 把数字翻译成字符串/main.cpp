#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        vector<int> everynum;
        int lenofnum = getlen(num, everynum);
        vector<int> ans(lenofnum, 0);
        ans[0] = 1;
        for(int i = 1; i < ans.size(); i++)
        {
            if(isaletter(everynum[i - 1], everynum[i]) && i != 1)
            {
                ans[i] = ans[i - 1] + ans[i - 2];
            }
            else if(!isaletter(everynum[i - 1], everynum[i]))
            {
                ans[i] = ans[i - 1];
            }
            else if(isaletter(everynum[i - 1], everynum[i] && i == 1))
            {
                ans[i] = ans[i - 1] + 1;
            }
        }
        // for(int i = 0; i < ans.size(); i++)
        // {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        return ans.back();
    }
    int getlen(int num, vector<int> &everynum)
    {
        int len = 1;
        while(num / 10)
        {
            everynum.insert(everynum.begin(), num % 10);
            len++;
            num /= 10;
        }
        everynum.insert(everynum.begin(), num);
        return len;
    }
    bool isaletter(int a,int b)
    {
        if(a == 0)
            return false;
        if(a * 10 + b <= 25)
        {
            return true;
        }
        return false;
    }

};    
int main()
    {
        int a = 506;
        Solution b;
        cout << b.translateNum(a) << endl;
    }