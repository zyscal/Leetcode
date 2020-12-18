#include<vector>
#include<iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
        {
           return NULL;
        }
        TreeNode *temroot = new TreeNode(preorder[0]);
        // cout<<"the root is:"<<temroot->val<<endl;
        // for(int i = 0; i < preorder.size(); i++)
        // {
        //     cout<<preorder[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i < inorder.size(); i++)
        // {
        //     cout<<inorder[i]<<" ";
        // }
        // cout<<endl;

        int posinorder = 0;
        for(int i = 0; i < inorder.size(); i++)//找到中序遍历中根节点位置，因为中序遍历中根节点左边东西为左子树，右边为右子树
        {
            if(inorder[i] == preorder[0])
            {
                posinorder = i;
                break;
            }
        }
        // cout<<"root :"<<temroot->val<<" posinorder:"<<posinorder<<endl;
        if(posinorder != 0)//说明有左子树，要不然左子树默认为NULL
        {
            vector<int> leftinorder(inorder.begin(), inorder.begin() + posinorder );
            vector<int> leftpreorder(preorder.begin() + 1,preorder.begin() + 1 + posinorder);
            temroot->left = buildTree(leftpreorder,leftinorder);
        }
        if(posinorder != inorder.size() - 1)//说明有右子树
        {
            vector<int> rightinorder(inorder.begin() + posinorder + 1, inorder.end());
            vector<int> rightpreorder(preorder.end() - (inorder.size() - posinorder - 1), preorder.end());
            temroot->right = buildTree(rightpreorder, rightinorder);
        }
        return temroot;
        
    }
    int main()
    {
        vector<int> preorder = {1,2,3};
        vector<int> inorder = {3,2,1};
        TreeNode *head = buildTree(preorder,inorder);
        return 0;
    }