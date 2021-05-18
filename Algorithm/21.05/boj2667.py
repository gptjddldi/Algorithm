import sys
import queue
input = lambda : sys.stdin.readline().rstrip()
dirR = [0,1,0,-1]
dirC = [1,0,-1,0]

n = int(input())
lis = [list(map(int, input())) for _ in range(n)]
vis = [[False]*n for _ in range(n)]
ret = []
cnt = 1

def bfs(start):
    cnt = 1
    vis[start[0]][start[1]] = True
    q = queue.Queue()
    q.put(start)
    while not q.empty():
        cur = q.get()
        for i in range(4):
            nr = cur[0] + dirR[i]
            nc = cur[1] + dirC[i]
            if nr<0 or nc<0 or nr>=n or nc>=n or vis[nr][nc] != 0 or lis[nr][nc]==0:
                continue
            vis[nr][nc] = True
            cnt += 1
            q.put([nr,nc])
    return cnt

for r in range(n):
    for c in range(n):
        # cnt = 1
        if lis[r][c] != 0 and not vis[r][c]:
            ret.append(bfs([r,c]))

ret.sort()
print(len(ret), *ret,sep="\n")
