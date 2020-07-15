class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if len(pushed) != len(popped):
            return False
        myStack = []
        poppedVal = 0
        for i in pushed:
            myStack.append(i)
            while myStack and poppedVal < len(popped) and myStack[-1] == popped[poppedVal]:
                myStack.pop()
                poppedVal += 1
        return poppedVal == len(popped)
