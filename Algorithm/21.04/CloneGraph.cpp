/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// 원래 내가 하던 방식은 ?
// vector<int> graph[300];
// 이런 식으로 그래프를 선언했었지.
// 이걸 Node 와 비교해보면.. 모르겠음
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* copy = new Node(node->val, {});
        mp[node] = copy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front(); q.pop();
            for(Node* nxt : cur->neighbors){
                if(mp.find(nxt) == mp.end()){
                    mp[nxt] = new Node(nxt -> val, {});
                    q.push(nxt);
                }
                mp[cur] -> neighbors.push_back(mp[nxt]);
            }
        }
        return copy;
    }
private:
    unordered_map<Node*, Node*> mp;
};