class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366]={};
        unordered_set<int> travel(begin(days), end(days));
        for(int i=days.front(); i< days.back(); i++) {
            if(travel.find(i) == travel.end()) dp[i] = dp[i-1];
            else
                dp[i] = min({dp[i-1]+costs[0], dp[i-7> 0? i-7:0]+costs[1]
                    , dp[i-30> 0? i-30:0]+costs[2]});
        }
        return dp[days.back()-1];
    }
};