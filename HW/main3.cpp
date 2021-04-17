#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int ans = 1;
    long long max_tran = 0;
    long long max_tem_tran = 0;
    int n;
    cin >> n;
    if(n != 0)
        getchar();
    for(int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if(i == 0)
        {
            if(a >= n - 1)
            {
                if(n == 1 || n == 0)
                {
                    cout << "0";
                }
                else
                {
                    cout << ans;
                }
                return 0;
            }
            max_tran = a;
            max_tem_tran = a;
        }
        else if(i <= max_tran)
        {
            max_tem_tran = max(max_tem_tran, i + a);
            if(max_tem_tran >= n - 1)
            {
                cout << ans + 1;
                return 0;
            }
        }
        else if(i > max_tran)
        {
            ans += 1;
            max_tran = max_tem_tran;
            max_tem_tran = max(max_tem_tran, i + a);
            if(max_tem_tran >= n - 1)
            {
                cout << ans + 1 ;
                return 0;
            }
        }
    }
    if(n == 0 || n == 1)
        cout << "0";
    else 
        cout << ans;
    return 0;
}