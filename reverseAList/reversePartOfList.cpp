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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int currentPos = 1; 
        ListNode* start = head; 
        ListNode* currentNode = head; 
        while(currentPos < left){
            start = currentNode; 
            currentNode = currentNode->next; 
            currentPos++;
        }
        ListNode* newList = NULL;
        ListNode* tail = currentNode; 
        while(currentPos<=right){
            ListNode* next = currentNode->next; 
            currentNode->next = newList; 
            newList = currentNode; 
            currentNode = next; 
            currentPos++;
        }

        start->next = newList; 
        tail->next = currentNode; 
        if(left>1) return head; 
        else return newList; 


    }
};
