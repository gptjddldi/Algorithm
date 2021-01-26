// Leet Code 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

#include<bits/stdc++.h>
using namespace std;

int minPartitions(string s) {
    int maxNum = 0;
    for(char c : s){
        maxNum = max(int(c-'0'), maxNum);
    }
    return maxNum;
}

int main(){
    cout<<minPartitions("82734");
}
