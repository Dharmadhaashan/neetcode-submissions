class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ans = {}
        for i in s:
            if i not in ans:
                ans[i] = 0
            ans[i] += 1
        for i in t:
            if i not in ans:
                ans[i] = 0
            ans[i] -= 1
        for i in ans:
            if ans[i]!=0:
                return False
        return True