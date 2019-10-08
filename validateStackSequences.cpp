class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }
        stack<int> myStack;
        int poppedValue = 0;
        for(int i = 0; i < pushed.size(); i++){
            myStack.push(pushed[i]);
            while(poppedValue < popped.size() && myStack.top() == popped[poppedValue]){
                myStack.pop();
                poppedValue++;
                if(myStack.size() == 0){
                    break;
                }
            }
        }
        if(myStack.size() > 0){
            return false;
        }else{
            return true;
        }
    }
};