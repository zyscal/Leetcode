#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int chartoascll(char a) {
	return (int)a;
}

int lengthOfLongestSubstring(string s) {
	int bucket[150];
	for (int i = 0; i < 150; i++)
		bucket[i] = -1;
	int ans = 0;
	int temans = 0;
	int pointbegin = 0;
	int pointend = -1;
	int lenthofs = s.length();

	if (lenthofs == 0 || lenthofs == 1)
		return lenthofs;//当字符创长度为0或者为1时候，返回0或者1 

	while (pointend < lenthofs - 1) {
		cout << "pointbegin:" << pointbegin << " pointend:" << pointend << endl;
		pointend++;
		if (bucket[chartoascll(s[pointend])] == -1 || bucket[chartoascll(s[pointend])] < pointbegin) {
			bucket[chartoascll(s[pointend])] = pointend;
			temans = pointend - pointbegin + 1;
			cout << "temans:" << temans << endl;
			if (temans > ans)
				ans = temans;

		}
		else if(bucket[chartoascll(s[pointend])] >= pointbegin){
			pointbegin = bucket[chartoascll(s[pointend])] + 1;
			bucket[chartoascll(s[pointend])] = pointend;
		}
		
	}
	return ans;
}
int main() {
	string s = "tmmzuxt";
	//cout << s.length() << endl;
	//cout << s[0] << s[1] << s[2] << endl;
	//cout << chartoascll(s[0]) << endl;
	cout<<"the anser is:"<<lengthOfLongestSubstring(s)<<endl;
	return 0;
}