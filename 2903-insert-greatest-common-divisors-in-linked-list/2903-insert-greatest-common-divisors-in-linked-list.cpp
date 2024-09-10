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
    int gcd(int a,int b){
        while(b!=0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr = head;
        ListNode* nex = head->next;

        while(nex!=NULL){
            int gcdcal = gcd(curr->val,nex->val);
            ListNode* gcdnew = new ListNode(gcdcal);

            curr->next = gcdnew;
            gcdnew->next = nex;

            curr = nex;
            nex=nex->next;
        }
        return head;
    }
};