#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int add(int a, int b) {
        vector<int> vector_a = get_binary(a);
        vector<int> vector_b = get_binary(b);

    }
    vector<int> get_binary(int a)
    {
        vector<int> ans(33, 0);
        if(a < 0)
        {
            ans[0] = 1;
            a = -a;
        }
        int pos = 32;
        while(a/2 != 0)
        {
            ans[pos] = a%2;
            a /= 2;
            pos--;
        }
        ans[pos] = a;
        return ans;
    }
    vector<int> get_complement(vector<int> a)
    {
        if(a[0] == 0)
        {
            return a;
        }
        vector<int> com_a(1, 1);
        for(int i = 1; i < a.size(); i++)
        {
            if(a[i] == 0)
            {
                com_a.push_back(1);
            }
            else
            {
                com_a.push_back(0);
            }
        }
    }
    int get_next(int i)
    {
        
    }
};
int main()
{
    int a = -18;
    Solution b;
    vector<int> ans = b.get_binary(a);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}