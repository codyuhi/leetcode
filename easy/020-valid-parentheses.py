class Solution:
    def isValid(self, s):
        if len(s) < 2:
            return False
        starting = ['(', '[', '{']
        ending = [')', ']', '}']
        stack = []
        for i in s:
            if i in starting:
                stack.append(i)
            else:
                if len(stack) == 0:
                    return False
                top = stack.pop()
                if top == '(' and i != ')':
                    return False
                elif top == '[' and i != ']':
                    return False
                elif top == '{' and i != '}':
                    return False
        if len(stack) != 0:
            return False
        return True


INPUTS = [
    "()",
    "()[]{}",
    "(]",
    '[',
    '((',
    "){"
]

if __name__ == '__main__':
    sol = Solution()
    for inp in INPUTS:
        print(f'\n"{inp}":')
        print(sol.isValid(inp))
