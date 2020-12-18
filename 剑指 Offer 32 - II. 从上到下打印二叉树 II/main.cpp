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
typedef pair<TreeNode *, int> pairtype;
vector<vector<int>> levelOrder(TreeNode* root) {

    queue<pairtype> ansque;
    vector< vector<int>> ans;
    if(root == NULL)
    {
        return ans;
    }
    int height = 0;
    vector<int> tem;
    ans.push_back(tem);
    ansque.push(pairtype(root, 0));
    while (!ansque.empty())
    {
        pairtype tem = ansque.front();
        ansque.pop();
        ans[tem.second].push_back(tem.first->val);
        if(tem.first->left != NULL)
        {
            if(tem.second + 1 > height)
            {
                vector<int> tem;
                ans.push_back(tem);
                height ++;
            }
            ansque.push(pairtype(tem.first->left, tem.second + 1));
        }
        if(tem.first->right != NULL)
        {
            if(tem.second + 1 > height)
            {
                vector<int> tem;
                ans.push_back(tem);
                height++;
            }
            ansque.push(pairtype(tem.first->right, tem.second + 1));
        }
    }
    return ans;
}

