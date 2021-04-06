// 양쪽 끝 중에 더 작은 값을 기준으로
// divide and conquer 
// 3 가지 경우로 나눠서 생각함
// mid 를 포함하는 경우, mid 의 왼쪽에 있는 경우, mid 의 오른쪽에 있는 경우

// 투 포인터
//l=0 r=height.size()-1 ret = min(l,r) * r-l 인데, 
// 여기서 l++ or r-- 하는 경우를 어떻게 나눌 수 있지?
// 둘 중에 더 작은 값을 가지는 idx 를 ++ 하거나 -- 해서 구하면 됨

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        for(int l=0, r = height.size()-1; l<r;){
            
            if(height[l] <= height[r]){
                ret = max(ret, height[l]*(r-l));
                l++;
            }
            else {
                ret = max(ret, height[r]*(r-l));
                r--;
            }            
        }
        return ret;
    }
};