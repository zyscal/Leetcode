#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
typedef pair<char, int> pairtype;
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> once;
        unordered_map<char, int> not_only_once;
        for(int i = 0; i < s.size(); i++)
        {
            if(not_only_once.find(s[i]) != not_only_once.end())
            {
                continue;
            }
            else 
            {
                if(once.find(s[i]) != once.end())
                {
                    once.erase(s[i]);
                    not_only_once.insert(pairtype(s[i], 0));
                }
                else
                {
                    once.insert(pairtype(s[i], i));
                }
            }
        }
        if(once.size() == 0)
        {
            return ' ';
        }
        auto iter = once.begin();
        int min = 9999999;
        char ans;
        while (iter != once.end())
        {
            if(iter->second < min)
            {
                min = iter->second;
                ans = iter->first;
            }
            iter ++;
        }
        return ans;
    }
};
int main()
{
    Solution a;
    cout << a.firstUniqChar("abaccdeff");
}