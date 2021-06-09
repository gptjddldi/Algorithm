def get_second_num(lis:list)->int:
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

def get_second_num_b(lis:list)->int:
    # 한 줄 풀이
    return lis.index(sorted(lis)[1])

if __name__ == '__main__':
    lis = [0,1,2]
    print(get_second_num(lis), get_second_num_b(lis), sep=", ")