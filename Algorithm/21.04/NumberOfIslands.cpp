// bfs or dfs
class Solution {
bool vis[301][301];
int dirR[4] = {0,1,0,-1};
int dirC[4] = {1,0,-1,0};
    public:
    int numIslands(vector<vector<char>>& grid) {

        int ret = 0;
        int M = grid.size(), N = grid[0].size();
        for(int r = 0; r<M; r++){
            for(int c = 0; c<N; c++){
                if(vis[r][c]) continue;
                if(grid[r][c]=='0') continue;
                queue<pair<int,int>> q;
                q.push({r,c});
                while(!q.empty()){
                    int curR = q.front().first, curC = q.front().second;
                    q.pop();
                    for(int d=0; d<4; d++){
                        int nr = dirR[d] + curR, nc = dirC[d] + curC;
                        if(nr<0 || nr>=M || nc<0 || nc>=N) continue;
                        if(vis[nr][nc] || grid[nr][nc]=='0') continue;
                        vis[nr][nc] = true;
                        q.push({nr,nc});
                    }
                } ret++;
            }
        }
        return ret;
    }
};