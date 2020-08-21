#include<iostream>
#include<vector>
#include<stdio.h>
#include<unordered_map>
using namespace std;
bool checkSubarraySum(vector<int>& nums, int k)
{
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0 && i + 1 < nums.size() && nums[i + 1] == 0)
		{
			return true;
		}
	}
	if (k == 0)
	{
		return false;
	}
	unordered_map<int, int> map;
	map.insert(pair<int, int>(0, -1));
	int rum = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		rum += nums[i];
		rum %= k;
		cout << rum << " ";
		auto iter = map.insert(pair<int, int>(rum, i));
		if (iter.second)
		{
			continue;
		}
		else if( i - iter.first->second >1)
		{
			return true;
		}
	}
	return false;

}
int main()
{
	vector <int> nums;
	nums = { 0,1,0 };
	cout << checkSubarraySum(nums, 1) << endl;
	return 0;
}