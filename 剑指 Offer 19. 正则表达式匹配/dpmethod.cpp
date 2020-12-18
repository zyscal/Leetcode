#include<iostream>
#include<vector>
using namespace std;

bool isMatch(string s, string p)
{
    s = "#" + s;
    p = "#" + p;
    vector< vector<int>> ansdp(s.size() + 1);
    for(int i = 0; i < s.size() + 1; i++)
    {
        ansdp[i].resize(p.size() + 1, false);
    }
    ansdp[0][0] = true;

    for (int j = 1; j <= p.size(); j++)
    {
        for(int i = 1; i <= s.size(); i++)
        {
            if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
            {
                ansdp[i][j] = ansdp[i - 1][j - 1];          
            }
            if(p[j - 1] == '*')
            {
                if(ansdp[i][j- 2])
                {
                    ansdp[i][j] = true;
                }
                else if(s[i - 1] == p[j - 1 - 1] || p[j - 1 - 1] == '.')
                {
                    ansdp[i][j] = ansdp[i - 1][j];
                }
            }

        }

    }
    for(int i = 0; i <= s.size(); i++)
    {
        for(int j = 0; j <= p.size(); j++)
        {
            cout<<ansdp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ansdp[s.size()][p.size()];
}
int main()
{
    cout<<isMatch("ab",".*")<<endl;
    return 0;
}