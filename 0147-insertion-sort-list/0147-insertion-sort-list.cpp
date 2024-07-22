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
        ListNode* temp=head;
        if(head->next==NULL)
            return head;
        vector<int> arr;
        while(temp)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        ListNode dummy;
        ListNode* cur=&dummy;
        for(auto it:arr)
        {
            ListNode* newnode=new ListNode(it);
            cur->next=newnode;
            cur=cur->next;
        }
        return dummy.next;
    }
};