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
        ListNode*curr=nullptr;
        ListNode*prev=nullptr;
        ListNode* forward=nullptr;

        if(head==nullptr)
        {
            return nullptr;
        }
        else if(head->next == nullptr){
            
            return head;
        }
        curr=head;
        forward=head->next;
        




        while(forward != nullptr)
        {
            curr->next=prev;
            prev=curr;
            curr=forward;
            forward=curr->next;




        }
        curr->next=prev;

        return curr;

    }
};
