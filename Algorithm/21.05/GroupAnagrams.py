class Solution:

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for w in strs:
            key = ''.join(sorted(w))
            if key in d:
                d[key].append(w)
            else:
                d[key] = [w]
        return d.values()