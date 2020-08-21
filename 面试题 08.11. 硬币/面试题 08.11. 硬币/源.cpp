#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;



long long wallet[4] = { 1,5,10,25 };
int waysToChange(int n) 
{
	long long** ans = (long long**)malloc(sizeof(long long*) * 4);
	for (int i = 0; i < 4; i++)
	{
		ans[i] = (long long*)malloc(sizeof(long long) * (n + 1));
		for (int j = 0; j < n + 1; j++)
		{
			ans[i][j] = 0;
			if (i == 0 || j == 0)
			{
				ans[i][j] = 1;
			}
		}
	}
	for (int j = 1; j < n + 1; j++)
	{
		for (int i = 1; i < 4; i++)
		{
			if (j >= wallet[i])//此处时间优化
			{
				ans[i][j] = ans[i - 1][j] + ans[i][j - wallet[i]];
			}
			else
			{
				ans[i][j] = ans[i - 1][j];
			}
			
		}
	}
	return (int)(ans[3][n]% 1000000007);
}

int main()
{
	cout << waysToChange(900750) << endl;
	return 0;
}