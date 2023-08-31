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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *curr = head;
        ListNode *nxt = head;

        while(nxt){
            curr= nxt;
            ListNode *pt1 = dummy->next;
            ListNode *pre = dummy;
            while(pt1 !=nxt){
                pt1 = pt1->next;
                pre = pre->next;
            }
            pre ->next = pre->next->next;
            nxt = nxt ->next;

//             now insert at correct position on left side
            ListNode* pt2 = dummy->next;
            ListNode* pre2= dummy;

            // cout<<i<<endl;
            while(pt2!= nxt and (curr->val)>= (pt2->val)){
                // cout<<pt2->val<<" ";
                pt2=pt2->next;
                pre2=pre2->next;
            }
            // cout<<endl;
            curr->next = pt2;
            pre2->next = curr;
            
            // cout<<pre2->val<<" "<<curr->val<<" "<<pt2->next->val<<endl;
        }
        
        return dummy->next;
    }
    
};