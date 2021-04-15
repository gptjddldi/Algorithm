/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 이거 사이클 찾는 알고리즘 이름이 머였더라.. 하여튼 기억하고 있다는 것 ^^
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *low = head, *fast = head;
        // low = low->next->next->next->next;
        // cout<<low->val;
        if(!head) return false;
        while(fast->next&& fast->next->next){
            low = low -> next;
            fast = fast -> next -> next;
            if(low==fast) return true;
        }
        return false;
        // cout<<head->next->val;
        // return true;
    }
};