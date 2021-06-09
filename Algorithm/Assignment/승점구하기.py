def get_score(lis)->int:
    score = 0
    for num in lis:
        a, b = map(int, num.split(":"))  # n:m -> a: n점, b: m점 
        if a > b:
            score += 3
        elif a == b:
            score += 1
        else:
            pass
    return score

if __name__ == '__main__':
    lis = ["3:1", "2:2", "1:3"]
    print(get_score(lis))