#include<iostream>
#include<vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
        {
            return NULL;
        }
        vector<Node*> ListofNode;
        LDR(ListofNode, root);
        for(int i = 0; i < ListofNode.size(); i++)
        {
            if(i != ListofNode.size() - 1)
            {
                ListofNode[i]->right = ListofNode[i + 1];
                if(i != 0)
                {
                    ListofNode[i]->left = ListofNode[i - 1];
                }
                else
                {
                    ListofNode[i]->left = ListofNode[ListofNode.size() - 1];
                }
            }else
            {
                ListofNode[i]->right = ListofNode[0];
                if(i != 0)
                {
                    ListofNode[i]->left = ListofNode[i - 1];
                }
                else
                {
                    ListofNode[i]->left = ListofNode[ListofNode.size() - 1];
                }
            }
            
        }
        return ListofNode[0];
    }
    void LDR(vector<Node*> &ListofNode, Node* root)
    {
        if(root->left != NULL)
        {
            LDR(ListofNode, root->left);
        }
        ListofNode.push_back(root);
        if(root->right != NULL)
        {
            LDR(ListofNode, root->right);
        }
    }
};