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
        if(head == nullptr) return nullptr;
        Node* temp=head;
        while(temp){
            Node* curr=temp;
            Node* d=new Node(curr->val);
            d->next=curr->next;
            curr->next=d;
            temp=d->next;
        }
        Node* ans=head->next;
        // assign random pointers
        Node* t1=head;
        Node* t2=head->next;
        while(t1 && t2){
            t2->random=(t1->random!=nullptr)?t1->random->next:nullptr;
            t1=t2->next;
            t2=(t1!=nullptr)?t1->next:nullptr;
        }
        //detach
        t1=head;
        t2=head->next;
        while(t1 && t2){
            Node *c=t2->next;
            Node* d=(c)?c->next:nullptr;
            t1->next=c;
            t2->next=d;
            t1=c;
            t2=d;
        }
        return ans;
    }
};
