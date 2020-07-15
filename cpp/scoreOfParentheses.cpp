class Solution {
public:
    int scoreOfParentheses(string S) {
        int count = 0;
        int recurse = 0;
        int repeat = 0;
        int score = 0;
        for(int i = 0; i < S.length(); i++){
            if(S[i] == '('){
                count++;
            }else{
                if(count != 1){
                    count--;

                }else{
                    count--;
                    score++;
                }
            }
        }
        return score;
    }
};