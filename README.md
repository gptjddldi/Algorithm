# Algorithm

##### 알고리즘 문제를 풀면서 나오는 자료구조, 알고리즘을 정리하겠다.

### stringstream (leet 824)
- istringstream
  ```
  //  문자열 format 을 parsing 할 때 사용

  string cmd;
  istringstream S("123 421 hello kkk 54");
  while(S>>cmd){
      cout<<cmd<<'\n';
  }
  
  -> 123
  421
  hello
  kkk
  54
  ```

- ostringstream
    ```
    // 문자열 format 을 조합하여 저장

    string cmd = "test_string";
    int data = 12;
    ostringstream oss;

    oss << "test "<< data << cmd;
    cout << oss.string();
    ```

### Three Point Triangle Area

  ```
  A(x1,y1) B(x2,y2) C(x3,y3)
  S = 1/2|(x1(y2-y3) + x2(y3-y1) + x3(y1-y2))|
  ```

### Integral Image (leet 1314)
모르겠다 설명조차도 ㅋㅋㅠㅠ dp 사용?
```
https://jangjy.tistory.com/32
```

### DP(Dynamic Programming)

문제를 해결하기 위한 점화식을 찾아낸 후 점화식의 첫째 항부터 차례로 구해나가는 것이다.

- BOJ 1463
- Leec 1027
- BOJ 1149
- BOJ 2579

### Prefix Sum (구간 합)

```
int arr[10] = {0, 2, 3, 4, 5, 6, 7, 8, 9} 배열이 존재한다.

이때 a에서 b의 구간 합을 요구하는 쿼리 2천만개가 들어온다.

이러한 문제에 대해 어떻게 해결 할 것인가?
```

```
일반 풀이

#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[10] = { 0,1,2,3,4,5,6,7,8,9 }
  int N;
  cin>>N;
  for(int i = 0; i< N; i++){
    int a, b;
    cin>>a>>b;
    int sum = 0;
    for(int j = a; j <= b; j++)
      sum += arr[j];
    cout << sum;
  }
}

-> 배열의 길이가 n 이면 복잡도 O(n^2)
```

```
//Prefix Sum Alogirthm

#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[10] = { 0,1,2,3,4,5,6,7,8,9 }
  int sum[10] = {0,}
  int N;
  cin>>N;
 for (int i = 0; i < 10; i++)
  {
    if (i == 0)
      sum[i] = arr[i];
  else
      sum[i] = sum[i - 1] + arr[i];
  }
for(int i = 0; i< N; i++){
    int a, b;
    cin>>a>>b;
    int sum = 0;

    cout << sum[b]-sum[a-1];
  }
}
-> 복잡도 O(n)
```

### std::map

  - 중복을 허용하지 않는 (key,value) 쌍으로 이루어진 hash map

### Brute Force

1. 선형 구조로 구조화
2. 구조화된 문제공간을 적절한 방법으로 해를 구정할 때까지 탐색

```
ex) 10의 약수의 합 구하기

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} // 구조화
int sum = 0;
for(int i: arr)
  if(10%i==0) sum+=i;
```

### Binary Search

  - "정렬"되어있는 배열에서 특정 데이터를 찾기 위해 탐색 범위를 절반으로 줄여가며 찾는 탐색방법
  - 술게임 소주 뚜껑에 있는 숫자 맞추기라고 생각하면 됨!
  ```
  int binarySearch(int target, int len){
	int st = 0;
	int end = v.size();
	while(true) {
	int mid = (st+end) / 2;
	if(target > v[mid]) st = mid+1; 
	else if(target<v[mid]) end = mid-1;
	else return 1;
	if (end<st) return 0;
	}
}

// 또는

int binarySearch(int st, int end, int val){
	if(end>=st) {
		int mid = (st+end) / 2;
		if(v[mid] == val) return 1;
		else if(v[mid] > val) return binarySearch(st, mid-1, val);
		else if (v[mid] < val) return binarySearch(mid+1, end, val);
	}
	return 0;
}
  ```

### Graph
  - 간선(Edge)과 정점(Node)으로 이루어진 자료구조
  - 구현방법 : 인접 행렬, 인접 리스트

인접 리스트 방식은 정점이 많고 간선이 상대적으로 적을 때 사용.
대부분 인접 리스트 방식을 이용해 구현한다.
```
입력:
5 7
3 1
2 3
4 1
5 2
5 4
3 5
2 5
```
 구현 1. Adjacency Matrix (directed)
```
int adj_mat[10][10];
int v,e;
cin>>v>>e; // v: 정점, e: 간선
for(int i=0; i<e; i++) {
  int u, v;
  cin>>u >> v;
  adj_mat[u][v] = 1;
}
```

 구현 2. Adjacency List (directed)
