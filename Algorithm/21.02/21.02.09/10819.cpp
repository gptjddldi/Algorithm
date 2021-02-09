// BOJ 10819. 차이를 최대로

#include <bits/stdc++.h>
using namespace std;
int N, ret;
vector<int> ve;
vector<int> arr(10);
bool used[10];
int getSum(vector<int>& ve){
    int sum = 0;
    for (int i = 0; i < N-1; i++)
    {
        sum += abs(ve[i]-ve[i+1]);
    }
    return sum;
}

int bt(int cur){
    if(cur==N){
        return getSum(arr);
    }
    for (int i = 0; i < N; i++){
        if(!used[i]){
            used[i] = true;
            arr[cur] = ve[i];
            // if(ret < bt(cur+1)){
            //     ret = bt(cur+1);
            //     for(int c: arr) cout<<c<<',';
            // cout<<'\n';}
            ret = max(ret, bt(cur+1));
            
            used[i] = false;
        }
    }
    return -1;
}
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin>>t;
        ve.push_back(t);
    }
    bt(0);
    cout<<ret;
    // cout<<getSum(ve);
    return 0;
}