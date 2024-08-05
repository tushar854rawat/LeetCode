/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    if(head==NULL){
        return NULL;
    }
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast->next!=NULL){
        head=slow->next;
        return head;
    }
    else{
        head=slow;
        return head;
    }
}