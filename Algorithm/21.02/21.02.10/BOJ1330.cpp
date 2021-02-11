// BOJ 1330. 단어 수학
// 항상 자릿수가 가장 큰 단어부터 9 8 7 6 5 4 3 2 1 0 을 넣어줌
// 자릿수가 같은 단어면 그 단어가 또 쓰인다면 그 단어에 큰 value 를 넣어줌.
#include <bits/stdc++.h>
using namespace std;

int value[26];
// map<char, int> cnt;
int cnt[26];
int N, ret;

bool comp(int s1, int s2){
    if(s1 > s2) return true;
    return false;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>N;
    string word[N];
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin>>tmp;
        reverse(tmp.begin(), tmp.end());
        int wei = 1;
        for(char ch: tmp){
            cnt[ch-65] += wei;
            wei *= 10;
        }
    }
    // for(string c: word){
    //     int wei = 1;
    //     for(char ch: c){
    //         cnt[ch-65] += wei;
    //          wei *= 10;
    //     }
    // }
    // sort(word, word+N, comp);
    sort(cnt, cnt+26, comp);
    for(int i=9; i>=0; i--){
        ret += i * cnt[9-i];
    }
    cout << ret;
    // for(int i=0; i<26; i++) cout<<char(i+65)<<":"<<cnt[i]<<',';
    // for(auto c: cnt) 
}