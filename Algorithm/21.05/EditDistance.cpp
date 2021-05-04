// 삽입, 제거, 교체
// 이걸 어케 풂;
// 제거를 먼저하느냐 교체를 먼저 하느냐.
// 우선순위 1. 제거만 해서 word2 를 만들 수 있을 경우.
// 제거가 가장 우선시 되어야 하는가? 아니면
// 아니 근데 순서는 상관이 없긴 한데
// 일단 word1 에서 word2 와 비슷한 Longest 배열? 그런 걸 만들어야 함
// horse, ros 면 [r,s] 또는 [o,s] 가 그 배열이고,
// [r,s] 인 경우 h,o,e 제거, o 삽입 4회 / [o,s] 인 경우 r,e 제거, h->r 교체 3회
// intention, execution [e,t,i,o,n] 이 그 배열이고, i,n,t 중에 1개 삭제, 2개 e,x 교체
// n->c or u 교체 나머지 삽입. 해서 5회임

// 답을 보니 dp 를 사용하래. 어떻게;;? 

// 일단 recursion 을 사용한다면
// 각 반복마다 제거, 교체, 삽입 3가지 경우를 고려하고 이때 복잡도는 O(N^3)
// 이걸 최적화한 결과가 dp가 나온다고 한다..

class Solution {
public:
    int minDistance(string s1, string s2) {
        return rec(s1, s2, 0, 0);
    }
    int rec(string s1, string s2, int i, int j){
        if(s1.length()==i) return s2.length()-j;
        if(s2.length()==j) return s1.length()-i;
        int res;
        if(s1[i] == s2[j]) res = rec(s1, s2, i+1, j+1);
        
        else{
            // insert
            int insert = rec(s1, s2, i, j+1);
            // delete
            int del = rec(s1, s2, i+1, j);
            // replage
            int rep = rec(s1, s2, i+1, j+1);
            res = min({insert, del, rep})+1;
        }
        return res;
    }
};


// dp[i][j] : s1[i], s2[j] 을 보고 있을 때 최솟값, (이때 s1[0~i-1]==s2[0~j-1])
// 아 시발 모르겠다 병신같은 대가리
class Solution {
public:
    int minDistance(string s1, string s2) {
        int sz1 = s1.size(), sz2 = s2.size();
        if(!sz1) return sz2;
        if(!sz2) return sz1;

        int dp[sz1+1][sz2+1];
        for(int i=0; i<=sz1; i++){ // 0 ~ i-1 까지가 0 이랑 같아질려면 i개 삭제해야함.
            dp[i][0] = i;
        }
        for(int i=0; i<=sz2; i++){ // 0 과 0~j-1 까지 같아지려먼 j개 삽입해야함.
            dp[0][i] = i;
        }        
        
        for(int i=0; i<sz1; i++){
            for(int j=0; j<sz2; j++){
                if(s1[i] == s2[j])
                    dp[i+1][j+1] = dp[i][j];
                else{
                    dp[i+1][j+1] = min({
                        dp[i][j+1], dp[i+1][j], dp[i][j]
                    })+1;
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};