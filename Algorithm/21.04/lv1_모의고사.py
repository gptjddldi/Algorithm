def solution(answers):
    s1 = [1,2,3,4,5]
    s2 = [2,1,2,3,2,4,2,5]
    s3 = [3,3,1,1,2,2,4,4,5,5]
    dic = dict()
    dic[1] = 0
    dic[2] = 0
    dic[3] = 0
    for i in range(len(answers)):
        if answers[i] == s1[i%5]:
            dic[1] += 1
        if answers[i] == s2[i%8]:
            dic[2] += 1
        if answers[i] == s3[i%10]:
            dic[3] += 1
    a, b = max(dic.items(), key=lambda item: item[1])
    ret = [idx for idx, v in dic.items() if v==b]
    return ret