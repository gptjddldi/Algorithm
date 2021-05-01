// dp 로 풀 수 있나? 푼다면 맨 끝에서 시작하는 게 나을듯?
// if(T[i-1] < T[i]) dp[i-1] = 1;
// if(T[i-1] > T[i]) dp[i-1] = dp[i] (아님)
// 아니 프로그래머스에서는 어떻게 풀었었지;
// vector<int> ret : 길이 T 와 같음, 전부 0
// for(int i=0; i<ret.size();i++)
// if(i==0)
// dp 로는 못 풀고 맨 끝에서 시작하는 건 맞음
// 맨 끝에서 시작하면서 다른 배열에는 Longest Increasing Number 을 넣어주면 된대(옛날에 풀었던 문제 LTS  알고리즘이었나..)
// 해보자..
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int r = T.size()-1;
        vector<int> ret(T.size(),0);
        stack<pair<int,int>> st; // <온도, 날>
        for(int i=r; i>=0; i--){
            if(!st.size()) st.push({T[i],0});
            else{
                int cnt=1;
                while(!st.empty() && st.top().first<=T[i]){
                    cnt+=st.top().second; // 왜 걍 ++ 가 아니고 저걸 더해주지? 다음 큰 칸으로 가는 길이 항상 1은 아니기 때문이네..
                    st.pop();
                }
                if(st.empty()){
                    st.push({T[i],0});
                }
                else{
                st.push({T[i],cnt});
                ret[i] = cnt;
                }
            }
        }
        return ret;
    }
};