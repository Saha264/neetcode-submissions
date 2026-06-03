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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* forward = dummy;
        ListNode* start = dummy;
        for(int i=0;i<n;i++)
        {
            forward=forward->next;
        }
        while(forward!=nullptr  && forward->next!=nullptr)
        {
            forward=forward->next;
            start=start->next;
        }
        ListNode*temp=start->next;

        start->next=temp->next;


        
     
        
        return dummy->next;
    }
};
