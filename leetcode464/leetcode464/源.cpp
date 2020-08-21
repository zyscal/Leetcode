#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<bitset>
#include<string>
using namespace std;
unordered_map<bitset<22>, bool> map;
typedef pair<bitset<22>, bool> pairtype;
typedef bitset<22> bittype;

bool dfs(int nowtotal, bitset<22> chose,int maxChoose)
{
	auto findthing = map.find(chose);//如果记忆中存在直接返回
	if (findthing != map.end())
	{
		return findthing->second;
	}
	if (nowtotal <= 0)
	{
		map.insert(pairtype(chose, true));
		return true;
	}
	bool ans = true;
	for (int i = 1; i <= maxChoose; i++)
	{
		if (chose[i] == 0)
		{
			bittype temtype(chose);
			temtype[i] = 1;
			if (dfs(nowtotal - i, temtype, maxChoose))
			{
				map.insert(pairtype(chose, false));
				ans = false;
				return ans;
			}
		}
	}
	map.insert(pairtype(chose, true));
	return ans;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) 
{
	bittype ans;
	int count = 0;
	if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
	{
		return false;
	}
	if (maxChoosableInteger > desiredTotal)
		return true;
	if (dfs(desiredTotal, ans, maxChoosableInteger))
	{
		return false;
	}
	return true;
}

int main()
{
	
	//unordered_map<int, string> test;
	//test.insert(inserttype(5, "test5"));
	//test.insert(inserttype(4, "test4"));
	//test.insert(inserttype(3, "test3"));
	//test.insert(inserttype(2, "test2"));
	//test.insert(inserttype(1, "test1"));
	//test.insert(inserttype(6, "test6"));
	//auto testinsert = test.insert(inserttype(7, "test7"));
	//cout << testinsert.second << " " << testinsert.first->first << testinsert.first->second << endl;
	//testinsert = test.insert(inserttype(7, "test7"));
	//cout << testinsert.second << " " << testinsert.first->first << testinsert.first->second << endl;
	//bool a = test.erase(6);
	//cout << a << endl;
	//a = test.erase(6);
	//cout << a << endl;
	//auto iter = test.begin();
	//while (iter != test.end())
	//{
	//	cout << iter->first<<" "<<iter->second << endl;
	//	iter++;
	//}
	//cout << "-----------------" << endl;
	//auto findtest = test.find(1);
	//cout << findtest->first << findtest->second << endl;
	//findtest = test.find(10);

	cout<<canIWin(10,0);
	return 0;
}