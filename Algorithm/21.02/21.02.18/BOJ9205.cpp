// BOJ 9205. 맥주 마시면서 걸어가기
#include <bits/stdc++.h>
using namespace std;
int t, n, sr, sc, er, ec;
vector<pair<pair<int,int>,bool>> conv;

int dist(int r1, int r2, int c1, int c2){
    return abs(r1-r2) + abs(c1-c2);
}

bool bfs(int r, int c){
    queue<pair<int,int>> q;
    q.push({r,c});

    while(!q.empty()){
        int curR = q.front().first, curC = q.front().second;
        q.pop()
        if(dist(curR,er,curC,ec)<=1000) return true;
        for(auto nxt: conv){
            int nxtR = nxt.first, nxtC = nxt.second;
            if(nxt.second.first)
            if(dist(curR,nxtR,curC,nxtC)<=1000){
                q.push({nxtR, nxtC});
            }
        }
    }
    return false;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>sr>>sc;
        for (int i = 0; i < n; i++)
        {
            int r,c;
            cin>>r>>c;
            conv.push_back({{r,c},false});
        }
        cin>>er>>ec;
        if(bfs(sr,sc)) cout<<'happy'
        else cout<<'sad';

        cout<<'\n';
        conv.resize(0);
    }
}