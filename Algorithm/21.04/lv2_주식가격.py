import collections

def solution(prices):
    # n^2 : 100억
    stack = [0]
    answer = [len(prices)-i-1 for i in range(len(prices))]
    
    for i in range(1,len(prices)):
        while stack:
            idx = stack[-1]
            
            if prices[idx] > prices[i]:
                answer[idx] = i - idx
                stack.pop()
            else:
                break
        stack.append(i)
    
    return answer