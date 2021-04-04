#include <bits/stdc++.h>
using namespace std;
// dp[i] : i ~ n-1 까지의 contiguous subarray 들의 합의 최댓값
// dp[i] = dp[i+1]>0 ? nums[i] + dp[i+1] : nums[i]
class Solution {
    int dp[40000];
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        dp[sz-1] = nums[sz-1];
        for(int i=sz-2; i>=0; i--){
            dp[i] = dp[i+1] > 0 ? nums[i] + dp[i+1] : nums[i];
        }
        return *max_element(dp, dp+sz);
    }
};
// 직전 항만을 이용하니까 dp 를 굳이 쓰지 않는 게 메모리를 아낄 수 있음

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sz = nums.size();
        int bf = nums[sz-1], ret = bf;
        for(int i=sz-2; i>=0; i--){
            bf = bf >= 0 ? nums[i] + bf : nums[i];
            ret = max(bf, ret);
        }
        return ret;
    }
};