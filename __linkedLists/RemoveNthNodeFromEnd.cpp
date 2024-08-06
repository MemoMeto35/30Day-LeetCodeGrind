// My solution
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = head; 
        ListNode* res = head; 
        
        int count = 1;
        while(head->next){
            count++;
            if(head->next->next==NULL) break;
            head = head->next; 
        }
        if(count==1) return NULL;  
        if(n==1) {
            head->next = NULL; 
            return res; 
        }
        if(n==count) return res->next;
        while(dummyHead){
            count--; 
            if(count ==n){
                dummyHead->next= dummyHead->next->next;
                break; 
            }
            dummyHead = dummyHead->next; 

        }
        return res; 
        


    }
};

// optimized Solution: using two pointers; 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(0, head);
        ListNode* dummy = res;

        for (int i = 0; i < n; i++) {
            head = head->next;
        }

        while (head != nullptr) {
            head = head->next;
            dummy = dummy->next;
        }

        dummy->next = dummy->next->next;

        return res->next;        
    }
};
