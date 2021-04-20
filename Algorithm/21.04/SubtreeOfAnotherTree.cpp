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
// subtree 자기 자신도 가능
// 재귀?
// s 의 루트가 같은 경우부터 시작
// 같지 않으면? left 자식 탐색.. 이런 식으로 하는 건가?
// 루트의 val 이 맞으면 -> isSubtree(s->left, t->left) isSubtree(s->right, t->right)
// 맞지 않으면 ? 
// 아까 한 것처럼 [3,3,1,1,2] [3,1,2] 이 경우를 해결해야함
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isSame(TreeNode* s, TreeNode* t){
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        
        if(isSame(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};