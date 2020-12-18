#include<iostream>
#include<vector>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
     vector<int> reversePrint(ListNode* head) {
        ListNode *tem = head;
        vector <int> ans = {};
        while (tem != NULL)
        {
            /* code */
            ans.insert(ans.begin(),tem->val);
            tem = tem->next;
        }
        return ans;
    }