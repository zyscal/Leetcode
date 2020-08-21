#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string convert(string s, int numRows) {
	int lengthofs = s.size();
	int dn = 2 * numRows - 2;
	if (dn == 0)
		return s;
	vector<string> ans(numRows,"");
	for (int i = 0; i < numRows; i++) {
		if (i == 0 || dn == 2 * i) {
			int countn = 0;
			while (i + countn * dn < lengthofs) {
				ans[i] += s[i + countn * dn];
				countn++;
			}
		}
		else if (i < lengthofs && dn - i != i) {
			int countn = 0;
			while (i + dn * countn < lengthofs) {
				ans[i] += s[i + dn * countn];
				if (i + dn * countn + 2 * (numRows - i - 1) < lengthofs && numRows - i - 1 != 0) {
					ans[i] += s[i + dn * countn + 2 * (numRows - i - 1)];
				}
				countn++;
			}
		}
	}
	string theansstring = "";
	for (int i = 0; i < numRows; i++) {
		theansstring += ans[i];
	}
	return theansstring;
}

int main() {
	string s = "LEETCODEISHIRING";
	cout << convert(s,4) << endl;

	s = "A";
	cout << convert(s, 1) << endl;
	return 0;
}