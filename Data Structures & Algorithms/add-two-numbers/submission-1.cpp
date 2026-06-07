class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1; // Keep track of the head of l1 to return
        ListNode* prev = nullptr; // Track the previous node to attach extra nodes if needed
        int carry = 0;
        
        // Phase 1: Traverse both lists together
        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            
            prev = l1;   // Keep track of the last processed node in l1
            l1 = l1->next;
            l2 = l2->next;
        }
        
        // Phase 2: If l2 was longer, attach the rest of l2 to l1
        if (l2 != nullptr) {
            prev->next = l2;
            l1 = l2; // Continue processing using l1 pointer
        }
        
        // Phase 3: Process the remaining nodes (either original l1 leftovers or attached l2 leftovers)
        while (l1 != nullptr && carry > 0) {
            int sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            
            prev = l1;
            l1 = l1->next;
        }
        
        // Phase 4: If there is still a carry left at the very end, create a new final node
        if (carry > 0) {
            prev->next = new ListNode(carry);
        }
        
        return res;
    }
};