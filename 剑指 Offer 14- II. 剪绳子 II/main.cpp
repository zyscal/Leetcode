#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int cuttingRope(int n) {
    if(n == 2)
    {
        return 1;
    }
    if(n == 3)
    {
        return 2;
    }
    if(n == 4)
    {
        return 4;
    }
    int ans = 1;
    while(n > 4)
    {
        ans *= 3;
        n -= 3;
        ans %= 1000000007;
    }
    ans *= n;
    ans %= 1000000007;
    return ans;
}
int main()
{
    return 0;
}