from collections import deque
def solution(priorities, location):
    cnt = 0
    q = deque()
    b = priorities[:]
    b.sort(reverse=True)
    for i in range(len(priorities)):
        q.appendleft(i)
    while(q):
        cur = q.pop() #cur 은 idx임  
        if priorities[cur] != b[0]:
            q.appendleft(cur)
            continue
        else:
            cnt+=1
            b = b[1:]
            if(cur==location): break
        
    return cnt