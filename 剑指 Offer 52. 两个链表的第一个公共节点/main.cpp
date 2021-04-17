#include<iostream>
#include<vector>
using namespace std;




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode *> A;
        vector<ListNode *> B;
        ListNode *temA = headA;
        ListNode *temB = headB;
        while(temA != NULL)
        {
            A.push_back(temA);
            temA = temA->next;
        }
        while (temB != NULL)
        {
            B.push_back(temB);
            temB = temB->next;
        }
        int count = 0;
        int posA = A.size() - 1;
        int posB = B.size() - 1;
        while (posA != -1 && posB != -1 && A[posA] == B[posB])
        {
            posA--;
            posB--;
            count++;
        }
        if(count == 0)
        {
            return NULL;
        }
        return A[A.size() - count];
    }
};