class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool on = !(n % 2);
        while(n > 0){
            bool t = n % 2;
            if(t){
                if(on){
                    return false;
                }else{
                    on = true;
                }
            }else{
                if(!on){
                    return false;
                }else{
                    on = false;
                }
            }
            n /= 2;
        }
        return true;
    }
};