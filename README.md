# Algorithm

##### 알고리즘 문제를 풀면서 나오는 자료구조, 알고리즘을 정리하겠다.


### 1. Stack, Queue

### 2.


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
  cint>>v>>e;
  for(int i=0; i<e; i++){
    int u, v;
    cin >> u >> v;
    adj[i].push_back(v);
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

연결 그래프에서의 순회 (DFS)
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

연결 그래프에서의 순회 (BFS)
```

```