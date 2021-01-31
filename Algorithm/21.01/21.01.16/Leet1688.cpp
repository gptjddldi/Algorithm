// Leet Code 1688 Count of Matches in Tournament.
#include <bits/stdc++.h>

using namespace std;

int res;

int numberOfMatches(int n) {
    if(n<=1) return res;
    else{
        res += int(n/2);
        return numberOfMatches(int((n+1)/2));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout<<numberOfMatches(7);

}