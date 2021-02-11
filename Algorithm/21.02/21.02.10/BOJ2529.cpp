// BOJ 2529. 부등호
// backtracking brtue force

#include <bits/stdc++.h>
using namespace std;
vector<char> ch;
vector<vector<int>> res;
bool used[10];
int N;
//string ret = "0";

vector<int> ret;
void bt(int idx, int prev) {
	if (idx == N) {
        // int ans = 0;
		// for(int c: ret) {
        //      ans*=10;
        //      ans += c;
        // }
        res.push_back(ret);

        return ;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (used[i]) continue;
		if (ch[idx] == '<' && i > prev) {
			used[i] = true;
			// ret[cur+1] = i
			ret.push_back(i);
			bt(idx + 1, i);
			used[i] = false;
			ret.pop_back();
		}
		if (ch[idx] == '>' && i < prev) {
			used[i] = true;
			ret.push_back(i);
			bt(idx + 1, i);
			used[i] = false;
			ret.pop_back();
		}
	}

}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char k;
		cin >> k;
		ch.push_back(k);
	}
    for(int i=0; i<=9; i++){
        
        used[i] = true;
        ret.push_back(i);
        bt(0, i);
        ret.clear();
        used[i] = false;
        memset(used, 0, 10);
    }
    // if(res.front() < 100 && res.back() >= 100)
    //     cout<<0<<res.front()<<'\n'<<res.back();
    // if(res.front() < 100 && res.back() < 100)
    //     cout<<0<<res.front()<<'\n'<<0<<res.back();
    // if(res.front() >= 100 && res.back() >= 100)
    //     cout<<res.front()<<'\n'<<res.back();
    // if(res.front() >= 100 && res.back() < 100)
    //     cout<<res.front()<<'\n'<<0<<res.back();
    for(auto c: res.back()) cout<<c;
    cout<<'\n';

    for(auto c: res.front()) cout <<c;

}