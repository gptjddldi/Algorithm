import sys
input = sys.stdin.readline
L = input().split('-')
res = 0
for i in range (len(L)):
    a = L[i].split('+')
    L[i] = 0
    for j in range(len(a)):
        L[i] += int(a[j])
    res = res - L[i]
print(res+L[0]*2)