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
// Merge Sort 그대로 쓰면 됨 ㄹㅇㅋㅋ
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur = new ListNode();
        ListNode* s = cur;
        while(l1 || l2){
            if(!l1){
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
            else if(!l2){
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else {
                if(l1->val > l2->val){
                    cur->next = l2;
                    l2 = l2->next;
                }
                else{
                    cur->next = l1;
                    l1 = l1->next;
                }
                cur = cur->next;
            }
        }
        return s->next;
    }
};