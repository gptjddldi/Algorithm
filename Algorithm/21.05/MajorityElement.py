# 선형 시간, 상수 공간
# 해시맵 이용하기 : 해시맵을 하나 만들어서 해당하는 번호에 카운트하기
# 근데 이건 공간복잡도 O(n) 임
# 그럼 이걸 O(1) 로 어떻게 ?
# n/2 번 초과로 나오는 원소는 딱 하나임

# Boyer-Moore Majority Vote Algorithm 라는 알고리즘이래요.. 알고 있었어?
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ret = nums[0]
        cnt = 0
        for num in nums:
            if cnt==0:
                ret = num
            if ret==num:
                cnt += 1
            else:
                cnt -= 1
        return ret