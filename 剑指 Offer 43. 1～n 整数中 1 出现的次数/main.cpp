#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;



class Solution {
public:
/**
 *按照数字n的每一位进行计算
 设第k位数字是i，i前的数字值为m，i后有n位，nn位组成的数字为a
 例如23165，当k = 2 时，i == 1，m == 23，nn == 2， a == 65
 当i == 2到9时：
    该位置出现1的次数为（m + 1）*10^n
 当i == 1时：
    该位置出现1的次数为m*10^nn + a + 1
 当i == 0时：
    该位置出现1的次数为m*10^nn
 */
    int countDigitOne(int n) {
        int len = length(n);
        int i = n % 10;
        int m = n / 10;
        int a = 0;
        int nn = 0;
        int ans = 0;
        for(int k = 0; k < len; k++)
        {
            if(i > 1)
            {
                ans += (m + 1)*pow(10, nn);
            }
            else if(i == 1)
            {
                ans += m*pow(10, nn) + a + 1;
            }
            else
            {
                ans += m*pow(10, nn);
            }
            getnext(m, nn, i, a, k);
        }
        return ans;
    }
    void getnext(int &m, int& nn, int& i, int& a, int k)
    {
        a += i * pow(10, k);
        i = m % 10;
        
        nn++;
        m /= 10;
    }
    int length(int n)
    {
        int ans = 1;
        while(n / 10 != 0)
        {
            n /= 10;
            ans ++;
        }
        return ans;
    }
};
int main()
{
    cout << pow(10, 1) << endl;

    Solution a;
    for(int i = 0; i < 50; i++)
    {
        cout << i << " : " << a.countDigitOne(i) << endl;
    }
}