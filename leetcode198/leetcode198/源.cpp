#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//int rob1(vector<int>& nums) {//198打家劫舍
//	vector<int> ans;
//	int len = nums.size();
//	if (len == 1)
//		return nums[0];
//	else if (len == 2)
//		return max(nums[0], nums[1]);
//	else if (len == 0)
//		return 0;
//	ans.push_back(nums[0]);
//	ans.push_back(max(nums[0], nums[1]));
//	for (int i = 2; i < len; i++) {
//		ans.push_back(max(ans[i - 1], ans[i - 2] + nums[i]));
//	}
//	for (int i = 0; i < len; i++) {
//		cout << ans[i] << " ";
//	}
//	return ans[len - 1];
//}

int rob2(vector<int>& nums) {//213打家劫舍II
	vector<int> ans;
	int len = nums.size();
	if (len == 1)
		return nums[0];
	else if (len == 2)
		return max(nums[0], nums[1]);
	else if (len == 0)
		return 0;
	ans.push_back(nums[0]);
	ans.push_back(max(nums[0], nums[1]));
	for (int i = 2; i < len; i++) {
		ans.push_back(max(ans[i - 1], ans[i - 2] + nums[i]));
	}
	for (int i = 0; i < len; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return ans[len - 1];
}
int rob(vector<int>& nums)
{
	if (nums.size() == 0)
		return 0;
	else if (nums.size() == 1)
		return nums[0];
	vector <int> keepfirst(nums.begin(),nums.end() - 1);
	for (int i = 0; i < keepfirst.size(); i++) {
		cout << keepfirst[i] << " ";
	}
	cout << endl;
	int getfirst = rob2(keepfirst);
	cout << "getfirst:" << getfirst << endl;
	vector <int> keeplast(nums.begin() + 1, nums.end());
	for (int i = 0; i < keeplast.size(); i++) {
		cout << keeplast[i] << " ";
	}
	cout << endl;
	int getlash = rob2(keeplast);
	cout << "getlash:" << getlash << endl;
	return max(getfirst, getlash);
}


int main() {
	vector<int> nums = { 1,2,3,1 };
	cout << rob(nums) << endl;
	return 0;
}