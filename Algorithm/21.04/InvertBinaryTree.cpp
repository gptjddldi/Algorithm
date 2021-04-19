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
// 딱 보니 재귀로 풀면 될듯
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        // if(!root->left && !root->right) return root;
        if(root->left) root -> left = invertTree(root->left);
        if(root->right) root -> right = invertTree(root->right);

        TreeNode* tmp = new TreeNode();
        
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        return root;
    }
     // bfs 풀이
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
                auto cur = q.front(); q.pop();
                TreeNode* tmp = new TreeNode();
                tmp = cur->left;
                cur->left = cur->right;
                cur->right = tmp;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            
        }
        return root;
    }
};