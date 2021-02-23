#include<iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int count_right = find_count_right(root->right);
        if(count_right == k - 1)
        {
            return root->val;
        }
        else if(count_right > k - 1)
        {
            return kthLargest(root->right, k);
        }
        else
        {
            return kthLargest(root->left, k - count_right - 1);
        }
    }
    int find_count_right(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int right = find_count_right(root->right);
        int left = find_count_right(root->left);
        return left + right + 1;
    }
};