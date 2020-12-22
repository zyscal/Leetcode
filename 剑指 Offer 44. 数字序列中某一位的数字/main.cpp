#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10)
            return n;
        int wei = 1;
        long long sumbefore = 10;
        long long begin = 0;
        long long end = 9;
        while (n > end)
        {
            wei++;
            begin = end + 1;
            long long sumnow = pow(10, wei) - sumbefore;
            sumbefore += sumnow;
            end = sumnow * wei + begin - 1;
        }
        // cout << "begin : " << begin << endl;
        // cout << "end : " << end << endl;
        // cout << "wei : " << wei << endl;
        long long count = n - begin;
        long long countzu = count / wei;
        long long countwei = count % wei;
        long long findnum = pow(10, wei - 1) + countzu;
        // cout << "findnum : " << findnum << endl;
        // cout << "countwei : " << countwei << endl;
        return findans(findnum, countwei, wei);

    }
    int findans(long long a, long long b, long long wei)//a数中的第b位是谁
    {
        b = wei - b;
        //先求b+1余，去掉前面的
        //求b商，提取相应位
        long long temint = pow(10, b);
        a %= temint;
        // cout << "a : " << a <<endl;
        a = a / pow(10, b - 1);
        return a;
    }
};
int main()
{

    Solution a;
    cout << "ans" << a.findNthDigit(9);
    return 0;
}