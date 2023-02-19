class Solution:
    # This is memory efficient but not speed efficient
    # The delete operation takes up more time than the average
    def removeDuplicates(self, nums):
        ptr = 1
        val = nums[0]
        while ptr < len(nums):
            if val == nums[ptr]:
                del nums[ptr]
            else:
                val = nums[ptr]
                ptr += 1
        return len(nums)

    # This is both memory and speed efficient
    # Instead of updating the values of all indexes in list because of delete operation from above,
    # This one simply updates the required indexes in-place and leaves the rest of the indexes as-is
    # This means for each update step, you only update one index instead of every index after the ptr
    def removeDuplicates2(self, nums):
        size = len(nums)
        insertIndex = 1
        for i in range(1, size):
            if nums[i - 1] != nums[i]:
                nums[insertIndex] = nums[i]
                insertIndex += 1
        return insertIndex


INPUTS = [
    [1, 1, 2],
    [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
]

if __name__ == '__main__':
    sol = Solution()
    for inp in INPUTS:
        original_input = inp
        print(f'\n"{inp}":')

        result = sol.removeDuplicates(inp)
        print(f'1st:\nk = {result}\nnums = {inp}\n')
        inp = original_input

        result = sol.removeDuplicates2(inp)
        print(f'2nd:\nk = {result}\nnums = {inp}\n')
        inp = original_input
