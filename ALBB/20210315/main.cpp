#include<iostream>
using namespace std;
float get_ans(float n)
{
    float ans = 0;
    for(int i = 1; i <= (n - 2) / 2; i++)
    {
        ans += (1 / ( n - 1 - i * 2)) * ((1.5 * n - 2 * i) * (n / 2 - 2 * i + 1) - n / 2);
    }
    for(int i = 1; i < (n - 2) / 2; i++)
    {
        ans += (1 / ( n - 1 - i * 2)) * ((1.5 * n - 2 * i) * (n / 2 - 2 * i + 1) - n / 2);
    }
    return (1 / (n - 1)) * ans;
}

int main()
{
    int n;
    cin >> n;
    cout << get_ans(n);
    return 0;
}