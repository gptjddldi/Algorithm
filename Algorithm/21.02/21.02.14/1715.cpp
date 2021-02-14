// BOJ 1715. 카드 정렬하기
// 우선순위 큐, 작은 것 부터 나오면 ㅇㅋ
#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int N;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        int k;
        cin>>k;
        pq.push(k);
    }
    int ret = 0;
    while(!pq.empty()){
        if(pq.size()==1) {
            cout<<ret;
            break;
        }
        int k1 = pq.top();
        pq.pop();
        int sum = k1 + pq.top();
        ret += sum;
        pq.pop();
        
        pq.push(sum);
    }
}