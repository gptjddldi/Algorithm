// BOJ 10815. 숫자 카드


// Without Binary Search 43244KB, 524ms

// #include <bits/stdc++.h>
// using namespace std;
// int N, M;
// vector<int> v;
// unordered_set<int> s;
// int main(){
// 	cin.tie(0);
// 	ios::sync_with_stdio(0);
// 	cin >>N;
// 	int k;
// 	while(N--){
// 		cin>>k;
// 		s.insert(k);
// 	}
// 	cin >> M;
// 	while(M--){
// 		cin>>k;
// 		int size = s.size();
// 		s.insert(k);
// 		if(s.size() == size) v.push_back(1);
// 		else v.push_back(0);
// 	}
// 	for(int c: v) cout<<c<<' ';
// }

// With Binary Search 8288KB, 228ms
#include<bits/stdc++.h>
using namespace std;

int N,M;
vector<int> v, res;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N;
    int k;
    while(N--){
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    cin>>M;
    while(M--){
        cin>>k;
        res.push_back(binary_search(v.begin(), v.end(), k));
    }
    for(int c: res) cout<<c<<' ';
}