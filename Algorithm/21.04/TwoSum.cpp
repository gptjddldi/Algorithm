#include <bits/stdc++.h>
using namespace std;
// 기존 코드 : nums 의 길이가 1000 이므로 O(n^2) 으로 풀 수 있다고 생각하고 풂
// hash map 사용 : unordered_map 을 탐색하는 시간 O(1) 으로 시간복잡도를 O(n) 으로 개선할 수 있었음.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ret;
        for(int i=0; i<nums.size(); i++){
            int tar = target - nums[i];
            if(mp.find(tar) != mp.end()){
                ret.push_back(i); ret.push_back(mp[tar]);
                break;
            }
            mp[nums[i]] = i;
        }
        
        return ret;
    }
};