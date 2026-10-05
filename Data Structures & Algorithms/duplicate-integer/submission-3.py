class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        ans = set()
        for i in nums:
            ans.add(i)
        if(len(ans)!=len(nums)):
            return True
        return False