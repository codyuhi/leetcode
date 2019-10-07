class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }
        if(pushed.size() == 0){
            return true;
        }
        // cout << "pushed.size() is " << pushed.size() << endl;
        stack<int> myStack;
        // cout << "Initialized stack." << endl;
        // cout << "pushed[0] is " << pushed[0] << endl;
        myStack.push(pushed[0]);
        // cout << "Pushed " << pushed[0] << endl;
        int pushedValue = 1;
        // cout << "pushedValue is " << pushedValue << endl;
        int poppedValue = 0;
        while(pushedValue != pushed.size() || poppedValue != pushed.size()){
            if(myStack.size() > 0){
                // cout << "myStack.top() is " << myStack.top() << endl;
                if(myStack.top() == popped[poppedValue]){
                    myStack.pop();
                    // cout << "Popped " << popped[poppedValue] << endl;
                    poppedValue++;
                    // cout << "poppedValue is " << poppedValue << endl;
                }else if(pushedValue < pushed.size()){
                    myStack.push(pushed[pushedValue]);
                    // cout << "Pushed " << pushed[pushedValue] << endl;
                    pushedValue++;
                    // cout << "pushedValue is " << pushedValue << endl;
                }else{
                    return false;
                }
            }else{
                // cout << "myStack is empty." << endl;
                if(pushedValue < pushed.size()){
                    myStack.push(pushed[pushedValue]);
                    // cout << "Pushed " << pushed[pushedValue] << endl;
                    pushedValue++;
                    // cout << "pushedValue is " << pushedValue << endl;
                }else{
                    return false;
                }
            }

        }
        return true;
    }
};