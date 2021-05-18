import sys
import queue
from itertools import combinations

input = lambda:sys.stdin.readline().rstrip()
n, m, v = map(int, input().split())

lis = [list() for _ in range(n+1)]

for _ in range(m):
    s, e = map(int, input().split())
    lis[s].append(e)
    lis[e].append(s)
for x in lis:
    x.sort()


def bfs(st):
    vis = [False] * (n+1)
    q = queue.Queue()
    q.put(st)
    vis[st] = True
    while not q.empty():
        cur = q.get()
        print(cur, end=" ")
        for nxt in lis[cur]:
            if not vis[nxt]:
                vis[nxt] = True
                q.put(nxt)

def dfs(st):
    vis = [False] * (n+1)
    s = list()
    vis[st] = True
    s.append(st)
    while len(s):
        cur = s.pop()
        print(cur, end=" ")
        for nxt in lis[cur]:
            if not vis[nxt]:
                vis[nxt] = True
                s.append(nxt)

def rec(node):
    vis[node] = True
    print(node, end=" ")
    for nxt in lis[node]:
        if not vis[nxt]:
            rec(nxt)
    

# dfs(v)
vis = [False] * (n+1)
rec(v)
print()
bfs(v)