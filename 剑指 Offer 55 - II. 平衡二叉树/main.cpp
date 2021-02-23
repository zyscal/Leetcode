#include<iostream>
#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    typedef pair<int, int> pairtype;
    bool isBalanced(TreeNode* root) {
        if(check_balanced(root) == -1)
        {
            return false;
        }
        return true;
    }
    int check_balanced(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = check_balanced(root->left);
        int right = check_balanced(root->right);
        if(left == -1 || right == -1 || right - left > 1 || left - right > 1)
        {
            return -1;
        }
        return max(left, right) + 1;
    }

};