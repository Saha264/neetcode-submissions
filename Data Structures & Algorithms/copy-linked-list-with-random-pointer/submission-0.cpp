/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> copy;

        Node*start=head;
        

        while(start!=nullptr)
        {
            copy[start] = new Node(start->val);
            start=start->next;
            
        }
        start=head;
        Node*c= copy[start];
        Node*result=c;
        while(start!=nullptr)
        {
            c= copy[start];
            c->random=copy[start->random];
            c->next=copy[start->next];

            start=start->next;


            
        }
        return result;




        
    }
};
