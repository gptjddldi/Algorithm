def iq_test(numbers:str)->int:
    """
    아이큐 테스트
    홀수인 경우 cnt += 1, 짝수 cnt -= 1

    Time : O(N)
    Space : O(1)
    """
    s1, s2, cnt = 1, 1, 0 #홀, 짝 index

    for i, num in enumerate(numbers.split()):  # i, numbers[i]
        if int(num) % 2 == 1: #홀
            if cnt <= 0:
                s1 = i+1  # index : 1 부터 시작, 기존 index + 1
            cnt += 1
        else:
            if cnt >= 0:
                s2 = i+1
            cnt -= 1
    return s1 if cnt<=0 else s2

if __name__ == '__main__':
    # numbers = "1"
    numbers = "2 4 7 8 10"
    print(iq_test(numbers))