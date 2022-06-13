class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        sd = {'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
        ret = 0
        st = ''
        for ch in s:
            st += ch
            if len(st) == 2:
                if st in sd:
                    ret += sd[st]
                    st = ''
                else:

                    ret += d[st[0]]
                    st = st[1]
        if st:
            ret += d[st]

        return ret


class Solution:
    def romanToInt(self, s: str) -> int:
        d = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000
        }
        ret = 0

        for i in range(0, len(s)-1):
            if d[s[i]] < d[s[i+1]]:
                ret -= d[s[i]]
            else:
                ret += d[s[i]]

        return ret + d[s[-1]]
