class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        step = 1
        i = len(nums) - 2
        while i >= 0:
            if nums[i] >= step:
                step = 1
            else:
                step += 1
            i -= 1
        return step <= 1
