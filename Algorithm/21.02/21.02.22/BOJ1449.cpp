// BOJ 1449. 수리공 항승
// 테이프를 붙일 곳을 leak, 
//누수가 된 양옆 0.5 를 매워야 하니까 정수로 다루기 위해 전체 길이 *2 한 뒤 양 옆 1 을 매운다고 생각
#include <bits/stdc++.h>
using namespace std;

int cnt, N, L;
bool leak[3003];
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>L;
    for (int i = 0; i < N; i++)
    {
        int k;
        cin>>k;
        leak[2*k-1] = true, leak[2*k] = true, leak[2*k] = true;

    }
    for (int i = 0; i < 2000; i++)
    {
        if(leak[i]){
            for (int j = 0; j < 2*L; j++)
            {
                leak[i+j] = false;
            }
            cnt++;
        }
    }
    cout<<cnt;
    
}