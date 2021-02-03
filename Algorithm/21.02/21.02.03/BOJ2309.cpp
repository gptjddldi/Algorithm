// BOJ 2309. 일곱 난쟁이 (back tracking)

#include <bits/stdc++.h>
using namespace std;
int arr[9];
bool vis[9];
bool ans;
int ret, cnt;
void bt(int ret, int idx){
	if(ret ==100 && cnt == 7) {
		ans = true;
		for (int i = 0; i < 9; i++) {
			if(vis[i]) cout<<arr[i]<<'\n';
		}
		return;
	}
	for (int i = idx; i < 9; i++)
	{
		if(!vis[i] && !ans) {
			vis[i] = true;
			ret += arr[i]; cnt++;
			bt(ret, i);
			ret -= arr[i];
			vis[i] = false; cnt--;
		}
	}
	
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 9; i++)
	{
		cin>>arr[i];
	}
	sort(arr, arr+9);
	bt(0,0);

}

// BOJ 2309. 일곱 난쟁이 (for)

#include <bits/stdc++.h>
using namespace std;
int arr[9];
bool vis[9];
bool flag=false;
int sum;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 9; i++)
	{
		cin>>arr[i];
		sum += arr[i];
	}
	sort(arr, arr+9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if((sum - arr[i] - arr[j] == 100) && flag==false){
				vis[i] = true, vis[j] = true;
				flag = true;
			}
		}
	}
	for (int i = 0; i < 9; i++)
		if(!vis[i]) cout<<arr[i]<<'\n';
	

}