// LeetCode 812. Largest Trangle Area
#include <bits/stdc++.h>

using namespace std;

double largestTrangleArea(vector<vector<int>>& points){
    double res = 0;
    for(auto &a: points){
        for(auto &b: points){
            for(auto &c: points){
                res = max(res, 0.5 * abs((a[0] * (b[1]-c[1]))+ (b[0] * (c[1]-a[1]))+ (c[0] * (a[1]-b[1]))));
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout<<largestTrangleArea(points);
}