#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSymmetric(TreeNode* root) {
    if(root == NULL)
    {
        return true;
    }
    return check(root->left, root->right);
    

}
bool check(TreeNode* left, TreeNode* right)
{
    if(left == NULL && right == NULL)
    {
        return true;
    }
    else if(left != NULL && right != NULL && left -> val == right -> val)
    {
        if(check(left->left, right->right) && check(left->right, right->left))
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    return false;
}
