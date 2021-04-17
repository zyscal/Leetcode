#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
            /* code */
        }
        ListNode* tail = head;
        while (tail -> next != nullptr)
        {
            tail = tail->next;
            /* code */
        }
        ListNode* next_head = head->next;
        while (head != tail)
        {
            move_to_back(head, tail);
            head = next_head;
            next_head = next_head->next;
            /* code */
        }
        return tail;
        
        
    }
    void move_to_back(ListNode* head, ListNode* tail)
    {
        head->next = tail->next;
        tail->next = head;
    }
};