class Solution {
    // ret 각각의 i번째 원소 첫번째 단어에 대해 anagram 이면 ret[i].append() 해서 넣는다.
    // 시간복잡도? 100! * n ㄷㄷㄷㄷㄷㄷㄷ
    // 아니면 다른 방법이 뭐가 있어;;
    // 일단 그럼 anagram 을 구하는 시간을 최적화하는 게..
    // t[i] 
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> mp;
        for (string st : strs){
            string t = st;
            sort(t.begin(), t.end());
            mp[t].push_back(st);
        }
        for(auto p : mp){
            ret.push_back(p.second);
        }
        return ret;
    }
};