#include<iostream>
#include <vector>
#include<algorithm>
#include<math.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size()) {
		return findMedianSortedArrays(nums2, nums1);
	}
	int m = nums1.size();
	int n = nums2.size();
	if (m == 0)
	{
		return n % 2 == 1 ? nums2[n / 2] * 1.0 : ((double)nums2[n / 2] + (double)nums2[n / 2 - 1]) / 2.0;
	}
	int half = (m + n) / 2 ;
	long long point1 = m / 2;
	long long point2 = half - point1;
	cout << "m:" << m << " n:" << n << endl;
	cout << "half:" << half << endl;
	cout << "1:" << point1 << " 2:" << point2 << endl;
	//ÄÜ·ñÏò×óÒÆ
	while (point1 > 0) 
	{
		if (nums1[point1 - 1] >= nums2[point2])
		{
			point1--;
			point2++;
		}
		else
		{
			break;
		}
	}
	while (point1 < m)
	{
		if (nums1[point1] < nums2[point2 - 1])
		{
			point1++;
			point2--;
		}
		else
		{
			break;
		}
	}
	cout << "point1 :" << point1 << " point2:" << point2 << endl;

	int left, right;
	if (point1 == 0) 
	{
		left = nums2[point2 - 1];
		right = n ==m ? nums1[point1] : min(nums1[point1], nums2[point2]);
	}
	else if (point1 == m)
	{
		right = nums2[point2];
		left = n-m <=1  ? nums1[point1 - 1] : max(nums1[point1 - 1], nums2[point2 - 1]);
	}
	else
	{
		left = max(nums1[point1 - 1], nums2[point2 - 1]);
		right = min(nums1[point1], nums2[point2]);
	}
	if ((m + n) % 2 == 1) {
		return (double)right * 1.0;
	}
	else
	{
		return (((double)left + (double)right) / 2.0);
	}
}
int main() {
	vector<int> a, b;
	a.push_back(-2);
	a.push_back(-1);
	b.push_back(3);
	//b.push_back(4);
	cout<<findMedianSortedArrays(a, b);
	return 0;
}