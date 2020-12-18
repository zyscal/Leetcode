#include<iostream>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
  bool same(TreeNode* A, TreeNode* B)
  {
      if(A == NULL && B == NULL)
      {
          return true;
      }
      else if(A != NULL && B!= NULL && A->val == B->val)
      {
         return true;
      }
      return false;
  }
  bool checktree(TreeNode* A, TreeNode* B)
  {
      if( B == NULL)
      {
          return true;
      }
      if(same(A, B) && checktree(A->left, B->left) && checktree(A->right, B->right))
      {
          return true;
      }
      return false;
  }
bool BFS(TreeNode* A, TreeNode* B)
{
    if((same(A, B) && checktree(A, B)) || (A != NULL && BFS(A->left, B)) || (A != NULL && BFS(A->right, B) ))
    {
        return true;
    }
    return false;
}
bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(B == NULL)
      {
          return false;
      }
    return BFS(A, B);
}
int main()
{
    TreeNode *a = new TreeNode(4);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);
    TreeNode *b = new TreeNode(4);
    cout<<isSubStructure(a, b);
}

