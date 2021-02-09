// BOJ 14002. 가장 긴 증가하는 부분 수열 4

#include <bits/stdc++.h>
using namespace std;
int A[1004];
int dp[1004];
int v[1004];
int N, cnt, p;

void func(int x){
    if(x==-1) return;
    func(v[x]);
    cout<<A[x]<<' ';
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++)
        cin>>A[i];
    
    for (int i = 0; i < N; i++)
    {
        // int k=40;
        dp[i] = 1;
        v[i] = -1;
        for (int j = 0; j < i; j++)
        {
            if(A[i]>A[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
                // k = j;
                v[i] = j;
            }
        }
        if(cnt<dp[i]){
            cnt = dp[i];
            p = i;
        }
    }
    cout<<cnt<<'\n';
    func(p);
}




// // BOJ 14002. 가장 긴 증가하는 부분 수열 4

// #include <bits/stdc++.h>
// using namespace std;
// int A[1004];
// int lis[1004];
// int lisCnt;
// int trace[1004];
// int N;

// // n: 배열 A의 길이
// int findLIS(int n){
//     for(int i=0; i<n; i++){
//         if(i==0 || A[i] > lis[lisCnt-1]){
//             trace[A[i]] = lisCnt;
//             lis[lisCnt++] = A[i];
//         } else{
//             int start = 0, end = lisCnt;
//             int idx = lisCnt;
//             while(start<end){
//                 int mid = (start+end) / 2;
//                 if(lis[mid] >= A[i]) {
//                     idx = min(idx, mid);
//                     end = mid;
//                 } else {
//                     start = mid+1;
//                 }
//             }
//             lis[idx] = A[i];
//             trace[A[i]] = idx;
//         }
//     }
//     // trace 배열에서 가장 나중을 꺼내면 됨
//     int cur = lisCnt-1;
//     for(int i= n-1; i>=0; i--){
//         if(trace[A[i]] == cur) {
//             lis[cur] = A[i];
//             cur--;
//         }
//     }
//     return lisCnt;
// }

// int main(){
//     cin.tie(0); ios::sync_with_stdio(0);
//     cin>>N;
//     for (int i = 0; i < N; i++)
//         cin>>A[i];
//     int len = findLIS(N);
//     cout<<len<<'\n';
//     for(int i=0; i<len; i++) cout<<lis[i]<<' ';
// }