#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) 
{

	auto iter = nums.begin();
	int maxans = -101;
	while (iter != nums.end())
	{
		if (*iter > 0)
		{
			maxans = 0;
			iter = nums.begin();
			break;
		}
		else
		{
			maxans = max(maxans, *iter);
		}
		iter++;
	}


	
	while (iter != nums.end())
	{
		while ( iter != nums.end() && *iter <= 0)
		{
			iter++;
		}
		int temans = 0;
		while (iter != nums.end() && temans >= 0)
		{
			temans += *iter;
			maxans = max(maxans, temans);
			iter++;
		}
	}
	return maxans;
}

int main()
{
	vector<int> nums;
	nums = { -2,-1};
	cout << maxSubArray(nums) << endl;
}