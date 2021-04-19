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
// 걍 쌩 bfs 느낌
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> ve;
            for(int i=0; i<n; i++){
                TreeNode* cur = q.front(); q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                ve.push_back(cur->val);
            }
            ret.push_back(ve);
        }
        return ret;
    }
};


// 근데 다른 방식 (preorder) 로 풀 수도 있구나
// preorder : root -> left -> right
class Solution {
vector<vector<int>> ret;
    private:
    void preorder(TreeNode* cur, int depth){
        if(!cur) return;
        if(ret.size() == depth) ret.push_back(vector<int>());
        ret[depth].push_back(cur->val);
        
        preorder(cur->left, depth+1);
        preorder(cur->right, depth+1);

    }
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        preorder(root, 0);
        return ret;
    }
