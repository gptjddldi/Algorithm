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
// next 는 deepcopy 할 수 있어, 근데 random 은?
// 일단 iterator 한번 돌면서 next 들을 만들고 그 뒤에 랜덤을 한다면?
// 근데 인덱스로 접근할 수 있는 게 아닌데, 이부분을 벡터에 저장해서.. 하면 시간이 오래걸리지 않을까시라.. 해봤자 N^2 인가?
// 시간복잡도 O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* ret = new Node(head->val);
        auto pos = ret;
        auto tmp = head;
        while(tmp->next){
            pos->val = tmp->val;
            Node* cur = new Node(tmp->next->val);
            tmp = tmp->next;
            pos->next = cur;
            pos = pos->next;
        }
        tmp = head;
        pos = ret;
        while(tmp){
            // Node* cur = new Node(tmp->val);
            auto n1 = head, n2 = ret;
            while(tmp->random != n1){
                n1 = n1->next;
                n2 = n2->next;
            }
            // cur->random = n2;
            pos->random = n2;
            pos = pos->next;
            tmp = tmp->next;
        }
        return ret;
    }
};



// original 노드와 copy 노드의 결합, 이후 분해 시간복잡도 O(N)
// 조금 복잡할 수 있네..
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* tmp = new Node(head->val);
        Node* n1 = head;
        while(n1){
            Node* n = new Node(n1->val);
            n->next = n1->next;
            n1->next = n;
            n1 = n1->next->next;
        }
        n1 = head;
        while(n1){
            // Node* n = n1->next;
            if(n1->random)
                n1->next->random = n1->random->next;
            n1 = n1->next->next;
        }
        Node* ret = head->next;
        n1 = head;
        auto pos = ret;
        while(pos->next){
            n1->next = n1->next->next;
            n1 = n1->next;
            
            pos->next = pos->next->next;
            pos = pos->next;
        }
        n1->next = n1->next->next;
        return ret;
    }
};