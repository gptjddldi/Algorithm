// LeetCode 1314. Matrix Bolco Sum
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector <int>>&mat, int k){
    vector<vector<int>> res;
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            for(int r = i-k ;r <= i+k; r++){
                for(int c = j-k; c <= j+k; c++){
                    if(r>=0 &&r<=mat.size() && c>=0 && c<=mat[i].size()){
                        res[i][j] += mat[r][c];
                    }
                }
            }
        }   
    }
    return res;
    
}

int main() {
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    for(auto c: matrixBlockSum(mat, 1));
}