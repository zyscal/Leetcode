#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSatisfaction(vector<int>& satisfaction) 
{
	if (satisfaction.size() == 0)
		return 0;
	sort(satisfaction.begin(), satisfaction.end());
	vector<int> ans(satisfaction.size());
	int tem = 0;
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		if (i == ans.size() - 1)
		{
			ans[i] = -satisfaction[i];
			continue;
		}
		tem += satisfaction[i + 1];
		ans[i] = -1 * satisfaction[i] - tem;
	}
	int allcount = 0;
	for (int i = 0; i < satisfaction.size(); i++)
	{
		allcount += (i + 1) * satisfaction[i];
	}
	int the_ans = allcount;
	auto iter = ans.begin();
	while (iter != ans.end())
	{
		the_ans = max(the_ans, allcount + *iter);
		allcount += *iter;
		iter++;
	}
	return the_ans;
}

int main()
{
	vector<int> satis;
	satis = { -1,-4,-5};
	cout<<maxSatisfaction(satis);
	return 0;
}