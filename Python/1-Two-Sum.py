class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        tmp = dict()
        for i, n in enumerate(nums):
            diff = target - n
            if tmp.has_key(n):
                return list([tmp[n], i])
            else:
                tmp.update({diff: i})
        return list()
