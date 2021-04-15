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
        ListNode* cur = NULL;
        while(head){
            ListNode* nxt = head -> next;
            head -> next = cur;
            cur = head;
            head = nxt;
        }
        return cur;
    }
};

//recursion
ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        auto res = reverseList(head->next);
        head->next->next = head; // head 다음의 다음은 head 가 와야 reverse 된것임
        head->next = NULL; // 이부분 왜 NULL 인데?
        return res;
    }