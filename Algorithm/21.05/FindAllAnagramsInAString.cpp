// anagrams O(N) 으로 풀 수 있나?
// 어떤 배열? 해시맵? 을 만들어서 하나씩 넣어.. 길이가 p.length() 가 되면
// anagrams 인지 확인하고, 맞으면 현재 idx - p.length() 를 ve 에 넣어
// 그담엔 해당 인덱스에 위치한 원소 삭제.. 그 담으로 넘어가고
// 만약 다음 원소가 p 에 속하지 않았다면 ? 배열 비우고 다음 원소로 넘어가
// multiset 에 넣으면 어때
// 이런식인데
// 잘 안돼서 답봄
// 슬라이딩 윈도우..
// 뭐 생각은 어느정도 비슷했더..
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ve;
        vector<int> v1(26,0), v2(26,0);
        if(s.size()<p.size()) return ve;
        for(int i=0; i<p.size(); i++) {
            v1[s[i]-'a']++;
            v2[p[i]-'a']++;
        }
        if(v1==v2) ve.push_back(0);
        for(int j = p.size(), i=0; j<s.size(); i++, j++){
            v1[s[j]-'a']++;
            v1[s[i]-'a']--;
            if(v1==v2) ve.push_back(i+1);
        }
        return ve;
    }
};