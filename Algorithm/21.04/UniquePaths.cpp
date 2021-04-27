class Solution {
    int dp[101][101];
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        dp[0][0] = 0;
        dp[1][0] = 1, dp[0][1] = 1;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                if(r>0) dp[r][c] += dp[r-1][c];
                if(c>0) dp[r][c] += dp[r][c-1];
            }
        }
        return dp[m-1][n-1];
    }
};
// 메모리를 더 줄이는 방법?
// 