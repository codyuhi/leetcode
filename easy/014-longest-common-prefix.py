class Solution:
    def longestCommonPrefix(self, strs):
        prefix = ''
        ptr = 0
        while ptr < len(strs[0]):
            prefix += strs[0][ptr]
            for string in strs:
                if len(string) <= ptr:
                    return prefix[:-1]
                if string[ptr] != strs[0][ptr]:
                    return prefix[:-1]
            ptr += 1
        return prefix

    def isCommonPrefix(self, strs, length):
        str1 = strs[0][0:length]
        for i in range(len(strs)):
            if strs[i].startswith(str1):
                return False
        return True

    # DOESN"T WORK. TODO: IMPLEMENT BINARY SEARCH
    def longestCommonPrefix2(self, strs):
        if not strs or len(strs) == 0:
            return ''
        minLen = 200
        for string in strs:
            if minLen > len(string):
                minLen = len(string)
        low = 1
        high = minLen
        while low <= high:
            middle = (low + high) // 2
            if self.isCommonPrefix(strs, middle):
                low = middle + 1
            else:
                high = middle - 1
        print(low, high)
        return strs[0][0:(low + high) // 2]


INPUTS = [
    ['flower', 'flow', 'flight'],
    ['dog', 'racecar', 'car'],
    ['ab', 'a']
]

if __name__ == '__main__':
    sol = Solution()
    for inp in INPUTS:
        print(f'\n"{inp}":')
        print(f'1: {sol.longestCommonPrefix(inp)}')
        print(f'2: {sol.longestCommonPrefix2(inp)}')

