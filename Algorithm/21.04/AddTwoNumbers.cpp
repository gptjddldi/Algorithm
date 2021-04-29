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
// 더해서 인트값으로 리턴, 각각을 인접리스트로 변환?
// 근데 노드가 아주 길고 길어
// 그래서 int double 이런걸로 연산할 수 없음
// 그래서 string 덧셈을 해야함..!
// 공간 복잡도 최적화를 어떻게 더 해야할 지 모르겠음 ㅜㅜ
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp = new ListNode();
        ListNode* ret = tmp;
        int sum = 0;
        while(l1 || l2 || sum){
            int v1=0, v2=0;
            if(l1) sum += l1->val, l1 = l1->next;
            if(l2) sum += l2->val, l2 = l2->next;

            tmp -> next = new ListNode(sum%10);
            tmp = tmp->next;
            sum /= 10;
        }

        return ret->next;
    }
};