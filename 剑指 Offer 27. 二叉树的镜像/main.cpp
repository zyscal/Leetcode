#include<iostream>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

TreeNode* BFS(TreeNode* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    swap(root->left, root->right);
    root->left = BFS(root->left);
    root->right = BFS(root->right);
    return root;
}
      TreeNode* mirrorTree(TreeNode* root) {
          return BFS(root);

    }
