// BOJ 2098. 외판원 순회

#include <bits/stdc++.h>
using namespace std;
int N, cost[16][16], dp[16][1<<16];
int ret, IMPOSSIBLE = 100000000;
int TSP(int cur, int vis){
    int &ret = dp[cur][vis];
    if(ret!=-1) return ret;
    if(vis == (1<<N) -1){
        // base condition : 모든 마을을 방문했을 때.
        if(cost[cur][0] !=0) return cost[cur][0]; // 현재 위치에서 0으로 돌아갈 수 있으면
        return IMPOSSIBLE;
    }
    ret = IMPOSSIBLE;
    for (int i = 0; i < N; i++)
    {
        // 현 위치에서 모든 N 개의 마을에 대해
        // 만약 i 번 마을을 이미 방문했거나 방문할 수 없으면 pass
        if((vis & (1<<i)) || cost[cur][i]==0) continue;
        // 방문할 수 있는 경우. vis|(1<<i) : i번 마을을 0 -> 1로 바꾸는 연산
        ret = min(ret, TSP(i, vis|(1<<i))+cost[cur][i]);
    }
    return ret;
    
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int k = 1<<16;
    cin>> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin>>cost[i][j];

    memset(dp, -1, sizeof(dp));
    cout<<TSP(0,1);
}