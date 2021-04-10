// dp[i] : dp[1~10] : 1개
// dp[11~26] : 2개 (20 제외)
// dp[27~] : 1개
// dp[101]
// dp[1] : 1개 dp[11~19] : 2개 dp[111] : dp[1](1,1,1) + dp[11](11,1)
// dp[123] : 
// dp[654523423] = dp[54523423] = 4
// dp[54523423] = dp[4523423]
// dp[4523423] = dp[523423]
// dp[523423] = dp[23423]
// dp[23423] = dp[3423] + dp[423]
// dp[3423] = dp[423]
// dp[423] = dp[23]
// dp[23] = 2
// 시간 초과
class Solution {
    unordered_map<string,int> dp = {{"1",1},{"2",1},{"3",1},{"4",1},{"5",1},{"6",1},{"7",1},{"8",1},{"9",1},{"10",1},{"11",2},{"12",2},{"13",2},{"14",2},{"15",2},{"16",2},{"17",2},{"18",2},{"19",2},{"20",1},{"21",2},{"22",2},{"23",2},{"24",2},{"25",2},{"26",2}};
public:
    int numDecodings(string s) {
        if(dp[s]) return dp[s];
        if(s[0]=='0') return 0;
        string st = "";
        st+=s[0];
        st+=s[1];
        if(dp[st]) return numDecodings(s.substr(1,s.size()-1)) + numDecodings(s.substr(2,s.size()-1));
        // if(s[0]=='2')
        // cout<<s.substr(1,s.size()-1);
        return numDecodings(s.substr(1,s.size()-1));
    }
};

