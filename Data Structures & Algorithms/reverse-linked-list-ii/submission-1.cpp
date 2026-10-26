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
    void reverse(ListNode* one){
        ListNode* temp=one;
        ListNode* p=nullptr;
        while(temp){
            ListNode* nxt=temp->next;
            temp->next=p;
            p=temp;
            temp=nxt;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
     ListNode* temp1=head;
     ListNode*temp2=head;
     ListNode* dummy=new ListNode(-1);
     dummy->next=head;
     ListNode*prev=dummy;
     for(int i=1;i<left;i++){
        prev=temp1;
        temp1=temp1->next;
     }
     for(int i=1;i<right;i++){
        temp2=temp2->next;
     }
     ListNode* last=(temp2->next!=nullptr)?temp2->next:nullptr;
     temp2->next=nullptr;
     prev->next=nullptr;
     reverse(temp1);
     prev->next=temp2;
     temp1->next=last;
    return dummy->next;
    }
};