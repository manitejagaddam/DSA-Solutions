class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        # mid = (start + end) / 2

        while start <= end:
            mid = (start + end) // 2
            if target == nums[mid]:
                return mid
            elif target > nums[mid]:
                start = mid + 1
            else:
                end = mid - 1
        return -1


        # for index, number in enumerate(nums):
        #     if number == target:
        #         return index
        # return -1
            

        