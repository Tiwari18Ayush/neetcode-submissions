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
    vector<ListNode*> nxt;
    vector<ListNode*> prev;

    int getlength(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void reverse(int i, int k) {
        ListNode* p = prev[i];
        ListNode* c = nxt[i];
        int cnt = 1;
        while (cnt <= k) {
            ListNode* t = c->next;
            c->next = p;
            p = c;
            c = t;
            cnt++;
        }
        
        if (prev[i] != nullptr) {
            prev[i]->next = p;
        }
        prev[i + 1] = nxt[i];
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getlength(head);
        int v = len / k;
        nxt.resize(v + 1);
        prev.resize(v + 1);
        prev[0] = nullptr;
        nxt[0] = head;
        ListNode* temp = head;
        ListNode* ans = head;

        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= k && temp; j++) {
                if (i == 1 && j == k) ans = temp;
                temp = temp->next;
            }
            nxt[i] = temp;
        }
        nxt[v] = temp;

        for (int i = 0; i < v; i++) {
            ListNode* p = nxt[i];
            reverse(i, k);
            p->next = nxt[i + 1];
        }
        return ans;
    }
};