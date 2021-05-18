import sys
from itertools import combinations
input = lambda : sys.stdin.readline().rstrip()

n, m = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(n)]

home, chicken = [], []
for r in range(n):
    for c in range(n):
        if board[r][c] == 1:
            home.append([r,c])
        if board[r][c] == 2:
            chicken.append([r,c])


def get_dist(home, lis):
    dist = 2500
    for a in lis:
        dist = min(dist, abs(home[0] - a[0]) + abs(home[1] - a[1]))
    return dist

chi_list = list(combinations(chicken, m))
res = float('inf')
for a in chi_list:
    summ = 0
    for h in home:
        summ += get_dist(h, a)
    res = min(res, summ)
print(res)