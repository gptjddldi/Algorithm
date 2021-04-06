// dict 를 순회하면서 s 를 만들 수 있으면 해당 단어를 제외하고 계속 순회
// wordDict 를 돌면서 돌고돌면서 string 단어 찾기인데 단어들 최대 길이 2만단어
// 이걸 dp 로 어떻게 풀어?
// 해답 봄
// dp[i] : idx i 까지 breakable 하다는 뜻
// 아 그니까 문제가 wordDict 에 있는 단어들을 0개 이상 사용해서 s 를 쪼갤 수 있느냐야
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string ss : wordDict){
            st.insert(ss);
        }
        if(st.size()==0) return false;

        int sz = s.size();
        vector<bool>dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i=1; i<=sz; i++){
            for(int j=0; j<=i; j++){
                if(dp[j]){
                    string word = s.substr(j,i-j);
                    if(st.find(word)!=st.end()){
                        dp[i] = true;
                        break;         
                    }

                }
            }
        }
        return dp[sz];
    }
};