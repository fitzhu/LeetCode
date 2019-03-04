class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        l, r = 0, len(nums)
        while l < r:
            if nums[l] != val:
                l += 1
            else:
                r -= 1
                tmp = nums[l]
                nums[l] = nums[r]
                nums[r] = tmp
        return r
        