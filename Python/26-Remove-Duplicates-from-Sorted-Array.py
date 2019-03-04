class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        p_slow, p_fast = 0, 1
        while p_fast < len(nums):
            if nums[p_fast] == nums[p_slow]:
                p_fast += 1
            else:
                p_slow += 1
                nums[p_slow] = nums[p_fast]
                p_fast += 1
        return p_slow + 1
