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
// 전위순회, 중위순회가 주어졌을 때 원래 트리를 구하셈
// 전에 백준에서 비슷한 걸 풀었었지
// recursion 으로 조지면 될 것 같은데.
// preorder 의 첫번째가 계속 루트노드라고 생각하면 됨
//
class Solution {
    TreeNode * res;
private:
    TreeNode* recursion(vector<int>& preorder, vector<int>& inorder){
        // preorder[0] 이 inorder 에서의 index 를 찾아야 함
        // 0~index-1 : left, preorder[1] ~ preorder[index]
        // index+1 ~ inorder.size()-1 : right, 
        // preorder[index+1] ~ preorder[inorder.size()-1]
        // 이런 느낌임
        if(!inorder.size()) return NULL;
        TreeNode* ret = new TreeNode(preorder[0]);
        int idx = 0;
        while(inorder[idx] != preorder[0]) idx++;
        vector<int> l, r, pl, pr;
        for(int i=0; i<inorder.size(); i++){
            if(i<idx) l.push_back(inorder[i]);
            else if (i>idx) r.push_back(inorder[i]);
        }
        for(int i=1; i<inorder.size(); i++){
            if(i<=idx) pl.push_back(preorder[i]);
            else pr.push_back(preorder[i]);
        }
        ret->left = recursion(pl,l);
        ret->right = recursion(pr,r);
        return ret;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        res = recursion(preorder, inorder);
        
        return res;
    }
};
// 좀 더 시간 아낌
TreeNode* recursion(vector<int>& preorder, vector<int>& inorder, 
                        int left, int right, int& cur){

        if(left>right) return NULL;
        TreeNode* ret = new TreeNode(preorder[cur]);
        int idx = left;
        while(inorder[idx] != preorder[cur]) idx++;
        cur++;
        ret->left = recursion(preorder, inorder, left, idx-1, cur);
        ret->right = recursion(preorder, inorder, idx+1, right,cur);
        return ret;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int cur = 0;
        res = recursion(preorder, inorder, 0, preorder.size()-1,cur);
        
        return res;
    }