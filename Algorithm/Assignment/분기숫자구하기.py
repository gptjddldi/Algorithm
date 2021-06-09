def quater(n:int)->int: 
    """
    분기 숫자 구하기
    0< n <= 12
    """
    return (n-1)//3 + 1

if __name__ == '__main__':
    for i in range(1,13):
        print(i, quater(i), sep="월 : ", end="분기\n")