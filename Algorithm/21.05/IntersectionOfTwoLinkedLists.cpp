/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// a->val == b->val 일 때까지 전진.. 
// 아니 맨 끝에서 시작하면 ? 뒤로 돌아갈 수 없으니까..
// 만약 끝에서 시작한다고 하면.. 더이상 같지 않을 때, 직전 노드를 반환하면 됨
// 그럼 앞에서 시작하면.. a 를 먼저 가? b 를 먼저 가?
// a 의 길이가 5, b 길이 6 이면.. b 를 먼저 한 칸 가고 동시에 가야 하지 않을까?
// intersection 이면 만난 순간부터 마지막까지는 길이가 같다는 의미니까
// 아 딱알았다.. a->val b->val 이게 기준이 아니고 걍 노드 그 자체가 같아야 intersection 인것임 ㅋㅋ
// 그리고 걍 노드가 같은 그 순간만 찾으면 뒤에는 신경 안써도 됨.. 그것이 동일한 노드니까!
// 그럼 어떻게 진행할 건데.. 누가 먼저 이동해; 이걸 O(N) 으로 해야함
// 먼저 한바퀴씩 돌면서 길이 측정 O(2N) 길이를 맞춘 뒤 각각 한칸씩 이동, O(N)
// => O(3N) ㅇㅋ 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ret;
        ListNode *a = headA, *b = headB;
        int n = 1, m = 1;
        while(a->next){
            a = a->next;
            n++;
        }
        while(b->next){
            b = b->next;
            m++;
        }
        a = headA, b = headB;
        if(n>m){
            n = n-m;
            while(n--)
                a = a->next;
        }
        else if(m>n){
            m = m-n;
            while(m--) b = b->next;
        }
        if(a==b) return a;
        
        while(a->next && b->next){
            a = a->next;
            b = b->next;
            if(a==b) return a;

        }
            // cout<<n<<m;
        return ret;
    }
};