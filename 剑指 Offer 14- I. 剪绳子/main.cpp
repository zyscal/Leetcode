#include<iostream>
#include<algorithm>
using namespace std;
int cuttingRope(int n) {
    int tem = 0;
    for(int i = 2; i <= n; i++)
    {
        int smallval = n / i;
        int largevalnum = n - smallval * i;
        int smallvalnum = i - largevalnum;
        int largeval = smallval + 1;

        int val = pow(smallval ,smallvalnum) * pow(largeval ,largevalnum);
        if(val < tem)
            return tem;
        else
        {
            tem = val;
        }
    }
    return tem;
}