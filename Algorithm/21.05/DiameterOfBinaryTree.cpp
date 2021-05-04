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
// 임의의 한 점(루트)에서 가장 멀리 떨어진 점
// 그 점에서 가장 먼 점까지의 거리인데,
// 리프노드에서 다른 리프노드까지 거리는 어케 구할 거?
// 왼쪽 자식 오른쪽 자식만 접근할 수 있자나..

// 몰라서 해설 봄
// 현재 노드에서 왼쪽 depth + 오른쪽 depth 의 최댓값이 diameter 구나.
// 이걸 각 노드에 반복하면 되는 건가
// 1. 루트 노드를 지날 때 최대 길이라면 root->left depth + root->right depth 가 답임
// 2. 루트 노드를 지나지 않는다면 root->left, root->right 에 대하여 1번 수행
class Solution {
    int ret = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        rec(root,d);
        return d;
    }
    int rec(TreeNode* root, int& depth){
        if(!root) return 0;
        int ld = rec(root->left, depth);
        int rd = rec(root->right, depth);
        depth = max(depth, ld+rd);
        return max(ld,rd) +1;
    }
};