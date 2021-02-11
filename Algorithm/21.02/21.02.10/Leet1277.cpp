#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ret = 0;

    
    int countSquares(vector<vector<int>>& matrix) {
        for(int r = 0; r < matrix.size() ; r ++){
            for(int c = 0; c < matrix[r].size(); c++){
                // ret += isSquare(matrix, r, c, 0);
                if(matrix[r][c] && r && c) matrix[r][c] += min(min(matrix[r-1][c], matrix[r][c-1]), matrix[r-1][c-1]);
                ret += matrix[r][c];
            }
        }
        return ret;
    }
};