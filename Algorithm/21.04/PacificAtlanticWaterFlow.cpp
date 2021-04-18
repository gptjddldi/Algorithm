// 태평양, 대서양 모두 갈 수 있는 index (r,c)
// dp 가 떠오르는 건..
// 만약 i,j 에서 갈 수 있다고 하자. matrix[r1][c1] >= matrix[i][j] 이고 r1,c1 에서 i,j를 갈 수 있다면 r1,c1 에서도 갈 수 있지.
// bfs 로 갈 수 있는 위치들을 탐색 -> dp[i][j]=true 면 해당 점 true 아니라면 계속 감
// 가다가 태평양, 대서양 모두 마주치면 dp[][] = true 로 바꿈
// 근데 이게 dp 인가? 아니군

// 잘 안풀리네
// 다른 방법은? 거꾸로 하는거야
//움직이지 않고 태평양에 갈 수 있는애들, 대서양에 갈 수 있는 애들은 첨에 알 수 있음
// 그럼 얘내부터 시작해서 dfs든 뭐든 조져서 흘러 올라가는 거야
// 그렇게 두개 다 흘러 올라간 뒤 행렬 전체를 순회하면서 출력하면 됨
// 괜찮은듯?
class Solution {
    int N, M;
    int dirR[4] = {1,0,-1,0};
    int dirC[4] = {0,1,0,-1};
private:
    void dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<bool>>& vis){
        vis[r][c] = true;
        for(int d=0; d<4; d++){
            int nr = r + dirR[d], nc = c + dirC[d];
            if(nr<0 || nr>=N || nc<0 || nc>=M || vis[nr][nc]) continue;
            if(matrix[nr][nc] < matrix[r][c]) continue;
            // vis[nr][nc] = true;
            dfs(nr,nc, matrix, vis);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ret;
        vector<vector<bool>>canP(201, vector<bool>(201));
        vector<vector<bool>>canA(201, vector<bool>(201));

        N = matrix.size(), M = matrix[0].size(); // N : 행 개수, M: 열 개수

        for(int r=0; r<N; r++){
            dfs(r, 0, matrix, canP);
            dfs(r, M-1, matrix, canA);
        }
        for(int c=0; c<M; c++){
            dfs(0, c, matrix, canP);
            dfs(N-1, c, matrix, canA);
        }

        for(int r=0; r<N; r++)
            for(int c=0; c<M; c++)
                if(canP[r][c] && canA[r][c])
                    ret.push_back({r,c});
        return ret;
    }
};