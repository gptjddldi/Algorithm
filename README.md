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