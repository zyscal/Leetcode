
//打家劫舍树状解决方案一（不成立）：
//尝试用数组存储树从而降低遍历复杂度，但空间过大，导致遍历超时
//#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//void treetovector(TreeNode* root, int n, vector<int>& dp)
//{
//	while (dp.size() <= n)
//	{
//		dp.push_back(-1);
//	}
//	dp[n] = root->val;
//	if (root->left != NULL)
//		treetovector(root->left, 2 * n + 1, dp);
//	if (root->right != NULL)
//		treetovector(root->right, 2 * n + 2, dp);
//}
//int fillmaxchose(int n, vector<int>& dp, vector<int>& maxchose)
//{
//	if (n >= dp.size())
//	{
//		return 0;
//	}
//	if (dp[n] == -1)//自身为空
//	{
//		maxchose[n] = 0;
//		return 0;
//	}
//	//其他情况，比较选择自身与不选择自身
//	if (maxchose[n] != -1)
//		return maxchose[n];
//	int notchosemyself = fillmaxchose(2 * n + 1, dp, maxchose) + fillmaxchose(2 * n + 2, dp, maxchose);
//	int chosemyself = fillmaxchose(4 * n + 3, dp, maxchose) + fillmaxchose(4 * n + 4, dp, maxchose) + fillmaxchose(4 * n + 5, dp, maxchose) + fillmaxchose(4 * n + 6, dp, maxchose) + dp[n];
//	if (n == 1)
//	{
//		cout << "notchose:" << notchosemyself << endl;
//		cout << "chose:" << chosemyself << endl;
//	}
//	maxchose[n] = max(notchosemyself, chosemyself);
//	return maxchose[n];
//}
//
//int rob(TreeNode* root) {
//	vector<int> dp;
//	treetovector(root, 0, dp);
//	for (int i = 0; i < dp.size(); i++)
//	{
//		cout << dp[i] << " ";
//	}
//	cout << endl;
//	vector<int> maxchose(dp.size(), -1);
//	cout << "maxchose:" << endl;
//	for (int i = 0; i < maxchose.size(); i++)
//	{
//		cout << maxchose[i] << " ";
//	}
//	cout << endl;
//	//return fillmaxchose(0, dp, maxchose);
//	fillmaxchose(0, dp, maxchose);
//	for(int i = 0; i < maxchose.size(); i++) {
//		cout << maxchose[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}
//int main() {
//	TreeNode root = TreeNode(3);
//	root.left = &TreeNode(4);
//	root.right = &TreeNode(5);
//	root.left->left = &TreeNode(1);
//	root.left->right = &TreeNode(3);
//	root.right->right = &TreeNode(1);
//	cout << rob(&root) << endl;
//	return 0;
//}

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int* BFS(TreeNode* root)//0为不放，1为放
{
    int* ans = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < 2; i++)
    {
        ans[i] = 0;
    }
    cout << ans[0] << ans[1] << endl;
    if (root == NULL)
    {
        return ans;
    }
    int* leftans = BFS(root->left);
    int* rightans = BFS(root->right);
    cout << endl;
    cout << "root:" << root->val << endl;
    cout << "left[0]:" << leftans[0] << endl;
    cout << "left[1]:" << leftans[1] << endl;
    cout << "right[0]:" << rightans[0] << endl;
    cout << "right[0]:" << rightans[1] << endl;
    ans[0] = max(leftans[0], leftans[1]) + max(rightans[0], rightans[1]);
    ans[1] = leftans[0] + rightans[0] + root->val;

    cout << "ans0:" << ans[0] << endl;
    cout << "ans1:" << ans[1] << endl;
    return ans;
}
int rob(TreeNode* root) 
{
    int* ans = BFS(root);
    return max(ans[0], ans[1]);
}
int main()
{
    TreeNode root = TreeNode(3);
	root.left = &TreeNode(4);
	root.right = &TreeNode(5);
	root.left->left = &TreeNode(1);
	root.left->right = &TreeNode(3);
	root.right->right = &TreeNode(1);
    cout << rob(&root);

	return 0;
}