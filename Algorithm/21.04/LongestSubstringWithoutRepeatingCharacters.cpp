// set 으로 풀면 될까? unordered_set
// 아니면 해시맵도 ㄱㅊ
// set 2개 만듦 s1, s2
// s1 에 하나씩 순회하면서 넣고, 만약 중복되는 값이 들어오면, s2 와 사이즈 비교, 초기화
// 1개만 만들어도 될 듯? 값 ret 로 하고 ret = max(ret, s2.size()) 이렇게
// 그럼 이건 greedy 알고리즘이 맞나? 중복값이 오면 무조건 종료하는 게 최댓값을 찾는 길이라는 증명?
// a,s,d,a,f,g,h,j 가 왔을 때 내가 한 것 처럼 하면 a,s,d 3 a,f,g,h,j ret = 5
// 근데 사실 답은 s,d,a,f,g,h,j ret=7 임
// 그리디 아닌듯? 그럼 
// 투포인터 p1,p2 라고 해서 풀면 어때
// a,s,d,f,d,p,y,u,i
// 투포인터 적용하면서, 있는 값과 만났을 때 ret 값을 갱신하고, 원래 있던 값 이후 index 를 p1 으로
// 이후 계속 진행, 만약 끝에 도달하면 ret 값 갱신, return ret;
// 어때 이방식은? 괜찮은듯
class Solution {
    unordered_set<char> st;
    // unordered_map<char,int> mp;
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int p1=0, p2=0;
        while(p2<s.size()){
            char ch = s[p2];
            if(st.find(ch) ==st.end()){
                st.insert(ch);
                ret = max(ret, p2-p1+1);
            }
            else{
                while(p1!=p2 && s[p1]!=s[p2])
                    st.erase(s[p1++]);
                st.erase(s[p1++]);
                st.insert(s[p2]);
                ret = max(p2-p1, ret);
            }
            p2++;
        }

        return ret;
    }
};