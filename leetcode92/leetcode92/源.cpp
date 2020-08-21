#include<stdio.h>
#include<iostream>
using namespace std;
int numTrees(int n) {
	int* G = (int*)malloc(sizeof(int) * (n + 1));
	G[0] = 1;
	G[1] = 1;
	for (int i = 2; i <= n; i++) {
		int thiscount = 0;
		for (int j = 1; j <= i; j++) {
			thiscount += G[j - 1] * G[i - j];
		}
		G[i] = thiscount;
	}
	return G[n];
}


int main() {
	cout << numTrees(1) << endl;
	return 0;
}