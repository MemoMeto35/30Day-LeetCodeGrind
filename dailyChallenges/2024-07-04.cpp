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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* currentNode = head; 
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead; 
        int sum = 0;
        while(currentNode != NULL){
            currentNode = currentNode -> next; 
            
            if(currentNode!=NULL){sum += currentNode->val; 
            if(currentNode->val == 0){
                tail->val = sum; 
                sum = 0;
                if(currentNode->next!=NULL){
                tail->next = new ListNode(0);
                tail = tail->next;}
            }}
        }
        return dummyHead; 
    }
};
