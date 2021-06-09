class Solution:
    def quater(self, n:int)->int: 
        """
        분기 숫자 구하기
        0< n <= 12
        """
        return (n-1)//3 + 1

    def get_smalist(self, lis:list)->int:
        """
        사용하지 않는 가장 작은 숫자 찾기
        가장 작은 수는 len(lis) 이하
        [0,1,2,3] 일 경우 리턴 값 4,
        [0,99,999,999] 일 경우 1
        [1,len(lis)]
        Time : O(N)
        Space: O(N)
        """
        flags = [False] * (len(lis)+1)
        for num in lis:
            if num <= len(lis):
                flags[num] = True
        
        for idx in range(len(flags)+1):
            if flags[idx] == False:
                return idx

    def get_smalist_b(self, lis):
        """
        공간 최적화
        가장 큰 수는 len(lis) 이하, 그럼 그 보다 큰 수는 무시하고,
        flag 대신, 주어진 lis 를 변형시켜서 lis[i] 를 flag[i] 로 사용..
        Time : O(N)
        Space : O(1)
        """
        for i in range(len(lis)):
            if lis[i] > len(lis):
                lis[i] = (len(lis)+1)
        
        for num in lis:
            num = abs(num)
            if num > 0 and num < len(lis):
                if lis[num] > 0:
                    lis[num] *= -1

        for i in range(len(lis)):
            if lis[i] > 0:
                return i

        return len(lis)

    def get_score(self, lis)->int:
        score = 0
        for num in lis:
            a, b = map(int, num.split(":"))
            if a > b:
                score += 3
            elif a == b:
                score += 1
            else:
                pass
        return score

    def get_fruite(self, n:int)->str:
        """
        더하고 빼기
        
        n>100 인 경우 항상 99로 수렴함
        100+k 일 때 (0<=k<10)
        100+k - (1+k) = 99
        """
        if n > 100:
           return "pineapple" 

    def count_vowel(self, word:str)->int:
        """
        모음 찾기
        Time : O(N)
        Space : O(1)
        """
        lis = ['a','e','i','o','u']
        cnt = 0
        for a in word:
            if a in lis:
                cnt += 1
        return cnt
    
    def get_second_num(self, lis:list)->int:
        """
        중간 숫자 찾기
        """
        if lis[0] > lis[1]:
            first, second = 0, 1
        else:
            first, second = 1,0

        if lis[2] > lis[first]:
            return first
        elif lis[2] < lis[second]:
            return second
        else:
            return 2
        # 한 줄 풀이
        # return lis.index(sorted(lis)[1])
    

    def find_friend(self, users:list)->list:
        """
        친구 찾기
        Time : O(N)
        Space : O(N)
        """
        return [name for name in users if len(name)==4]


    def iq_test(self, numbers:str)->int:
        """
        아이큐 테스트
        홀수인 경우 cnt += 1, 짝수 cnt -= 1

        Time : O(N)
        Space : O(1)
        """
        s1, s2, cnt = 0, 0, 0 #홀, 짝
        for i, num in enumerate(numbers.split()):
            if int(num) % 2 == 1: #홀
                if cnt <= 0:
                    s1 = i+1
                cnt += 1
            else:
                if cnt >= 0:
                    s2 = i+1
                cnt -= 1
        return s1 if cnt<=0 else s2


if __name__ == '__main__':
    sol = Solution()
    lis =  "1 1 1 2 1 1"
    print(sol.iq_test(lis))