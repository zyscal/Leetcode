#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int getMoneyAmount(int n) 
{
	vector< vector<int> > ansdp(n + 2);
	for (int i = 0; i < n + 2; i++)
	{
		ansdp[i].resize(n + 2, 0);
	}
	for (int i = 1; i <= n - 1; i++)//��ֵ
	{
		for (int j = 1; j <= n - i; j++)
		{
			int temans = n * n;
			int left = j;
			int right = j + i;
			for (int k = left; k <= right; k++)//��ÿһ��λ����Ϊ�ָ���ҵ���С�ķָ�㣬�㷨:max����ߣ��ұߣ� + �Լ�λ�� = ��ǰ�ָ���ֵ
			{
				temans = min(temans, k + max(ansdp[left][k - 1], ansdp[k + 1][right]));
			}
			ansdp[left][right] = temans;
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << ansdp[i][j] << " ";
		}
		cout << endl;
	}
	return ansdp[1][n];
}

int main()
{
	cout << getMoneyAmount(5) << endl;;
	return 0;
}

