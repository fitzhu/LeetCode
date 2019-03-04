class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, len(nums) - 1
        while left < right and nums[left] >= nums[right]:
            mid = left + (right - left) / 2
            if nums[mid] < nums[left]:
                right = mid
            else:
                left = mid + 1
        return nums[left]

if __name__ == '__main__':
    nums = [4,5,6,7,0,1]
    tmp = Solution()
    res = tmp.findMin(nums)
