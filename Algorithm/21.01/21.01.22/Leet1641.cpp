// LeetCode 1641. Count Sorted Vowel Strings

#include <bits/stdc++.h>
using namespace std;

    int dp[51][5] = {0,};
    int countVowelStrings(int n) {
        dp[1][0] = 5, dp[1][1] = 4, dp[1][2] = 3, dp[1][3] = 2, dp[1][4] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i][4] = 1;
            for (int j = 3; j > -1; j--) dp[i][j] = dp[i-1][j] + dp[i][j+1];
        }
        return dp[n][0];    
    }


unordered_map<char, int> um = {{'a',1}, {'e',2}, {'i', 3}, {'o', 4}, {'u', 5}};
unordered_map<int, char> um1 = {{1,'a'}, {2,'e'}, {3,'i'}, {4,'o'}, {5,'u'}};

    int count(int n, char ch){
        // 길이 n의 string에서 첫 번째 ch 뒤에 올 수 있는 vowl 의 경우의 수
        // ex) count(2, 'a') -> count(1, ' ')
        // count(3, 'e') = count(2,'e') + count(2,'i') + count(2, 'o') + count(2, 'u') 
        if(n==2){
            return 6-um[ch];
            // return find(um1.begin(), um1.end(), ch) - um1.begin();
            // ch 에 해당하는 값 리턴
        }
        // for(i = ch에 해당하는 값 ~ 마지막 값) res += count(n-1,i)  return res;
        // int begin = find(vowl.begin(), vowl.end(), ch) - vowl.begin();
        // for(begin; begin<vowl.size(); begin++)
        int res = 0;
        for(int i=um[ch];i<=5;i++){
            res += count(n-1, um1[i]);
        }
        return res;
    }
    int countVowelStrings(int n) {
        return count(n+1,'a');
    }