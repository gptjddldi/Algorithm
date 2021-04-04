// 벡터 한번 순회하면서 차이의 최댓값을 리턴, O(n) 으로 풀어야 함
// 가장 작은 수와 그 이후로 커진 수의 차의 최댓값
// 백터를 한번 순회하면서 계속 이전 수와의 크기를 비교함
// 이전 수 보다 작아진 경우 mini 에 저장, maxi=mini 로 갱신
// 이전 수 보다 큰 경우 계속 maxi 에 저장
// maxi - mini 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = prices[0], mini = prices[0];
        int ret = 0;
        for(int i=0; i<prices.size(); i++){
            if(mini > prices[i]){
                mini = prices[i];
                maxi = mini;
            } else maxi = max(maxi, prices[i]);
            ret = max(maxi-mini, ret);
        }
        return ret;
    }
};