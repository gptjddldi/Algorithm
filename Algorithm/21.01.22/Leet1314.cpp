// LeetCode 1314. Matrix Bolck Sum

#include <bits/stdc++.h>
using namespace std;

int sizeX, sizeY;
int posible(int i, int j, vector<vector<int>>&sum){
    if(i<0 || j<0) return 0;
    if(i>=sizeX) i = sizeX-1;
    if(j>=sizeY) j = sizeY-1;
    return sum[i][j];
}
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    sizeX = mat.size();
    sizeY = mat[0].size();

    vector<vector<int>> sum(sizeX, vector<int>(sizeY, 0));
    for (int i = 0; i < sizeX; i++){
        for (int j = 0; j < sizeY; j++){
            sum[i][j] = mat[i][j] + posible(i-1,j,sum) + posible(i,j-1,sum) - posible(i-1, j-1, sum);
        }
    }

    vector<vector<int>> res(sizeX, vector<int>(sizeY, 0));
    for (int i = 0; i < sizeX; i++)
    {
        for (int j = 0; j < sizeY; j++)
        {
            res[i][j] = posible(i+k, j+k, sum) - posible(i-k-1, j+k, sum) - posible(i+k,j-k-1,sum) + posible(i-k-1, j-k-1, sum);
        }
        
    }
    return res;
    
}

int main() {
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    for(auto c: matrixBlockSum(mat, 1)) cout<<c[0];
}


