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
// 시작하는 지점은 루트가 아닐 수 있음, 한번 간 곳은 또 가지 않음
// 플로이드 와샬 그래프인가? 아닌듯.. 플로이드 와샬은 각 정점 사이의 최단거리를 구하는데, O(V^3)임
// 임의의 정점에서 dfs 해서 가장 큰 값 찾기.. 이것도 시간복잡도 클듯? 그리고 이건 root 에서 시작해서 내려가는 방식이기에 못찾는 부분이 있을 수 있음
// 그럼 아래에서 올라가는 방법은.. 그치만 주어진 노드에선 자식 노드만 알 수 있는데
// 만약 루트에서 내려간다면 dfs 로 아니 근데 루트가 음수면?
// maxi = root->val 임 처음엔
// 그리고 왼쪽으로 내려가 여기서 cur->val > maxi 이면 maxi = cur->val 아니라면 maxi = max(maxi, maxi+cur->val) 이런식?
// 두가지 경우
// 1. 현재 노드를 루트로 생각 -> maxi = max(maxi, left+right+cur->val);
// 2. 현재 노드 위로 올라감
class Solution {
int maxi = -9999;

private:
    int help(TreeNode* cur){
        if(!cur) return 0;
        int left = max(0,help(cur->left)); // 왼쪽 값의 합이 음수면 안 더해줌
        int right = max(0,help(cur->right));
        maxi = max(maxi, left+right+cur->val);
        return max(left,right) + cur->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        maxi = root->val;
        help(root);
        return maxi;
    }
};