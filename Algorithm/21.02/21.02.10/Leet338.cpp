#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    vector<int> countBits(int num) {
        dp.resize(num+1);
        dp[0] = 0;
        if(num==0) return dp;
        dp[1] = 1;
        if(num==1) return dp;
        dp[2] = 1;
        
        for(int i=3; i<=num; i++){
            dp[i] = dp[i-pow(2,(int)log2(i))] + 1;
        }
        return dp;
    }
};