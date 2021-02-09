// BOJ 1725. 히스토그램

#include<bits/stdc++.h>
using namespace std;

int N, S;
int arr[100002];

int histogram(int st, int end) { // divide and conquer 
    if (st==end) return 0;
    if (st+1==end) return arr[st];
    int mid = (st+end) / 2;
    int result = max(histogram(st, mid), histogram(mid, end));
    int w = 1, h = arr[mid], r = mid, l = mid;
    while(r-l+1 <= end-st){
        int tl = l>st ?  min(arr[l-1], h) : -1; //왼쪽으로 확장
        int tr = r<end-1 ? min(arr[r+1], h) : -1;
        w++;
        if (tl >= tr){
            h = tl;
            l--;
        }
        else {
            h = tr;
            r++;
        }
        result = max(result, w*h);
    }
    return result;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++){
        cin>>arr[i];
    }
    cout<<histogram(0,N);
}