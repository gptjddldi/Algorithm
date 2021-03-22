// BOJ 9935. 문자열 폭발
#include <bits/stdc++.h>
using namespace std;
string s1, bomb;
string sol(string s, string bomb){
    if (s.length() == 0) return "FRULA";
    int st=0;
    while(st<=s.size()){
        if(s.substr(st, bomb.size()) == bomb){
            return sol(s.substr(0, st)+s.substr(st+bomb.size(), s.size()), bomb);
        }
        st++;
    }
    return s;
}
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    cin>>s1>>bomb;
    // cout<<sol(s1,bomb);
    // cout<<s1.substr(0,3) + s1.substr(4,s1.length()+5);
    stack<string> st;
    st.push(s1);
    while(!st.empty()){
        string cur = st.top();
        int cnt = 0;
        st.pop();
        while(cnt<=cur.size()){
            if(cur.substr(cnt,bomb.size())==bomb){
                
            }
        }
    }
    cout<<"FRULA";
}