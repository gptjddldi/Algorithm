// BOJ 7662. 이중 우선순위 큐
// 최대힙, 최소힙 2개를 가지고 풀 수 있는 것 같은데 실패했다
// multiSet 사용, end 에 --는 왜 붙이는 거지?
#include <bits/stdc++.h>
using namespace std;
int t,N, num;
char cmd;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        multiset<int> s;
        cin>>N;
        for (int i = 0; i < N; i++)
        {
            cin>>cmd>>num;
            if(cmd=='I'){
                s.insert(num);
            }
            else if(s.empty()) continue;
            
            else if(num==-1){
                s.erase(s.begin());
            } 
            else s.erase(--s.end());
        }
        
        if(!s.empty()) cout<<*(--s.end())<<' '<<*s.begin()<<'\n';
        else cout<<"EMPTY"<<'\n';
    }
    
}