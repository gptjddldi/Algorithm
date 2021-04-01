# 스택에 넣어서 될까?
def solution(skill, skill_trees):
    
    answer = 0
    for word in skill_trees:
        skill_list = list(skill)
        for s in word:
            if s in skill:
                if s != skill_list.pop(0):
                    break
        else:
            answer += 1
    return answer