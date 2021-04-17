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
// 2개의 리스트를 Merge 할 땐 각각의 value 를 비교하면서 했는데
// k개의 리스트는 어떻게 Merge하지?
// 각각을 돌면서 작은 최솟값을 계속 찾아?
// 시간복잡도 생각해보면 몰라.. 근데 list 총 길이가 10^4 이하라매.. 그럼 된 거 아닐까?
// 근데 Hard 문젠데 이렇게 푸는 게 맞나? 일단 풀어봐..
// cur->val 과 같으면 넣어줌

// 다른 관점에서 생각하면?
// lists 를 순회하는 lis 마다 바로바로 merge 하는 거임 ㅋㅋ
// 그럼 한번만 순회하면서 merge 할 수 있음
// 오호라 ㄷㄷㄷㄷㄷㄷㄷㄷㄷㄷ
// 근데 더 좋은 방식은 하나씩 merge 하지 말고 두개씩 merge 하면서 size 를 절반으로 계속 줄이면 오히려 좋음;
// merge 를 덜하니까..
// merge Two 는 Recursion 을 사용했음 잘 이해는 안되긴 하네 ㅎㅎ;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int sz = lists.size();
        while(sz>1){
            for(int i=0; i<sz/2; i++){
                lists[i] = mergeTwo(lists[i], lists[sz-i-1]);
            }
            sz = (sz+1)/2;
        }
        return lists.front();
    }
    ListNode *mergeTwo(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        else if(!l2) return l1;
        if(l1->val <= l2->val){
            l1->next = mergeTwo(l1->next, l2);
            return l1;
        } else {
            l2 -> next = mergeTwo(l1, l2->next);
            return l2;
        }
    }
};