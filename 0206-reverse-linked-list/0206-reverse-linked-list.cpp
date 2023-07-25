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
    ListNode* reverseList(ListNode* head) {
        ListNode* left = NULL;
        ListNode* pointer = head;
        ListNode* right;
        while(pointer != NULL){
            right = pointer->next;
            pointer->next = left;
            left = pointer;
            pointer = right;
        }
        return left;
    }
};