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
    void reorderList(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;

        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* h2 = slow->next; 
        slow->next = nullptr; // CRITICAL: Cut the link to separate the two halves!

        ListNode* prev = nullptr;
        ListNode* curr = h2;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        h2 = prev; // h2 now points to the head of the reversed second half

        // Step 3: Merge the two halves (h1 and h2) alternately
        ListNode* h1 = head;
        while (h2 != nullptr) {
            ListNode* next1 = h1->next;
            ListNode* next2 = h2->next;

            h1->next = h2; // Link h1 to h2
            h2->next = next1; // Link h2 to the original next of h1

            // Move pointers forward
            h1 = next1;
            h2 = next2;
        }

    }
};
