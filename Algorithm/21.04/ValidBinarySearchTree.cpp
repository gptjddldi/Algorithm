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
// 이진검색트리
// 왼쪽의 "모든" 자식은 루트 보다 작아야 하고 오른쪽 "모든" 자식은 루트보다 커야 함
// "보장된다" 루트 노드가 가장 큰 값이라는 게
class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(!root) return true;
        if((minNode && root->val <= minNode->val) || 
           (maxNode && root->val >= maxNode->val))
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return isValidBST(root, NULL, NULL);
    }
};