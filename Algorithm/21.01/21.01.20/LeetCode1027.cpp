// LeetCode 1027. Longest Arithmetic Subsequence
#include <bits/stdc++.h>
using namespace std;

int longestArithSeqLength(vector<int>& A) {
    int n = A.size();
    vector<vector<int>> d(n, vector<int>(1005,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int r = A[j] - A[i]
            d[j][r] = max(2, dp[i][d])
        }
        
    }
    
}

int main() {
    vector<int> A = {9,4,7,2,10};
    cout<<longestArithSeqLength(A);
}