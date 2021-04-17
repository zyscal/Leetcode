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
            vector<TreeNode*> pathp;
            vector<TreeNode*> pathq;
            find(pathp, p, root);
            find(pathq, q, root);
            int i = 0;
            while (true)
            {
                if(i < pathq.size() && i < pathp.size() && pathp[i] == pathq[i])
                {
                    i++;
                }
                else{
                    return pathq[i - 1];
                }
                /* code */
            }
            return NULL;
        }
        bool find(vector<TreeNode* > &path, TreeNode* p, TreeNode* root)
        {
            if(root == NULL)
            {
                return false;
            }
            if(root == p)
            {
                path.push_back(root);
                return true;
            }
            path.push_back(root);
            if(find(path, p, root->left) || find(path, p, root->right))
            {
                return true;
            }
            path.erase(path.end());
            return false;
        }
    };
