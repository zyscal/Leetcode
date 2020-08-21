#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& nums)
{
	vector<int> ans(nums.size(), 0);
	if (nums.size() == 1)
		return 0;
	if (nums.size() == 2)
	{
		return nums[1];
	}
	ans[1] = nums[1];
	for (int i = 2; i < ans.size(); i++)
	{
		ans[i] = max(ans[i - 1], ans[i - 2] + nums[i] * i);
	}
	return ans[ans.size() - 1];
}

int deleteAndEarn(vector<int>& nums) {//转化为打家劫舍I
	int maxnum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		maxnum = max(maxnum, nums[i]);
	}
	vector<int> anslist(maxnum + 1, 0);
	for (int i = 0; i < nums.size(); i++)
	{
		anslist[nums[i]]++;
	}
	return rob(anslist);
}

int main()
{
	vector <int> nums = { 3,4,2};
	deleteAndEarn(nums);
	return 0;
}