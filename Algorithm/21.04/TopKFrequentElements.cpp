// 해시 맵에 빈도 수 저장
// 벡터로 옮겨서 value 를 기준으로 sort
class Solution {
    unordered_map<int,int> mp;
    vector<int>ret;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> ve(mp.begin(), mp.end());
        sort(ve.begin(), ve.end(), [](pair<int,int>a, pair<int,int>b){return a.second>b.second;});
        for(auto it: ve){
            ret.push_back(it.first);
            if(++cnt == k) break;
        }
        return ret;
    }
};

// priority queue 사용

class Solution {
    unordered_map<int,int> mp;
    vector<int>ret;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : mp)
            pq.push({it.second, it.first});
        for(int i=0; i<k; i++){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};