#include<iostream>
#include<vector>
#include<queue>
#include <stack>
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
    stack<int> ansstack;
    vector< vector<int>> ans;
    if(root == NULL)
    {
        return ans;
    }
    int height = 0;
    int nowhang = 0;
    vector<int> tem;
    ans.push_back(tem);
    ansque.push(pairtype(root, 0));
    while (!ansque.empty())
    {
        pairtype tem = ansque.front();
        ansque.pop();
        if(tem.second % 2 == 0)
        {
            ans[tem.second].push_back(tem.first->val);
        }
        else
        {
            ansstack.push(tem.first->val);
        }
        if(tem.second > nowhang)
        {
            if(tem.second % 2 == 0)
            {
                while (!ansstack.empty())
                {
                    ans[nowhang].push_back(ansstack.top());
                    ansstack.pop();
                    /* code */
                }
                
            }
            nowhang++;
        }
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
    if(nowhang % 2 == 1)
    {
        while (!ansstack.empty())
        {
            ans[nowhang].push_back(ansstack.top());
            ansstack.pop();
            /* code */
        }
        
    }
    return ans;
}

int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    a->left = b;
    vector< vector<int>> ans = levelOrder(a);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}