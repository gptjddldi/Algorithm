// BOJ 1759. 암호 만들기
#include <bits/stdc++.h>
using namespace std;

int L, C;
char c;
vector<char> res(20);
//char res1[20];
char alp[20];
bool isused[20];
int isvowel;
set<char> vowel = { 'a','e','i','o','u' };
//set<char> vowel;
void bt(int k, int st) {
	if (k == L && isvowel>=1 && isvowel < L-1) {
		for (char c : res) cout << c;
		cout << '\n';
		return;
	}

	for (int i = st; i < C; i++)
	{
		if (!isused[i]) {
			res[k]= alp[i];
			isused[i] = true;
			if (vowel.count(alp[i])) isvowel++;
			bt(k + 1, i);
			isused[i] = false;
			if (vowel.count(alp[i])) isvowel--;

		}
	}


}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> L >> C;
	res.resize(L);
	for (int i = 0; i < C; i++) cin >> alp[i];
	sort(alp, alp + C);
	// for(auto c: alp) cout << c;
	bt(0, 0);
}