```
  // with STL
  vector<int> adj[10];
  int v, e;
  cin>>v>>e;
  for(int i=0; i<e; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  // without STL
  int edge[10][10];
  int deg[10] // 각 정점의 outdegree
  int* adj[10];
  int idx[10]; // ajd[i]에서 새로운 정점을 추가할 때의 위치
  int main() {
    int v, e;
    cin >> v >> e;
    for(int i=0; i< e; i++){
      cin >> edge[i][0] >> edge[i][1];
      deg[edge[i][0]] ++;
    }
    for(int i=0; i <= v; i++)
      adj[i] = new int[deg[i] + 1];
    for(int i=0; i< e; i++){
      int u = edge[i][0], v = edge[i][1];
      adj[u][idx[u]] = v;
      idx[u]++;
    }
    
  }
```

연결 그래프에서의 순회 (BFS)
```
vector <int> ajj[10];
bool vis[10];
void bfs() {
  queue<int> q;
  q.push(1); // 시작 위치
  vis[1] = true;
  wihle(!q.empty()){
    int cur = q.front();
    q.pop()
    cout<< cur << ' ';
    for(auto nxt: adj[cur]){
      if(vis[nxt]) continue;
      q.push(nxt);
      vis[nxt] = true;
    }
  }
}
```

연결 그래프에서의 순회 (DFS, 비재귀)
```
vector<int> adj[10];
bool vis[10];
void dfs() {
  stack<int> s;
  s.push(1);
  vis[1] = true;
  while(!s.empty()) {
    int cur = s.top();
    s.pop()
    cout << cur << ' ';
    for(int i= 0; i < adj[cur].size(); i++) {
      int nxt = adj[cur][i];
      if(vis[nxt]) continue;
      s.push(nxt);
      vis[nxt] = true;
    }
  }
}
```

연결 그래프에서의 순회 (DFS, 재귀)
```
vector<int> adj[10];
bool vis[10];
void dfs(int cur) {
  cout<< cur <<' ' ;
  for(int i= 0; i < adj[cur].size(); i++) {
    int nxt = adj[cur][i];
    if(vis[nxt]) continue;
    vis[nxt] = true;
    dfs(nxt);
  }
}
```

### BackTracking
 
 - 현재 상태에서 가능한 모든 후보군을 탐색하는 알고리즘

```
// k : 현 위치, m : end point
void func(int k) {
  if(k==m) {
    for (int i = 0; i < m; i++)
	{
		cout<<arr[i]<<' ';
		cout<< '\n';
		return ;
	}
  }
  for (int i = 1; i <= n; i++)
  {
	  if(isused[i]) {
		  arr[k] = i;
		  isused[i] = 1;
		  func(k-1);
		  isused[i]=0
	  }
  }
  
}
```

### 소수 찾기 (Sieve of Eratosthenes)

에라토스테네스의 체 : 1 부터 N 까지의 자연수 중 모든 소수를 찾는 알고리즘

- 길이 N+1 의 배열을 만든다 bool arr[N+1]
- 2 부터 시작해 arr[i] 가 false 라면 i 의 배수는 모두 true
- N+1 까지 탐색한 뒤 arr[i] = false 인 i 를 리턴하면 된다.
```
int N = 100;
bool arr[N+1]; arr[1] = 1
for(int i=2; i<=N; i++){
  if(!arr[i])
    for(int j=2*i i*j <=N; j+=i)
      arr[j] = 1;
}
int sol(int x){
    notPrime[1] = true;
    for (int i = 2; i*i <= 1500000; i++)
    {
        if(notPrime[i]) continue;
        for (int j = i*i; j <= 1500000; j+=i)
        {
            notPrime[j] = true;
        }
    }
```

### 사전순 순열 (Lexicographical Permutation)

