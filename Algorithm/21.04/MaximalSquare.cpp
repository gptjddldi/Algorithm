// 정사각형
// 이걸 어케 찾음?
// 재귀, if matrix[i][j]==1 -> matrix[i+1][j] matrix[i][j+1] matrix[i+1][j+1] 을 탐색
// 실패 -> 답봄
// dp 사용, dp[r+1][c+1] = min(dp[r][c+1], dp[r+1][c], dp[r][c]) + 1;
class Solution {
    int ret = 0;
    int dp[302][302];
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        for(int r=0; r<N; r++){
            for(int c=0; c<M; c++){
                if(matrix[r][c]=='1'){
                    dp[r+1][c+1] = min({dp[r][c+1], dp[r+1][c], dp[r][c]})+1;
                    ret = max(dp[r+1][c+1], ret);
                }
            }
        }
        return pow(ret,2);
    }
};