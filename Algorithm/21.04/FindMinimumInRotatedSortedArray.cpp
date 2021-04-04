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
// 왜 이분탐색으로 푸는 문제인가? 하면 이분탐색은 일단 정렬된 배열에 대해서 탐색을 진행함
// 근데 주어진 배열은 정렬된 배열을 오른쪽으로 x칸 이동시킨 것.
// 여기서 이분탐색 아이디어를 사용하는 것같음.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int st=0, ed = nums.size()-1;
        while(st < ed){
            int mid = (st+ed)/2;
            if (nums[st] < nums[ed]) // 정렬된 경우
                return nums[st];
            if (nums[mid] >= nums[st])
                st = mid+1;
            else
                ed = mid;
            
        }
        return nums[st];
    }
};
//1, 2, 3, 4, 5 -> 5, 1, 2, 3, 4