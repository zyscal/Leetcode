#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
ListNode* reverseList(ListNode* head) {
    ListNode *tem = NULL;
    while (head != NULL)
    {
        /* code */
        ListNode *afterhead = head -> next;
        head->next = tem;
        tem = head;
        head = afterhead;
    }
    return tem;
    
}