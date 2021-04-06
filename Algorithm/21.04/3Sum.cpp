// 최대 O(N^2) 안에 풀면 될듯?
// 2 개의 합이 nums[i] * -1 이 되도록 하면 될듯
// Two Sum 은 어떻게 풀었었지?
// 풀이 보고 풀었음 hash_map 를 쓰면 중복을 어떻게 처리할 지 잘 생각이 안나서
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()<=2) return ret;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++){
            int a = nums[i];
            if(a>0) break; // nums 는 정렬되었으므로 a>0 보다 큰 값들의 합이 0 인 경우는 불가능
            if(i>0 && a == nums[i-1]) continue; // 중복 제거
            for(int j=i+1, k = nums.size()-1; j<k;){
                int b = nums[j], c = nums[k];
                int value = a + b + c;
                if (value==0) {
                    ret.push_back({a,b,c,});
                    while(j<k && nums[++j]==b); // 중복 제거
                    while(j<k && nums[--k]==c); // 중복 제거
                }
                else if (value<0)
                    j++;
                 else k--;
            }
            
        }
        return ret;
    }
};