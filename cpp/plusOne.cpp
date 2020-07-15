class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        switch(digits.size()){
            case 0:
                digits.push_back(1);
                break;
            case 1:
                if(digits[0] < 9){
                    digits[0]++;
                }else{
                    digits[0] = 1;
                    digits.push_back(0);
                }
                break;
            default:
                for(int i = 0; i < digits.size(); i++){
                    if(digits[digits.size()-1-i] < 9){
                        digits[digits.size()-1-i]++;
                        break;
                    }else{
                        digits[digits.size()-1-i] = 0;
                        if(i == digits.size() - 1){
                            digits.insert(digits.begin(),1);
                        }
                    }
                }
                break;
        }
        return digits;
    }
};