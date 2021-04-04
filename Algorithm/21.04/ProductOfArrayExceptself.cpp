#include <bits/stdc++.h>
using namespace std;

// without using division.. 원래 생각 : 다 곱해서 하나씩 나눠주기
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ve;
        int pd = 1, pd2 = 1, cnt = 0;
        for(int k : nums){
            if(k){
                pd *= k;
                pd2 *= k;
            }
            else{
                cnt++;
                pd2 *= k;
            }
                
            
        }
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]) ve.push_back(pd/nums[i]);
        //     else ve.push_back();
        // }
        for(int k : nums){
            if(k) ve.push_back(pd2/k);
            else if(cnt>=2) ve.push_back(0);
            else ve.push_back(pd);
        }
        return ve;
    }
};

// 앞에서 부터 구한 곱 * 뒤에서 부터 구한 곱, 시간복잡도 O(N) 공간 복잡도 O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> ret(sz);
        fill(ret.begin(), ret.end(), 1);
        int st = nums[0];
        int ed = nums[sz-1];
        for(int i=1; i<sz; i++){
            ret[i] *= st;
            ret[sz-i-1] *= ed;
            st = nums[i] * st;
            ed = nums[sz-i-1] * ed;
        }
        return ret;
    }
};