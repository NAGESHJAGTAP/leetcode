/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) {
         return {-1, -1};
        }
        ListNode* prev = head;
        ListNode* curr=head->next;

        int first=-1;
        int idx=1;
        int last=-1;  
        int min=INT_MAX;     
     while (curr->next != NULL) {
        if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
              if(first == -1){
                first=idx;
                last=idx;
              }else{
                if(idx - last < min){
                    min=idx-last;
                }
                last=idx;
              }
              }
              prev=curr;
              curr=curr->next;
              idx++;
            }
          if(first == last){
            return{-1,-1};
          }
          return{min, last-first};
    }
};