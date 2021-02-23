#include<iostream>
#include<vector>

#include<math.h>
using namespace std;


class Solution {
public:
    int nthUglyNumber(int n) {
            vector<long long> dnum = {2, 3, 5};
            long long the_ans_pos_num = LONG_MAX;
            vector<long long> list = {1};
            vector<long long> last_n = {1};//上一个n产生的
            long long min_2_n = 1;
            long long count_mi = 1;
            while(min_2_n < the_ans_pos_num)
            {
                min_2_n *= 2;
                vector<long long> this_n;
                for(int i = 0; i < last_n.size(); i++)
                {
                    for(int j = 0; j < dnum.size(); j++)
                    {
                        if(list.size() >= n && list[n - 1] <= last_n[i] * dnum[j])
                        {
                            continue;
                        }
                        insert_sorted(this_n, last_n[i] * dnum[j]);
                    }
                }
                insert_sorted_vector(list, this_n, n);
                if(list.size() >= n)
                {
                    the_ans_pos_num = list[n - 1];
                }
                last_n = this_n;
                count_mi++;
            }
            cout << list.size() << endl;
            return the_ans_pos_num;
    }
    void insert_sorted_vector(vector<long long> &a, vector<long long> &b, int n)
    {
        for(int i = 0; i < b.size(); i++)
        {
            if(a.size() >= n && a[n - 1] <= b[i])
            {
                break;
            }
            insert_sorted(a, b[i]);
        }
        return ;
    }

    void insert_sorted(vector<long long> &list, long long num)
    {
        for(int i = 0; i < list.size(); i++)
        {
            if(num < list[i])
            {
                list.insert(list.begin() + i, num);
                return ;
            }
            if(num == list[i])
            {
                return;
            }
        }
        list.push_back(num);
        return ;
    }
};

int main()
{
    Solution a;
    cout << a.nthUglyNumber(1690) << " ";


}