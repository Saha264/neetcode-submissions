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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();

        if(n<=1)
        {
            return nullptr;
        }

        for(int i=1;i<n;i++)
        {
            ListNode*l1= lists[i-1];
            ListNode*l2= lists[i];
            ListNode*temp;

            if(l1==nullptr)
            {
                continue;
            }
            if(l2==nullptr)
            {
                l2=l1;
                continue;
            }

            if(l1->val < l2->val)
            {
                temp=l1;
            
                l1=l1->next;
            }
            else if(l1->val >= l2->val){
                temp=l2;
                
                l2=l2->next;
            }
            ListNode*h=temp;

            while(l1!=nullptr || l2!=nullptr)
            {
                if(l2==nullptr || (l1!=nullptr && l1->val < l2->val))
                {
                    temp->next=l1;
                    l1=l1->next;
                }
                else{
                    temp->next=l2;
                    l2=l2->next;

                }
                temp=temp->next;

            }
            lists[i]=h;

        }
        return lists[n-1];
        
        
    }
};
