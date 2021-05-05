// 이분탐색으로 풀어랴
// 이분탐색을 두번 사용하면?
// 처음 사용에선 left 를 구하고 두번째에선 right 를 구함
// left 를 구하는 방법은 target 직전 작은 값의 idx +1
// right 는 target 보다 큰 값의 idx -1
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        if(!nums.size()) return ret;
        int l = 0, r = nums.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid] < target) l=mid+1;
            else
                r=mid; 
        }
        if(nums[l]!=target) return ret;
        ret[0] = l;
        r = nums.size()-1;
        while(l<r){
            int mid = (l+r)/2 +1;
            if(nums[mid] > target) r=mid-1;
            else
                l=mid;
            
        }
        ret[1] = r;
        return ret;
    }
};