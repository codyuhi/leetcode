class Solution:

    def handleI(self, s, ptr):
        if ptr + 1 < len(s) and s[ptr + 1] == 'V':
            return (4, 2)
        if ptr + 1 < len(s) and s[ptr + 1] == 'X':
            return (9, 2)
        return (1, 1)

    def handleX(self, s, ptr):
        if ptr + 1 < len(s) and s[ptr + 1] == 'L':
            return (40, 2)
        if ptr + 1 < len(s) and s[ptr + 1] == 'C':
            return (90, 2)
        return (10, 1)

    def handleC(self, s, ptr):
        if ptr + 1 < len(s) and s[ptr + 1] == 'D':
            return (400, 2)
        if ptr + 1 < len(s) and s[ptr + 1] == 'M':
            return (900, 2)
        return (100, 1)

    def romanToInt(self, s):
        ptr = 0
        total = 0
        while ptr < len(s):
            if s[ptr] == 'I':
                i = self.handleI(s, ptr)
                total += i[0]
                ptr += i[1]
                continue
            if s[ptr] == 'V':
                ptr += 1
                total += 5
                continue
            if s[ptr] == 'X':
                x = self.handleX(s, ptr)
                total += x[0]
                ptr += x[1]
                continue
            if s[ptr] == 'L':
                ptr += 1
                total += 50
                continue
            if s[ptr] == 'C':
                c = self.handleC(s, ptr)
                total += c[0]
                ptr += c[1]
                continue
            if s[ptr] == 'D':
                ptr += 1
                total += 500
                continue
            if s[ptr] == 'M':
                ptr += 1
                total += 1000
                continue
        return total

    def romanToInt2(self, s):
        translations = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        total = 0
        s = s.replace('IV', 'IIII').replace('IX', 'VIIII')
        s = s.replace('XL', 'XXXX').replace('XC', 'LXXXX')
        s = s.replace('CD', 'CCCC').replace('CM', 'DCCCC')
        for char in s:
            total += translations[char]
        return total


INPUTS = [
    'I',
    'VI',
    'IV',
    'III',
    'LVIII',
    'MCMXCIV',
]

if __name__ == '__main__':
    sol = Solution()
    for inp in INPUTS:
        print(f'"{inp}":')
        print('1st:', sol.romanToInt(inp))
        print('2nd:', sol.romanToInt2(inp), '\n')
