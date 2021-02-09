// BOJ 2104. 부분 배열 고르기

#include <bits/stdc++.h>
using namespace std;

long long N, ret;
long long arr[100002];

long long dnq(int st, int end){
    if(st==end) return arr[st]*arr[st];
    if(st+1==end) {
        if(arr[st]>=arr[end]){
            return max(arr[st]*arr[st], (arr[st]+arr[end])*arr[end]);
        }
        else{
            return max(arr[end]*arr[end], (arr[st]+arr[end])*arr[st]);
        }
        // return (arr[st]+arr[end]) * min(arr[st],arr[end]);

    }    
    int mid = (st + end) / 2;
    ret = max(dnq(st, mid), dnq(mid+1, end));

    long long l = mid, r = mid, mini = arr[mid], sum = arr[mid];
    while(r-l<=end-st){
        long long toL = l>=st ? min(arr[l-1], mini) : -1;
        long long toR = r+1<=end ? min(arr[r+1], mini) : -1;

        long long retL = toL * (sum + arr[l-1]);

        long long retR = toR * (sum + arr[r+1]);

        if(retL >= retR){
            l--;
            mini = toL;
            sum += arr[l];
        }
        else{
            r++;
            mini = toR;
            sum += arr[r];
        }
        ret = max(mini*sum ,ret);
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        cin>>arr[i];
    }
    cout<<dnq(1, N);
}