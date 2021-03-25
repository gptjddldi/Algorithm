// BOJ 11403. 경로 찾기
#include <bits/stdc++.h>
using namespace std;
int N;
bool dis[104][104];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin>>dis[i][j];
        }   
    }
    
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if(dis[i][k] && dis[k][j]) dis[i][j]=1;
            }
            
        }
        
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout<<dis[i][j]<<' ';
        }   
        cout<<'\n';
    }
}