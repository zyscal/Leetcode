#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if (l1 == NULL)
         {
             return l2;
             /* code */
         }
         if(l2 == NULL)
         {
             return l1;
         }
         if(l2->val < l1->val)
         {
             swap(l1,l2);
         }
         ListNode  *teml1 = l1;
         
         while(l2 != NULL)
         {
             int getval = l2 -> val;
             while( teml1->next != NULL && teml1->next->val <= getval)
             {
                 teml1 = teml1 -> next;
             }
             ListNode *teml2 = l2;
             l2 = l2->next;
             teml2->next = teml1->next;
             teml1->next = teml2;
         }
         return l1;
    }
int main()
{

}