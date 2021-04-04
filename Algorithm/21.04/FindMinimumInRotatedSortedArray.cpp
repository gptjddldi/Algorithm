#include<bits/stdc++.h>
using namespace std;
// 풀고 보니까 binary search 로 푸는듯? (max_element 는 비겁하니까 안씀)
// 나는 원래 sorted 된 배열로 돌아가서 nums[0] 을 찾는 식으로 했음
// 근데 이분탐색을 쓰는 문제라면 왜, 굳이 rotate 한다는 조건이 있을까?
class Solution {
public:
    int findMin(vector<int>& nums) {
        vector<int> ve;
        int sz = nums.size();
        for(int k : nums)
            ve.push_back(k);
        sort(ve.begin(), ve.end());
        while(ve[0] != nums[0]){
            int ed = nums.back();
            copy(nums.begin(), nums.end()-1, nums.begin()+1);
            nums[0] = ed;            
        }
        return nums[0];
    }
};