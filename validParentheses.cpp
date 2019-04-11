class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stack.push(s[i]);
            }else if(stack.size() > 0){
                switch(s[i]){
                    case ')':
                        if(stack.top() != '('){
                            return false;
                        }
                        stack.pop();
                        break;
                    case ']':
                        if(stack.top() != '['){
                            return false;
                        }
                        stack.pop();
                        break;
                    case '}':
                        if(stack.top() != '{'){
                            return false;
                        }
                        stack.pop();
                        break;
                }
            }else{
                return false;
            }
        }
        if(stack.size() > 0){
            return false;
        }
        return true;
    }
};