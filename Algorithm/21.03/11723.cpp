// BOJ 11723. 집합
#include<bits/stdc++.h>
using namespace std;
set<int> S;

void add(int x){
    S.insert(x);
}
void remove(int x){
    S.erase(x);
}
int check(int x){
    if(S.find(x)==S.end()) return 0;
    return 1;
}
void toggle(int x){
    if(S.find(x)==S.end()){
        S.insert(x);
    } else S.erase(x);
}
void all(){
    S = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
}
void empty(){
    S.clear();
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int N;
    cin>>N;
    while(N--){
        string cmd; int x;
        cin>>cmd;
        if(cmd=="add"){
            cin>>x;
            add(x);            
        }
        else if(cmd=="remove"){
            cin>>x;
            remove(x);
        }
        else if(cmd=="check"){
            cin>>x;
            cout<<check(x)<<'\n';
        }
        else if(cmd=="all"){
            all();
        }
        else if(cmd=="toggle"){
            cin>>x;
            toggle(x);
        }
        else{
            empty();
        }
    }
}