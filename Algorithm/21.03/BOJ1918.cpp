// BOJ 1918. 후위 표기식
#include <bits/stdc++.h>
using namespace std;
stack<char> st;
int pr(char ch){
	if(ch=='(') return 0;
	else if (ch =='+' || ch == '-') return 1;
	else if(ch == '*' || ch == '/') return 2;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	for (int i = 0; i < s.size(); i++)
	{
		char &c = s[i];
		if(c>='A' && c <= 'Z') cout<<c;
		else if(c == '(') st.push(c);
		else if(c == ')') {
			while(st.top()!='('){
				cout<<st.top();
				st.pop();
			} st.pop();
		}
		else{
			while(!st.empty() && pr(c) <= pr(st.top())){
				cout<<st.top(); st.pop();
			}st.push(c);
		}
	}
	
	while(!st.empty()){
		cout<<st.top(); st.pop();
	}
}