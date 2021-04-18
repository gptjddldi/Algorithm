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
// recursion 으로 풀면 어때 int rec(TreeNode* cur) 
class Solution {
private:
    int recursion(TreeNode* cur, int val){
        if(!cur) return val;
        return max(recursion(cur->left,val+1), recursion(cur->right,val+1));
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ret;
        ret = max(recursion(root->left,1), recursion(root->right,1));
        
        return ret;
        
    }
    // bfs 로 푼다면 이런 식으로 각 depth 를 한번에 순회함
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int ret = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            ret++;
            int n = q.size();
            for(int i=0; i<n; i++){
                auto *cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }

        }
        return ret;
    }
};