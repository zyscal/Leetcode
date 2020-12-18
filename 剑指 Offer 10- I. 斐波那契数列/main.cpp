#include<iostream>
using namespace std;
int fib(int n) {
    int n1 = 0;//第n - 1项
    int n2 = 1;//第n - 2项
    if(n == 0)
        return n1;
    if(n == 1)
        return n2;
    for(int i = 2; i<=n; i++)
    {
        int tem = (n1 + n2)%1000000007;
        n1 = n2;
        n2 = tem;
    }
    return n2;

}
int main()
{
    cout<<fib(100);
    return 0;
}