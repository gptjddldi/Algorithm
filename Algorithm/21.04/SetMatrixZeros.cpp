// 공간복잡도 O(C) ?
// O(MN) 먼저 생각해보면 M*N 행렬 m1 을 새로 만들어야 함, matrix 를 순회하면서 0이 있는 곳의 m1 행렬을 수정함
// 새로운 행렬을 만들지 않고 기존의 행렬을 바꾸면 복잡해지지 ㅇㅇ
// m+n 은 ? 
// 기존의 행렬을 돌면서 0이 있는 index 를 저장해. 한바퀴 다 돌고 기존 행렬을 바꿔
// 이건 O(m+n) 이 맞아? O(mn) 아님?

// set 2개를 만들어 각각 크기는 m, n 임
// 행렬을 돌면서 0이 있는 row 는 s1 에 col 은 s2 에 저장함
// 다 돌고 s1 s2 에 있는 애들을 써서 행렬 수정함 O(n+m)이지 이게


// 그럼 이제 set 도 쓰지 않고 하는 법은?
// 순회하면서 0이 있는 곳을 뭐 9로 바꿔.
// 다시 돌면서 9가 있는 곳의 행과 열을 0으로 바꿔
// 다시 돌면서 9를 0으로 바꿔
// 이러면 공간복잡도 O(C) 아님?
// 원래 메모리를 적게 쓰려면 시간을 더 써야 하는 법임

// 근데 처음 행렬에 9가 나올 수도 있는데.. 행렬에 나올 수 있는 수는 INT 범위 모든 수네
// 그래서 우리는 어떤 숫자로 flag 를 사용할 순 없네?
// 그럼 이 방법도 안됨


// 힌트를 보고 알았는데 0이 있는 곳의 첫 행과 첫 열을 0으로 바꿔서
// 다음 순회에 다 바꾸면 되는 것이었음 ㅋㅋ
// 그래도 80퍼는 내가 풀얻어..
// 근데 이렇게 하면 안되잖어;
// 첫 행과 첫 열을 0으로 바꾸는 거 ㅇㅋ, 주의할 점은 0으로 만약 [1,0] 이 0으로 되어있다 하면
// 해당 행에 대해서만 수행하고 열에 대해서는 나중에 수행하도록 해야함
// 4 2 1 6
// 0 8 3 2
// 1 2 4 9
// 이렇게 있고 순회하면서 0을 찾아서 행 열 전부를 0으로 바꾸면 대참사가 일어남
// 0 2 1 6
// 0 0 0 0
// 0 2 4 9
// 이 상태가 되는데 순회는 아직 안끝남 ㄷㄷ 결국 [2][0] 을 만났을 때
// 0 2 1 6
// 0 0 0 0
// 0 0 0 0 이렇게 됨
// 그렇기 때문에 우린 r=1, c=1 부터 시작하는 순회를 돌아야 함
// 순회를 다 돌고 마지막에 0번 행괴 0번 열을 바꿔주는 거지.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool r1 = false, c1 = false;
        int N = matrix.size(), M = matrix[0].size(); // N : 행, M : 열
        for(int r=0; r<N; r++){
            for(int c=0; c<M; c++)
                if(matrix[r][c]==0){
                    if (r==0) r1 = true;
                    if (c==0) c1 = true;
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
        }
        for(int r=1; r<N; r++){
            for(int c=1; c<M; c++){
                if(matrix[r][0]==0 || matrix[0][c]==0){
                    matrix[r][c] = 0;
                }
            }
        }
        if(r1)
            for(int c=0; c<M; c++) matrix[0][c] = 0;
        if(c1)
            for(int r=0; r<N; r++) matrix[r][0] = 0;
            
    }
    

};