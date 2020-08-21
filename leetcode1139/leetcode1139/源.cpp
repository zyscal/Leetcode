#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int largest1BorderedSquare(vector<vector<int>>& grid) {
	vector<vector<int>> x(grid), y(grid);
	int hang = grid.size();
	int lie = grid[0].size();
	int ans = 0;
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			if (grid[i][j] == 1) {
				ans = 1;
				break;
			}
		}
		if (ans == 1) {
			break;
		}
	}
	for (int i = 0; i < hang; i++) {
		for (int j = 1; j < lie; j++) {
			x[i][j] = x[i][j - 1] + grid[i][j];
		}
	}
	for (int j = 0; j < lie; j++) {
		for (int i = 1; i < hang; i++) {
			y[i][j] = y[i - 1][j] + grid[i][j];
		}
	}

	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			int count = 1;
			while (grid[i][j] == 1 && i + count < hang && j + count < lie && grid[i + count][j] == 1 && grid[i][j + count] == 1) {
				int mx, my;
				mx = i + count;
				my = j + count;
				if (x[mx][my] - x[mx][j] == count && y[mx][my] - y[i][my] == count) {
					ans = max(ans, count + 1);
				}
				count++;
			}
		}
	}
	return ans * ans;
}

int main() {
	vector<vector<int>> x = { {0,1},{1,1} };
	cout<<largest1BorderedSquare(x)<<endl;
	return 0;
}