class Solution:
    def isPalindrome(x):
        str_x = str(x)
        lower_ptr = 0
        upper_ptr = len(str_x) - 1
        while lower_ptr < upper_ptr:
            if str_x[lower_ptr] != str_x[upper_ptr]:
                return False
            lower_ptr += 1
            upper_ptr -= 1
        return True

    def isPalindrome2(x):
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        reversed_x = 0
        while x > reversed_x:
            reversed_x = reversed_x * 10 + x % 10
            x //= 10
        return x == reversed_x or x == reversed_x // 10


INPUTS = [
    121,
    -121,
    10,
    1001
]

if __name__ == '__main__':
    sol = Solution
    for inp in INPUTS:
        print('1st:', sol.isPalindrome(inp))
        print('2nd:', sol.isPalindrome2(inp),'\n')