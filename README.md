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

### Greedy
