// BOJ 1613. 역사
#include <bits/stdc++.h>
using namespace std;
int n, k, s;
bool his[401][401];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for (int i = 0; i < k; i++)
    {
        int a,b;
        cin>>a>>b;
        his[a][b] = 1;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(his[i][k] && his[k][j]) his[i][j]=1;
            }
            
        }
    }
    cin>>s;
    while(s--){
        int a,b;
        cin>>a>>b;
        if(his[a][b]) cout<<-1;
        else if(his[b][a]) cout<<1;
        else cout<<0;
        cout<<'\n';
    }
}