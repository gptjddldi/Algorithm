/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// dfs recursion 이용
// bfs 는 queue 이용, 왼쪽(오른쪽) 자식을 넣은 뒤 하나만 들갔으면 false
// val 값이 다르면 false
class Solution {

public:
    // dfs(recursion)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val!=q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    // dfs
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<TreeNode*> q1;
        q1.push(p); q1.push(q);
        while(!q1.empty()){
            auto t1 = q1.front(); q1.pop();
            auto t2 = q1.front(); q1.pop();
            if(t1->val != t2->val) return false;
            if(t1->left) q1.push(t1->left);
            if(t2->left) q1.push(t2->left);
            if(q1.size() % 2 != 0) return false;
            if(t1->right) q1.push(t1->right);
            if(t2->right) q1.push(t2->right);
            if(q1.size() % 2 != 0) return false;

            // if(t1->left != t2->left || t1->right != t2->right) return false;
        }
        return true;
    }
};