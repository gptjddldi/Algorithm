def maxProfit(prices):
    ret = 0
    cur = prices[0]
    for i in prices:
        if i>cur:
            ret = max(ret, i-cur)
        else:
            cur = i
    return ret