// 순환이 존재하면 false 해주면 되는 건가..
// 모든 코스를 돌 수 있어야 함.
// 그럼 순환은 어떻게 찾느냐..
// bool vis[100000];
// 아니 numCourses 는 왜 준거임?
// [a,b] a 를 수강하려면 b를 수강해야함
// "유향 그래프에서 순환 찾기"
// 위상정렬이 머임;;?
// ㅇㅋ 배워왔음
class Solution {
public:
// bfs
    bool canFinish(int numCourses, vector<vector<int>>& ve) {
        vector<int> graph[numCourses]; // ve 를 그래프로 만듦.
        unordered_map<int,int> ind;
        vector<int> v1;
        queue<int> q;
        for(auto cur : ve){
            graph[cur[1]].push_back(cur[0]);
            ind[cur[0]]++;
        }
        
        for(int i=0; i<numCourses; i++)
            if(ind[i]==0)
                q.push(i); // indegree==0 인 index 를 저장함.
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            v1.push_back(cur);
            for(auto nxt : graph[cur]){
                ind[nxt]--;
                if(!ind[nxt]) q.push(nxt);
            }
        }
        return v1.size()==numCourses || !ve.size();
        
    }
};