#include <bits/stdc++.h>
using namespace std;
// dp[i] 에 가장 작은 값과 가장 큰 값을 둘 다 저장한다면?
// dp[i].first : 최대 dp[i].second : 최소
// 근데 이것도 dp 를 굳이 쓰지 않아도 되겠지?
class Solution {
    // pair<int,int>dp[22222];
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int sz = nums.size();
        int ma = nums[0], mi = nums[0];
        // dp[0] = {nums[0],nums[0]};
        for(int i=1; i<sz; i++){
            int tmp1 = max({ma*nums[i], mi*nums[i], nums[i]});
            // dp[i].first = max({dp[i-1].first*nums[i], dp[i-1].second*nums[i], nums[i]});
            int tmp2 = min({ma*nums[i], mi*nums[i], nums[i]});
            // dp[i].second = min({dp[i-1].first*nums[i], dp[i-1].second*nums[i], nums[i]});
            ma = tmp1; mi = tmp2;
            maxi = max(ma, maxi);
        }
        return maxi;
    }
};