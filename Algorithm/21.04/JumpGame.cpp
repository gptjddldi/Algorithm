// bool dp[i] : 0에서 i까지 갈 수 있는가?
// if(dp[i] == true){
// for(k, k<=nums[i],k++) dp[i+k] = true
//}
// 맨 뒤에서 부터 오면 시간을 아낄 수 있나? 그래도 O(N^2)인듯. 각 인덱스마다 전체 nums 를 순회해야 함
// 임의의 점 i 에서 nums[sz-1] 에 도달할 수 있으면, 해당 i에 도달할 수 있는지 찾기
// 현재 위치에서 가장 멀리갈 수 있는 idx 계속 업데이트 greedy

//GREEDY O(N)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ret = 0;
        for(int i=0; i<nums.size(); i++){
            if (ret>=i)
                ret = max(ret, i+nums[i]);
        }
        return ret>=nums.size()-1;
    }
};

// DP O(N^2)
class Solution {
    bool dp[100002];
public:
    bool canJump(vector<int>& nums) {
        vector<int> pos;
        int tar = nums.size()-1;
        dp[0] = true;
        for(int i-0; i<nums.size(); i++)
            if(i+nums[i] >= nums.size()-1) 
                pos.push_back(i);
        
        for(int i=0; i<nums.size(); i++){
            if(dp[i]){
                if(dp[i] + nums[i] >= nums.size()) return true;
                for(int j=0; j<=nums[i]; j++){
                    dp[i+j] = true;
                }
            }
        }
        return dp[tar];
    }
};