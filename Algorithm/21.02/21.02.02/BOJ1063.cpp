// BOJ 1063. 킹

#include <bits/stdc++.h>
using namespace std;
// int dx[4] = {1,0,-1,0};
unordered_map<string, pair<int,int>> mv;
// mv[string] = {x,y}
string K,S;
int N;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	mv["R"] = {1,0}, mv["L"] = {-1,0}, mv["B"] = {0,-1}, mv["T"] = {0,1};
	mv["RT"] = {1,1}, mv["LT"] = {-1,1}, mv["RB"] = {1,-1}, mv["LB"] = {-1,-1};
	cin >> K >> S >> N;
	string dir;
	while(N--){
		char kx = K[0], sx = S[0];
		int ky = K[1], sy = S[1];
		cin>>dir;
		int nX = mv[dir].first, nY = mv[dir].second;
		kx += nX, ky += nY;
		if(kx == sx && ky == sy) {sx += nX; sy += nY;}

		if(kx < 'A' || kx > 'H' || sx < 'A' || sx > 'H' || ky < '1' || ky > '8' || sy < '1' || sy > '8' ) {
			// cout<<"kx: "<<kx<<"ky: "<<ky<<endl;
			continue;
		}
		K[0] = kx, S[0] = sx, K[1] = ky, S[1] = sy;
	}
	cout<<K<<'\n'<<S;
	// int k = (int)'8';
	// bool is = k+1 == 'A'+1;
	// cout<<is;
}