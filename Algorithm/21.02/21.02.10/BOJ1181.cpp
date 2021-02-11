// BOJ 1181. 단어정렬

#include <bits/stdc++.h>
using namespace std;
int N;
vector<string> ve;

struct myOrder
{
    bool operator() (const string& s1, const string& s2) const{
        if(s1.size() == s2.size()) return s1<s2;
        return s1.size()<s2.size();
    }
};


set<string , myOrder> st;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    for (int i = 0; i < N; i++){
        string k;
        cin>>k;
        st.insert(k);
    }
    // sort(ve.begin(), ve.end(), comp);
    for(auto c: st) cout<< c<< '\n';
}
