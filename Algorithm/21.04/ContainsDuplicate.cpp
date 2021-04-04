#include <bits/stdc++.h>
using namespace std;
// 생각 : n 의 갯수가 10^5 이고, n 개의 아이템을 set 에 넣을 때 시간 O(NlogN) 이므로 10만 ~ 정도이므로 시간이 충분하다고 생각함.
 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for(int num : nums) st.insert(num);
        return nums.size() != st.size();
    }
};
// O(N) 으로 풀 수 있는 방법은? vis[20억] 을 설정해서 vis[i] == true 이라면 true 리턴.. 근데 vis[20억]은 메모리를 많이 쓸 것 같은데?
// unordered map 을 사용하면 ? 굿
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> vis;
        for(int num : nums) {
            if (vis[num]) return true;
            else vis[num] = true;
        }
        return false;
    }
};