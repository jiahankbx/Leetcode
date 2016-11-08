class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = len(nums)-1
        while i > 0 and nums[i-1] >= nums[i]:
            i -= 1
        # find the right most digit greater than nums[i-1]
        if i > 0:
            j = len(nums)-1
            while nums[j] <= nums[i-1]:
                j -= 1
            nums[i-1], nums[j] = nums[j], nums[i-1]
        # reverse the list from ith to end
        j = len(nums) - 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1 
        return
        
跟我的c++原理一样。 
52ms beat 96%
