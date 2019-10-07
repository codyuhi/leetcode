class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }
        if(pushed.size() == 0){
            return true;
        }
        stack<int> myStack;
        myStack.push(pushed[0]);
        int pushedValue = 1;
        int poppedValue = 0;
        while(pushedValue != pushed.size() || poppedValue != pushed.size()){
            if(myStack.size() > 0){
                if(myStack.top() == popped[poppedValue]){
                    myStack.pop();
                    poppedValue++;
                }else if(pushedValue < pushed.size()){
                    myStack.push(pushed[pushedValue]);
                    pushedValue++;
                }else{
                    return false;
                }
            }else{
                if(pushedValue < pushed.size()){
                    myStack.push(pushed[pushedValue]);
                    pushedValue++;
                }else{
                    return false;
                }
            }

        }
        return true;
    }
};