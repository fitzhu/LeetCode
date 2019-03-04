class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l, r = 0, len(height) - 1
        res = 0
        while l < r:
            left, right = height[l], height[r]
            area = min(left, right) * (r - l)
            # update res
            res = area if area > res else res
            if left < right:
                l += 1
            else:
                r -= 1
        return res

if __name__ == '__main__':
    tmp = Solution()
    height = [1,8,6,2,5,4,8,3,7]
    res = tmp.maxArea(height)
