#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void f1(vector<int> &ans, int num)
{
    if(num <= 54)
    {
        ans[0]++;
    }
    else if(num <= 83)
    {
        ans[3]++;
    }
    else if(num <= 367)
    {
        ans[1]++;
    }
    else if(num <= 552)
    {
        ans[4]++;
    }
    else if(num <= 679)
    {
        ans[2]++;
    }
    else
    {
        ans[5]++;
    }
}
int main()
{
    vector<int> ans(6, 0);
    vector<string> ans_string;
    ans_string.push_back("2-DH1");
    ans_string.push_back("2-DH3");
    ans_string.push_back("2-DH5");
    ans_string.push_back("3-DH1");
    ans_string.push_back("3-DH3");
    ans_string.push_back("3-DH5");
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        f1(ans, a);
    }
    int check = false;
    while(!check)
    {
        check = true;
        for(int i = 5; i > 0; i--)
        {
            if(ans.at(i) > ans.at(i - 1))
            {
                swap(ans.at(i), ans.at(i - 1));
                swap(ans_string.at(i), ans_string.at(i - 1));
                check = false;
            }
        }
    }
    int i = 0;
    while (i <= 5 && ans.at(i) != 0 )
    {
        cout << ans_string.at(i) << " " << ans.at(i) << endl;
        i++;
        /* code */
    }
    
    return 0;
}