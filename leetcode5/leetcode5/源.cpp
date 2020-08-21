#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
string longestPalindrome(string s) {
	int lengthofs = s.size();
	int** map = (int**)malloc(sizeof(int*) * (lengthofs + 1));
	for (int i = 0; i < lengthofs; i++) {
		map[i] = (int*)malloc(sizeof(int) * (lengthofs + 1));
	}
	for (int i = 0; i < lengthofs; i++) {
		map[i][i] = 1;
	}
	for (int j = 1; j < lengthofs; j++) {
		for (int i = 0; i < j; i++) {
			if (s[i] == s[j]) {
				if (j - i == 1) {
					map[i][j] = 2;
				}
				else if(map[i+1][j-1] == j - i - 1){
					map[i][j] = map[i+1][j-1] + 2;
				}
				else {
					map[i][j] = 0;
				}
			}
			else {
				map[i][j] = 0;
			}
		}
	}
	int ansi = 0;
	int ansj = 0;
	int anslen = 0;
	for (int j = 0; j < lengthofs; j++) {
		for (int i = 0; i <= j ; i++) {
			if (map[i][j] > anslen) {
				ansi = i;
				ansj = j;
				anslen = map[i][j];
			}
		}
	}
	string ans(anslen,'s');
	for (int i = ansi,j = 0; i <= ansj; i++,j++) {
		ans[j] = s[i];
	}

	return ans;
}

int main() {
	string s = "abcdedf";
	cout << longestPalindrome(s) << endl;
	return 0;
}