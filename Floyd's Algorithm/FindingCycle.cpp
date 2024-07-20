/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* hare = head; 
        ListNode* tort = head; 
        if(!head) return head; 
        while(true){
            hare = hare->next; 
            tort = tort->next; 
            if(hare == NULL || hare->next == NULL){
                return NULL;
            }
            hare = hare->next; 
            if(hare == tort) break;

        }

        ListNode* p1 = hare; 
        ListNode* p2 = head; 
        while(p1 != p2){
            p1= p1->next; 
            p2 = p2->next; 
        }
        return p1; 
    }
};
