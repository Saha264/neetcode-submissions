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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*head1=list1;
        ListNode*head2=list2;
        ListNode*temp;
        ListNode*h;


        if(head1==nullptr)
        {
            return head2;
        }
        if(head2==nullptr)
        {
            return head1;
        }

        if(head1->val < head2->val)
        {
            temp=head1;
           
            head1=head1->next;
        }
        else if(head1->val >= head2->val){
            temp=head2;
            
            head2=head2->next;
        }
        h=temp;

        while(head1!=nullptr && head2!=nullptr)
        {
            cout<<"head1  "<<head1->val<<'\n';
            cout<<"head2  "<<head2->val<<'\n';

            if(head1->val < head2->val)
            {
                temp->next=head1;
                temp=temp->next;
                head1=head1->next;
            }
            else{
                temp->next=head2;
                temp=temp->next;
                head2=head2->next;
            }
        
        }

        if(head1==nullptr)
            {
                cout<<"hi";
                while(head2!=nullptr)
                {
                    cout<<"hi";
                    temp->next=head2;
                    temp=temp->next;
                    head2=head2->next;
                }
            }
        else if(head2==nullptr)
        {
            cout<<"hey";
            while(head1!=nullptr)
            {
                temp->next=head1;
                temp=temp->next;
                head1=head1->next;
            }
        }

        return h;

    }
};
