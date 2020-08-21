#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int tallestBillboard(vector<int>& rods) {	
	if (rods.size() == 0)
		return 0;
	vector< vector<int>> ans(rods.size());
	int sum = 0;
	auto iter = rods.begin();
	while (iter != rods.end())
	{
		sum += *iter++;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		ans[i].resize(sum + 1, 0);
	}
	ans[0][rods[0]] = rods[0];
	int temcount = rods[0];
	for (int i = 1; i < rods.size(); i++)
	{
		vector<int> temansi(ans[i - 1]);//用于比较看到哪里
		vector<int> maxans(ans[i - 1]);//用于存储最大的答案
		int j = 0;
		while (temcount >= j)//放当前这个木柜只需要遍历到上一行temcount即可
		{
			if (j > temansi[j])
			{
				j++;
				continue;
			}

			cout << "j:"<<j<<" temansi[j]"<<temansi[j] << endl;
			maxans[j + rods[i]] = max(maxans[j + rods[i]], temansi[j] + rods[i]);//放左边
			if ( j - rods[i] >= 0 )//放右边，右边不如左边高
			{
				maxans[j - rods[i]] = max(maxans[j - rods[i]], temansi[j]);
				cout << j << endl;
				cout << rods[i] << endl;
				cout << temansi[j] << endl << endl;
			}
			else//放右边比左边高
			{
				maxans[rods[i] - j] = max(maxans[rods[i] - j], temansi[j] - j + rods[i]);
			}
			j++;
		}
		ans[i] = maxans;
		temcount += rods[i];
	}
	cout << "test" << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return ans[rods.size() - 1][0];
}

int main()
{
	vector<int> rods = { 100,100 };
	cout<<tallestBillboard(rods);

	return 0;
}