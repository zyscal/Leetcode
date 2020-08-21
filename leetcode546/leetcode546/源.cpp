#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int calculation(int l, int r, int k,vector<int>& boxes,int ***map ) {
	if (l > r) {
		return 0;
	}
	if (map[l][r][k] != 0)
		return map[l][r][k];
	while (l < r && boxes[r] == boxes[r - 1])//找到右边连续的最左边一个
	{
		r--;
		k++;
	}
	map[l][r][k] = calculation(l,r - 1,0,boxes,map) + (k + 1) * (k + 1);
	for (int i = l; i < r; i++) {
		if (boxes[i] == boxes[r]) {
			map[l][r][k] = max(map[l][r][k], calculation(l, i, k + 1, boxes, map) + calculation(i + 1, r - 1, 0, boxes, map));
		}
	}
	return map[l][r][k];
}

int removeBoxes(vector<int>& boxes) {
	int lengthofboxs = boxes.size();
	int*** map = (int***)malloc(sizeof(int**) * lengthofboxs);
	for (int i = 0; i < lengthofboxs; i++) 
	{
		map[i] = (int**)malloc(sizeof(int*) * lengthofboxs);
		{
			for (int j = 0; j < lengthofboxs; j++) {
				map[i][j] = (int*)malloc(sizeof(int) * lengthofboxs);
				for (int k = 0; k < lengthofboxs; k++) {
					map[i][j][k] = 0;
				}
			}
		}
	}
	int l = 0;
	int r = lengthofboxs - 1;
	int k = 0;
	return calculation(l, r, k,boxes,map);
}


int main() {
	vector<int> boxes = { 1, 3, 2, 2, 2, 3, 4, 3, 1 };
	cout<<removeBoxes(boxes);
	return 0;
}