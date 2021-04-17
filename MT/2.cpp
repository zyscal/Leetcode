#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

long long get_tem_ans(long long a)
{
    return a/3;
}

int main()
{
    long long n, c1, c2;
    cin >> n >> c1 >> c2;
    long long small = min(c1, c2);
    long long tem_count = 0;
    long long count_of_small = 0;
    getchar();
    for(int i = 0; i < n; i++)
    {
        char a = getchar();
        if(a == 'F')
        {
            tem_count += 1;
        }
        else{
            count_of_small += get_tem_ans(tem_count);
            tem_count = 0;
        }
    }
    count_of_small += get_tem_ans(tem_count);
    cout << count_of_small * small;
    return 0;
}