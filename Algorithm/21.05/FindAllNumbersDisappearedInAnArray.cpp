// 생각 
// 메모리를 이용한다면
// 첫 반복에 이게 나오는 지 넣고 두번째 반복에 나오지 않은 애들을 넣어주면 됨
// 그 결과는 [4,3,2,7,8,2,3,1] 인 경우
// [1,2,2,1,0,0,1,1] 이게 나온다.
// 그럼 여기서 메모리를 쓰지 않으려면?

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret, ve(nums.size()+1);
        
        int n = nums.size();
        int i=0;
        for(int num : nums){
            ve[num]++;
        }
        for(int i=1; i<=n; i++)
            if(!ve[i]) ret.push_back(i);
        
        return ret;
    }
};

vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        
        int n = nums.size();
        int i=0;
        for(int i=0; i<n; i++){
            int m = abs(nums[i])-1;
            nums[m] = nums[m] > 0 ? -1 * nums[m] : nums[m];
        }
        for(int i=0; i<n; i++)
            if(nums[i]>0) ret.push_back(i+1);
        
        return ret;
    }