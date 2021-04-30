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
// iterater, queue, 마지막 값
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                root = q.front(); q.pop();
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);                
            }
            ret.push_back(root->val);
        }
        return ret;
    }
};

class Solution {
public:
    // preorder 에서 루트 -> 오른쪽 -> 왼쪽 탐색하도록 한 코드..
    // if(res.size()<depth) 이걸 어떻게 생각해 ㅅㅂ;
    void recursion(int depth, vector<int>& res, TreeNode* root){
        if(!root) return;
        if(res.size()<depth) res.push_back(root->val);
        recursion(depth+1, res, root->right);
        recursion(depth+1, res, root->left);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        recursion(1, ret, root);
        return ret;
    }
};