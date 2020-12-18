#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    typedef pair<Node *, Node *> nodetype;
    Node* copyRandomList(Node* head) {
        if(head == NULL)
        {
            return NULL;
        }
        unordered_map<Node *,Node *> Listofmap;
        vector<Node *> vectoroflist;
        Node *temp = head;
        while (temp != NULL)
        {
            nodetype tempair;
            Node *copy = new Node(temp->val);
            vectoroflist.push_back(copy);
            tempair.first = temp;
            tempair.second = copy;

            Listofmap.insert(tempair);
            temp = temp->next;
            /* code */
        }
        temp = head;
        int i = 0;
        while (temp != NULL)
        {
            if(i + 1 < vectoroflist.size())
            {
                vectoroflist[i]->next = vectoroflist[i + 1];
            }
            auto iter = Listofmap.find(temp->random);
            if(iter != Listofmap.end())
            {
                Node *findrandom = iter->second;
                vectoroflist[i]->random = findrandom;
            }
            i++;
            temp = temp->next;
            /* code */
        }
        return vectoroflist[0];
    }
};