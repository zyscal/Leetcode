#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> findp;
        vector<TreeNode*> findq;
        find(findp, root, p);
        find(findq, root, q);
        int i = 0;
        while (true)
        {
            if(i < findp.size() && i < findq.size() && findp[i] == findq[i])
            {
                i++;
            }
            else
            {
                return findp[i - 1];
            }
            /* code */
        }
        return NULL;
        
        
    }
    void find(vector<TreeNode*> &path, TreeNode* root, TreeNode* node)
    {
        TreeNode* tem = root;
        while(tem->val != node->val)
        {
            path.push_back(tem);
            if(node->val > tem->val)
            {
                tem = tem->right;
            }
            else
            {
                tem = tem->left;
            }
        }
        path.push_back(tem);
        return ;
    }
};