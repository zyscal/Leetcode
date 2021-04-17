#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
queue<long long> ans_list;
int main()
{
    int low, high, k;
    cin >> low >> high >> k;
    for(int i = 0; i <= 9 && i <= high; i++)
    {
        if(i >= low)
        {
            cout << i << " ";
        }
    }
    for(int i = 1; i <= 9 && i <= high; i++)
    {
        ans_list.push(i);
    }
    while (ans_list.empty() == false)
    {
        long long root_num = ans_list.front();
        ans_list.pop();
        long long root_last_num = root_num % 10;
        if(root_last_num - k >= 0)
        {
            long long tem_left = root_num * 10 + (root_last_num - k);
            if(tem_left >= low && tem_left <= high)
            {
                cout << tem_left << " ";
            }
            else if(tem_left >= high)
            {
                return 0;
            }
            ans_list.push(tem_left);
        }
        if(root_last_num + k <= 9 && k != 0)
        {
            long long tem_right = root_num * 10 + (root_last_num + k);
            if(tem_right >= low && tem_right <= high)
            {
                cout << tem_right << " ";
            }
            else if(tem_right >= high)
            {
                return 0;
            }
            ans_list.push(tem_right);
        }
    }
    
}