[Lexicographical permutation](https://www.nayuki.io/page/next-lexicographical-permutation-algorithm)

  1. 가장 긴 증가하지 않는 배열의 최대 인덱스 찾기
  (arr[i-1] < arr[i]) 
  2. i 이상의 인덱스에서 arr[j] >= arr[i-1] 을 만족하는 가장 큰 j 찾기
  3. swap arr[j], arr[i-1]
  4. arr[i] 로 시작하는 배열을 반대로 하기.

  ```
  arr = [0, 1, 2, 5, 3, 3, 0]
  1. i = 3 (arr[3] = 5, arr[2] = 2)
  2. j = 5 (arr[j] = 3)
  3. swap arr[5], arr[2] => arr = [0, 1, 3, 5, 3 ,2, 0]
  4. arr = [0, 1, 3, 0, 2, 3, 5] : next permutation of arr
  ```

### LIS (Longest Increasing Subsequence)

  1. 기존의 dp 를 이용한 O(n^2)
  2. 이분탐색을 이용한 O(NlgN) 
  [최적화된 LIS](https://jins-dev.tistory.com/entry/최적화된-LISLongest-Increasing-Subsequence-알고리즘과-해-찾기)

```
int findLIS(int n){
    for(int i=0; i<n; i++){
        if(i==0 || A[i] > lis[lisCnt-1]){
            trace[A[i]] = lisCnt;
            lis[lisCnt++] = A[i];
        } else{
            int start = 0, end = lisCnt;
            int idx = lisCnt;
            while(start<end){
                int mid = (start+end) / 2;
                if(lis[mid] >= A[i]) {
                    idx = min(idx, mid);
                    end = mid;
                } else {
                    start = mid+1;
                }
            }
            lis[idx] = A[i];
            trace[A[i]] = idx;
        }
    }
    // trace 배열에서 가장 나중을 꺼내면 됨
    int cur = lisCnt-1;
    for(int i= n-1; i>=0; i--){
        if(trace[A[i]] == cur) {
            lis[cur] = A[i];
            cur--;
        }
    }
    return lisCnt;
}
```

### Bit Masking (비트 마스킹)

  - BOJ 2098. 외판원 순회

  N 이 작을 때 dp로 풀 수 있음
  dp[i][j] 현재 i 위치에 있고 j 에 속한 마을들을 방문한 상태
  j 에는 여러 마을이 속해야 하는데 기존 dp 로는 이를 구현할 수 없음.
  
  => Bit Mask 도입

 마을이 N 개일 때 N 비트 정수를 사용해 방문한 마을은 1, 방문하지 않은 마을은 0으로 표현할 수 있다.

 ex) 마을이 4개일 때 0000(2) ~ 1111(2) 로 표현가능

 주어진 상태에서
 1. i 번 비트가 0인지 1인지 확인
 2. i 번 비트를 1로 바꾸기
 3. i 번 비트를 0으로 바꾸기
 
 3가지 연산이 가능함

 ```  
 int TSP(int current, int visited) {
    int& ret = dp[current][visited];
    if (ret != -1) return ret;
    // base case : 모든 마을을 방문했을 때
    if(visited == (1<<N)-1){
        if(W[current][0]!=0) return W[current][0];
        return IMPOSSIBLE;
    }
    ret = IMPOSSIBLE;
    for (int i = 0; i < N; i++)
    {
        // i 번 마을을 이미 방문했거나 해당 마을로 갈 수 없는 경우
        if(visited & (1<<i) || W[current][i]==0) continue;
        // 그 외
        ret = min(ret, TSP(i, visited | (1<<i)) + W[current][i]);
    }
    return ret;
}
 ```

### Priority Queue (최대힙, 최소힙)

- 최대힙
```
int heap[100002];
int sz = 0;

void add(int x){
    sz++;
    heap[sz] = x;
    int idx = sz;
    while(idx!=1){
        int par = idx/2;
        if(heap[par]>heap[idx]) break;
        swap(heap[par], heap[idx]);
        idx = par;
    }
}

int top() {
    if (sz==0) return 0;
    return heap[1];
}

void pop() {
    if(sz==0) return;
    swap(heap[1], heap[sz]);
    sz--;
    int idx = 1;
    while(idx*2 <= sz){
        int min_child;
        if(heap[idx*2] > heap[idx*2+1] || idx*2+1>sz) min_child=idx*2;
        else min_child = idx*2+1;
        if(heap[idx] > heap[min_child]) break;
        swap(heap[idx], heap[min_child]);
        idx = min_child;
    }

}
```

### Dijkstra's Algorithm (다익스트라 알고리즘)

> - 한 정점에서 나머지 정점들까지의 최단거리를 구하는 알고리즘

> - 정점의 개수 V, 간선의 개수 E 일 때 시간복잡도 O(ElogV)

#### 방식
  1. 아직 방문하지 않은 정점들 중 거리가 가장 짧은 정점을 하나 선택해 방문한다
  2. 해당 정점에서 인접하고 아직 방문하지 않은 정점들의 거리를 갱신한다.

그럼 어떻게 매 반복마다 가장 짧은 정점을 선택하지? '최소힙' 이용

```
using pii = pair<int, int>;
int v,e,st;
vector<pii> ve[20005];
const int INF = 1e9+10;
int d[20005];
void dijkstra(){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    d[st] = 0;
    pq.push({d[st],st});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int dist = cur.first, idx = cur.second;
        if(d[idx] != dist) continue;
        for(auto nxt: ve[idx]){
            int cost = nxt.first, nidx = nxt.second;
            if(d[nidx] > dist+cost){
                d[nidx] = dist+cost;
                pq.push({d[nidx],nidx});
            }
        }
    }
}
```

### Bellman-Form Algorithm (벨만 포드 알고리즘)

> - 정점의 개수 V, 간선의 개수 E 일 때 시간복잡도 O(VE)
> - Dijkstra Algorithm 과 다르게 가중치가 음수일 때도 사용 가능함

### Floyd-Warshall Algorithm (플로이드 와샬 알고리즘)

> - 시간복잡도 O(V^3)
> - 가중치가 음수일 때도 사용가능
> - 주어진 그래프에서 모든 정점 쌍 사이의 최단거리를 각각 구하는 알고리즘임
```
for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b] = min(c, dis[a][b]);
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
```