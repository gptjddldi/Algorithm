// x 를 입력받음 x-1 or x+1 이 있는지 확인하면서 진행
// nlogn 으로 푸는 방법은 LIS 알고리즘 풀때 했던 방식으로 풀 수 있음
// 그럼 n 으로 푸는 방법은?
// LIS 는 증가하기만 하면 됐음. 이 문제는 연속적으로 증가해야함 (consecutive)
// x 를 입력받음, x-1 과 x+1 모두 존재할 경우, 하나만 존재할 경우, 존재 안 할 경우로 나눠서
// mp[x] 는 현재 연속인 개수
// 만약 [1,2,3,4,5] 에서 지금 x=3 을 탐색할 차례다? 하면 mp[1] = 1 mp[2] = 2 인 상황임
// mp[4] 는 아직 존재하지 않고, mp[2] 가 존재하니 mp[3] = mp[3-1]+1 이 됨

// 그럼 만약 [1,3,4,2] 이면? mp[1] = 1 mp[3] = 1 mp[4] = mp[3]+1 = 2, mp[3] = mp[4], 
// mp[2] = mp[1] + mp[3] + 1 이렇게 됨
// [100,4,200,1,3,2] 이면 mp[100]=1 mp[4]=1 mp[200]=1 mp[1]==1 mp[3]==mp[4]+1=2 mp[4]=2 mp[2] = mp[3] + mp[1] + 1
// [0,1,3,7,2,5,8,4,6,1]
// mp[0] = 1 mp[1] = 2 mp[3] = 1 mp[7] = 1 mp[2] = 3 mp[5] = 1 mp[8] = mp[7]+1 = 2 mp[4] = 4 mp[6] = 2 + 1 = 3
// 양 옆을 갱신하는 게 아니라 양 옆 끝을 갱신해야함
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ret = 0;
        for(int num : nums){
            if(mp[num]) continue;
            
            if(mp.find(num-1)!=mp.end() && mp.find(num+1)!=mp.end()){ // 양 옆 다 존재
                mp[num] = mp[num-1] + mp[num+1] + 1;
                mp[num-mp[num-1]] = mp[num];
                mp[num+mp[num+1]] = mp[num];
                ret = max(ret, mp[num]);
            } else if(mp.find(num-1) != mp.end()){
                mp[num] = mp[num-1] + 1;
                mp[num-mp[num-1]] = mp[num];
                ret = max(ret, mp[num]);
            } else if(mp.find(num+1) != mp.end()){
                mp[num] = mp[num+1] + 1;
                mp[num+mp[num+1]] = mp[num];
                ret = max(ret,mp[num]);
            } else mp[num] = 1;
            ret = max(ret,mp[num]);
        }
        return ret;
    }
};