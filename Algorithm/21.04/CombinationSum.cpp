class Solution {
vector<vector<int>> ret;
public:
    // 합이 target이 되도록 중복 OK
    // 생각나는 건.. 백트랙킹?
    // 백트랙킹이나 재귀나..
    // 중복값을 어떻게 없애지?
    void bt(vector<int>ve, int tar, vector<int>& candi, int ba){
        if(tar==0){
            ret.push_back(ve);
            return;
        } else if (tar<0) return ;
        else{
            for(int k : candi){
                if(tar >= k && k>=ba) {
                    ve.push_back(k);
                    bt(ve, tar-k, candi,k);
                    ve.pop_back();
                }
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ve;
        bt(ve, target, candidates,0);
        return ret;
    }
};