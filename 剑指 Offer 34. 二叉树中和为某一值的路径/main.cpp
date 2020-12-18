#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void BFS(vector<vector<int>> *ans, queue<int> path, TreeNode *root, int sum, int temsum)
{
    if(root == NULL)
    {
        return;
    }
    else if(root-> val + temsum == sum && root->left == NULL && root->right == NULL)
    {
        path.push(root->val);
        queue<int> rightpath(path);
        vector<int> newpath;
        while(!rightpath.empty())
        {
            newpath.push_back(rightpath.front());
            rightpath.pop();
        }
        ans->push_back(newpath);
    }
    else
    {
        path.push(root->val);
        temsum += root->val;
        BFS(ans, path, root->left, sum, temsum);
        BFS(ans, path, root->right, sum, temsum);
    }
}
vector<vector<int>> pathSum(TreeNode* root, int sum)
{
    vector<vector<int>> ans;
    queue<int> path;
    int temsum = 0;
    BFS( &ans, path, root, sum, temsum);
    return ans;
}

int main()
{
    TreeNode *a = new TreeNode(-2);
    a->right = new TreeNode(-3);
    vector<vector<int>> ans = pathSum(a,-5);
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j] << " ";
        }
        cout<<endl;
    }
}

