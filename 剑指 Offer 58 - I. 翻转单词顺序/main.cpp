#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        vector< vector<char>> word_list;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                continue;
            }
            else
            {
                vector<char> word;
                while (i != s.size() && s[i] != ' ')
                {
                    word.push_back(s[i]);
                    i++;
                    /* code */
                }
                word_list.push_back(word);
            }
        }
        string ans = "";
        if(word_list.size() == 0)
        {
            return ans;
        }
        for(int i = word_list.size() - 1; i > 0; i--)
        {
            for(int j = 0; j < word_list[i].size(); j++)
            {
                ans += word_list[i][j];
            }
            ans += " ";
        }
        for(int i = 0; i < word_list[0].size(); i++)
        {
            ans += word_list[0][i];
        }
        return ans;
    }
};
int main()
{
    Solution a;
    cout << a.reverseWords("the sky is blue") << endl;
}