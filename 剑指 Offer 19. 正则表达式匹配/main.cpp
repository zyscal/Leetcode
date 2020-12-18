#include<iostream>
#include<vector>
using namespace std;



bool findans(string s, string p, int i, int j, vector< vector<int>> &ans)
{
    if(i >= 0 && j < 0)//模式没了，但是字符串还有
    {
        return false;
    }
    if(i < 0 && j < 0)//模式跟字符串都没
    {
        return true;
    }
    if(p[j] == '.' && i >= 0)
    {
        ans[i][j] = findans(s, p, i - 1, j - 1, ans);
        return ans[i][j];
    }
    if(p[j] != '*' && p[j] != '.' && i >= 0)
    {
        if(s[i] != p[j])
        {
            ans[i][j] = false;
            return ans[i][j];
        }
        else
        {
            ans[i][j] = findans(s, p, i- 1, j - 1, ans);
            return ans[i][j];
        }
    }
    else if(p[j] == '*' && i >= 0)
    {
        //不看这一个
        if(findans(s, p, i, j - 2, ans))
        {
            ans[i][j] = true;
            return ans[i][j];
        }
        //看这一个
        if(s[i] == p[j - 1] || p[j - 1] == '.')
        {
            ans[i][j] = findans(s, p, i - 1, j, ans);
            return ans[i][j];
        }
    }
    else if(p[j] == '*' && i < 0)
    {
        return findans(s, p, i, j - 2, ans);
    }
    
    return false;
    
}
bool isMatch(string s, string p) {
    vector< vector<int>> ans(s.size() + 1);
    for(int i = 0; i < ans.size(); i++)
    {
        ans[i].resize(p.size() + 1, false);
    }
    int i = s.size() - 1;
    int j = p.size() - 1;
    return findans(s, p, i, j, ans);
}
int main()
{
    cout<<isMatch("mississippi","mis*is*p*.");
    return 0;
}