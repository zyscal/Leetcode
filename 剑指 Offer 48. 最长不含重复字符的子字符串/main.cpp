#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> slist;
        int maxlen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            char tem = s[i];
            sinlist(tem, slist, maxlen);
        }
        return maxlen;
    }
    void sinlist(char a, vector<char> &slist, int &maxlen)
    {
        if(slist.size() == 0)
        {
            slist.push_back(a);
            maxlen = max(maxlen, (int)slist.size());
            return ;
        }
        for(int i = 0; i < slist.size(); i++)
        {
            if(a == slist[i])
            {
                maxlen = max(maxlen, (int)slist.size());
                slist.erase(slist.begin(), slist.begin() + i + 1);
                slist.push_back(a);
                return ;
            }
        }
        slist.push_back(a);
            maxlen = max(maxlen, (int)slist.size());
        return;
    }
};

int main()
{
    Solution a;
    string aa = "abcabcbb";
    cout << a.lengthOfLongestSubstring(aa);
}