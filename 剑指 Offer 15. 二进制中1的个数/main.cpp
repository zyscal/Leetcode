#include<iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int ans = 0;
    while(n>=1)
    {
        ans += n % 2 == 0 ? 0 : 1;
        n /= 2;
    }
    return ans;
}
int main()
{

}