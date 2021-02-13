// BOJ 1620. 나는야 포켓몬 마스터 이다솜

#include <bits/stdc++.h>
using namespace std;
int N, M;
map<string, string> dict, dict2;
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N>>M;
    string p;
    for (int i = 1; i <= N; i++)
    {
        cin>>p;
        dict[p] = to_string(i);
        dict2[to_string(i)] = p;
    }
    for (int i = 0; i < M; i++)
    {
        cin>>p;
        if(dict.find(p) != dict.end()) cout<<dict[p]<<'\n';
        else cout<<dict2[p]<<'\n';
    }
    
    
}


// // BOJ 1620. 나는야 포켓몬 마스터 이다솜

// #include <bits/stdc++.h>
// using namespace std;
// int N, M;
// map<string, int> dict;
// char s[100001][21];
// int main(){
//     cin.tie(0); ios::sync_with_stdio(0);
//     cin>>N>>M;
//     string p;
//     for (int i = 1; i <= N; i++)
//     {
//         cin>>s[i];
//         dict[s[i]] = i;

//     }
//     for (int i = 0; i < M; i++)
//     {
//         int idx = 0;
//         cin>>p;
//         if(p[0] <'A') { // 숫자가 들어올 경우
//             for(int i=0; i<p.length(); i++) idx = idx*10 + p[i]-'0';
//             cout<<s[idx]<<'\n';
//         } else cout<<dict[p]<<'\n';
//     }
    
    
// }