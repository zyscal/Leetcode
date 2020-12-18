#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* getKthFromEnd(ListNode* head, int k) {
    vector<ListNode*> allnode;
    ListNode* p = head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        allnode.push_back(p);
        p = p->next;
    }
    return allnode[count - k];
    
}