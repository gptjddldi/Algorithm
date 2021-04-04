#include<bits/stdc++.h>
using namespace std;

// 잘 모르겠음;;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, ed = nums.size()-1;
        while(st<=ed){
            int mid = (st+ed)/2;
            if(nums[mid]==target) return mid;
            
            if(nums[mid] > nums[ed]){ //  
                if(target<nums[mid] && target>=nums[st])
                    ed = mid-1;
                else st = mid+1;
            }
            else if(nums[mid] < nums[st]){
                if(target>nums[mid] && target<=nums[ed])
                    st = mid+1;
                else ed = mid-1;
            }
                
            else{ // no rotation (sorted)
                if(nums[mid] < target)
                    st = mid+1;
                else
                    ed = mid-1;
            }
        }
        return -1;
    }
};
// 4,5,6,7,0,1,2

// 7,0,1,2,4,5,6
// tar=5
// tar=0 st=0 ed=6 mid=3 nums[mid]=7