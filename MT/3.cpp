#include<iostream>
#include<vector>
using namespace std;

pair<int, int> get_ans(vector<long long> num_list, long long a)
{
    pair<int, int> ans(-1, -1);

    int i = 0;
    for(; i < num_list.size(); i++)
    {
        if(num_list.at(i) == a)
        {
            ans.first = i;
            break;
        }
    }
    if(i == num_list.size())
    {
        return ans;
    }
    for(i = num_list.size() - 1; i >= 0; i--)
    {
        if(num_list.at(i) == a)
        {
            ans.second = i;
            break;
        }
    }
    return ans;
}

int main()
{
    int n, m;

    cin >> n >> m;

    getchar();
    vector<long long> num_list;
    vector<long long> question_list;
    for(int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        num_list.push_back(num);
    }
    getchar();
    for(int i = 0; i < m; i++)
    {
        long long ques;
        cin >> ques;
        question_list.push_back(ques);
    }
    for(int i = 0; i < question_list.size() - 1; i++)
    {
        pair<int, int> tem_ans = get_ans(num_list, question_list.at(i));
        if (tem_ans.first != -1)
        {
            /* code */
            cout << tem_ans.first + 1 << " " << tem_ans.second + 1<< endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
        pair<int, int> tem_ans = get_ans(num_list, question_list.at(question_list.size() - 1));
        if (tem_ans.first != -1)
        {
            /* code */
            cout << tem_ans.first + 1 << " " << tem_ans.second + 1;
        }
        else
        {
            cout << 0 ;
        }
    return 0;
}