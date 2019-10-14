class Solution {
public:
    int balancedStringSplit(string s) {
        stack<char> charStack;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(charStack.size() < 1){
                charStack.push(s[i]);
            }else if(charStack.top() != s[i]){
                charStack.pop();
                if(charStack.size() == 0){
                    count++;
                }
            }else{
                charStack.push(s[i]);
            }
        }
        return count;
    }
};