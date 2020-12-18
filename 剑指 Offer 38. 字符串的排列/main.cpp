
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<int> a(127,0);
        for(int i = 0; i < s.size(); i++)
        {
            char Chars = s[i];
            a[Chars]++;
        }
        return findans(a);
    }
    vector<string> findans(vector<int> &char_list)
    {
        bool check = true;
        vector<string> ans;
        for(int i = 0; i < char_list.size(); i++)
        {
            if(char_list[i] > 0)
            {
                check = false;
                vector<int> temchar_list(char_list);
                temchar_list[i]--;
                char first = i;
                
                vector<string> temans = findans(temchar_list);
                for(int j = 0; j < temans.size(); j++)
                {
                    string temans_string(&first,1);
                    temans_string += temans[j];
                    ans.push_back(temans_string);
                }
                if(temans.size() == 0)
                {
                    string temans_string(&first,1);
                    ans.push_back(temans_string);
                }
                temchar_list[i]++;
            }
        }
        return ans;
    }

};
    int main()
    {
        Solution a;
        vector<string> ans(a.permutation("aabc"));
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }
    }