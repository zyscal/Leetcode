#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x),left(NULL),right(NULL){}
};
vector<int> levelOrder(TreeNode* root) {
    
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }
    queue<TreeNode*> ansque;
    ansque.push(root);
    while(!ansque.empty())
    {
        TreeNode *temnode = ansque.front();
        ansque.pop();
        if(temnode->left !=NULL)
        {
            ansque.push(temnode->left);
        }
        if(temnode->right != NULL)
        {
            ansque.push(temnode->right);
        }
        ans.push_back(temnode->val);
    }
    return ans;
}
