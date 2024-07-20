/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL) return head; 
        Node* currentNode = head;
        while(currentNode != NULL){
            if(currentNode->child == NULL){
            currentNode = currentNode->next;}
            else{
                Node* tail = currentNode->child; 
                while(tail->next!=NULL){
                    tail = tail->next; 
                }
                tail->next = currentNode->next;
                if(currentNode->next != NULL){
                    tail->next->prev = tail;
                }
                currentNode->next = currentNode->child; 
                currentNode->next->prev = currentNode;
                currentNode->child = NULL; 
            }
        }
        return head; 
    }
};
