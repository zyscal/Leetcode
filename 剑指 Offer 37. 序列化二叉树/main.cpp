#include<queue>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#define MAX_VAL 9999999
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      if(root == NULL)
      {
        return "[]";
      }
        queue<TreeNode *> ansqueue;
        ansqueue.push(root);
        string ans = "[";
        while (!ansqueue.empty())
        {
          TreeNode *tem = ansqueue.front();
          ansqueue.pop();
          if(tem != NULL)
          {
            ansqueue.push(tem->left);
            ansqueue.push(tem->right);
            ans += inttostr(tem->val);
          }
          else
          {
            ans += "null";
          }
          ans += ",";
          /* code */
        }
        int len = ans.length();
        ans[len - 1] = ']';
        cout<<ans<<endl;
        return ans;
    }
    string inttostr(int a)
    {
      string ans = "";
      bool zhengfu = true;
      if(a < 0)
      {
        zhengfu = false;
        a = -a;
      }
      while ( a/10 )
      {
        char ge = (a % 10) + '0';
        string gewei = "";
        gewei += ge;
        ans = ge + ans;
        a /= 10;
        /* code */
      }
        char ge = (a % 10) + '0';
        string gewei = "";
        gewei += ge;
        ans = ge + ans;
      if( !zhengfu )
      {
        return ("-" + ans);
      }
      return ans;
    }
    // Decodes your encoded data to tree.
    int left_or_right = 0;
    TreeNode* deserialize(string data) {
      TreeNode* root;
      if(data.length() == 2)
      {
        return NULL;
      }
      queue<TreeNode *> ansque;
      int temnum = 0;
      bool zhengfu = true;
      for(int i = 1; i < data.length(); i++)
      {
         if(data[i] >= '0' && data[i] <= '9')
         {
            temnum *= 10;
            temnum += data[i] - '0';
         }
         else if (data[i] == '-')
         {
           zhengfu = false;
         }
         else if(data[i] == ',' || data[i] == ']')
         {
           if(!zhengfu)
           {
             temnum = -temnum;
           }
            if(ansque.empty())
            {
                root = new TreeNode(temnum);
                ansque.push(root);
            }
            else
            {
              if( !left_or_right )
              {
                ansque.front()->left = new TreeNode(temnum);
                ansque.push(ansque.front()->left);
                left_or_right++;
              }
              else if(left_or_right)
              {
                ansque.front()->right = new TreeNode(temnum);
                ansque.push(ansque.front()->right);
                left_or_right--;
                ansque.pop();
              }
            }
            temnum = 0;
            zhengfu = true;
         }
         else if(data[i] == 'n')
         {
           if( !left_or_right )
           {
             ansque.front()->left == NULL;
             left_or_right++;
           }
           else if(left_or_right)
           {
             ansque.front()->right == NULL;
             ansque.pop();
             left_or_right--;
           }
           i += 4;
         }
      }
      return root;
      

    }
};
int main()
{
  Codec b;
  TreeNode *a = new TreeNode(-1);
  a->left = new TreeNode(0);
  a->right = new TreeNode(1);
  b.serialize(a);
  cout<<b.deserialize(b.serialize(a));
  return 0;
}