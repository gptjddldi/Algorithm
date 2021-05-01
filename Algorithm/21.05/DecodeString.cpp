// 스택 사용
// 스트링에서 해당 글자가 숫자인줄 어케 암?
// 매우 어려웠음;
class Solution {
public:
    string decodeString(string s) {
        string ret;
        stack<int>nums;
        stack<string> chars;
        int num=0;
        for(char c : s){
            if(isdigit(c)){
                num = num*10 + (c-'0'); //숫자가 한 자리가 아닐 수 있구나.
                
            }
            else if(c == '['){
                chars.push(ret);
                nums.push(num);
                ret = "";
                num = 0;
            }
            else if (c==']'){
                string tmp = ret;
                for(int i=0; i<nums.top()-1; ++i){
                    ret += tmp;
                }
                ret = chars.top() + ret;
                chars.pop(); nums.pop();
            }
            else if(isalpha(c)){
                ret.push_back(c);
            }
        }
        return ret;
    }
};

// 처음 생각은 이런 recursion 인데 나는 구현을 실패했고, 누구는 성공했길래 따라해봄. 어렵다.
class Solution {
public:
    string rec(string s, int& i){
        string res;
        while(i<s.size() && s[i] !=']'){
            if(!isdigit(s[i]))
                res += s[i++];
            else{
                int n = 0;
                while(i<s.size() && isdigit(s[i]))
                    n = n*10 + s[i++] - '0';
                i++; //'['
                string t = rec(s,i);
                i++; //']'
                while(n-->0) res += t;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i=0;
        return rec(s, i);
    }
};