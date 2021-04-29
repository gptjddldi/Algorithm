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
// inorder : 중위순회 with recursion
class Solution {
vector<int> ve;

public:
    void help(TreeNode* root){
        if(!root) return;
        if(root->left) help(root->left);
        ve.push_back(root->val);
        if(root->right) help(root->right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        help(root);
        return ve;
    }
};

// inorder : 중위순회 with iteration

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ve;
        stack<TreeNode*> st;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            
            ve.push_back(root->val);
            root = root->right;
        }
        return ve;
    }

    // Time: O(n), Space: O(1) 인 Morris 라는 것도 있는 듯 함.