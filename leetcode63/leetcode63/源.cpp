#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m, n;
		m = obstacleGrid.size();
		n = obstacleGrid[0].size();
		int* upon = (int*)malloc(sizeof(int) * n);

		if (obstacleGrid[0][0] == 0) {
			upon[0] = 1;
		}
		else {
			upon[0] = 0;
		}
	
		for (int i = 1; i < n; i++) {
			if (obstacleGrid[0][i] == 1) {
				upon[i] = 0;
			}
			else {
				upon[i] = upon[i - 1];
			}
		}//初始化第一行
	
		for (int i = 1; i < m; i++) {
			if (obstacleGrid[i][0] == 1)
				upon[0] = 0;

			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 1) {
					upon[j] = 0;
				}
				else {
					upon[j] += upon[j - 1];
				}
			}
		}

		return upon[n - 1];

}
int main() {
	vector<vector<int> > tem = { {1},{0}};
	cout << uniquePathsWithObstacles(tem) << endl;
	return 0;
}