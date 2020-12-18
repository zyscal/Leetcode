#include<iostream>
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
      ListNode* deleteNode(ListNode* head, int val) {
          ListNode *p = head;
          if(p->val == val)
          {
              return p->next;
          }
          while(p->next != NULL)
          {
              if (p->next ->val == val)
              {
                  p->next = p->next->next;
                  return head;
              }
              p = p->next;
          }
          return head;
    }