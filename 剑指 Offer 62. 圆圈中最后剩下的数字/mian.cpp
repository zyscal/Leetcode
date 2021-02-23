#include<iostream>

using namespace std;


    
class Solution {
public:
    struct nodes
    {
        int val;
        nodes* next;
        nodes* before;
        nodes(int i) : val(i), next(NULL) ,before(NULL){}
        /* data */
    };
    int lastRemaining(int n, int m) {
        nodes *head = new nodes(0);
        create_nodes_list(head, n);
        head = head->before
        while (!check_one(head))
        {
            for(int i = 0; i < m; i++)
            {
                head = head->next;
            }
            delete_one(head);
        }
        return head->val;
        
    }
    void delete_one(nodes* head)
    {
        head->next->before = head->before;
        head->before->next = head->next;
        head = head->next;
    }

    bool check_one(nodes* head)
    {
        if(head->next == head)
        {
            return true;
        }
        return false;
    }

    void create_nodes_list(nodes* head, int n)
    {
        nodes *p = head;
        for(int i = 1; i < n; i++)
        {
            nodes* node = new nodes(i);
            p->next = node;
            p->next->before = p;
            p = p->next;
        }      
        p->next = head;
        head->before = p;
    }
};
