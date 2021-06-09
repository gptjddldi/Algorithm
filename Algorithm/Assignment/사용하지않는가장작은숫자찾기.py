def get_smalist(lis:list)->int:
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

def get_smalist_b(lis):
    """
    공간 최적화
    가장 작은 수는 len(lis) 이하, 그럼 그 보다 큰 수는 무시하고,
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

if __name__ == '__main__':
    lis = [0, 1, 3, 1, 4, 3]
    print(get_smalist(lis), get_smalist_b(lis), sep=", ")