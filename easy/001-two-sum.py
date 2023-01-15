class Solution:
    def twoSum(nums, target):
        for i in range(len(nums)):
            if (target - nums[i]) in nums and i != nums.index(target-nums[i]):
                return [i, nums.index(target - nums[i])]

    def twoSum2(nums, target):
        hashmap = {}
        for i in range(len(nums)):
            hashmap[nums[i]] = i
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap and hashmap[complement] != i:
                return [i, hashmap[complement]]

    def twoSum3(nums, target):
        hashmap = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in hashmap:
                return [i, hashmap[complement]]
            hashmap[nums[i]] = i


INPUTS = {
    'test1': {
        'target': 9,
        'nums': [2, 7, 11, 15]
    },
    'test2': {
        'target': 6,
        'nums': [3, 2, 4]
    },
    'test3': {
        'target': 6,
        'nums': [3, 3]
    }
}

if __name__ == '__main__':
    sol = Solution
    for inp in INPUTS:
        print('1st:', sol.twoSum(INPUTS[inp]['nums'], INPUTS[inp]['target']))
        print('2nd:', sol.twoSum2(INPUTS[inp]['nums'], INPUTS[inp]['target']))
        print('3rd:', sol.twoSum3(INPUTS[inp]['nums'], INPUTS[inp]['target']),'\n')
