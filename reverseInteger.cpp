#include <stdexcept>
class Solution {
public:
    int reverse(int x) {
        string k = to_string(x);
        string y = "";
        if(k[0] == '-'){
            y = "-";
        }
        for(int i = k.length() - 1; i >= 0; i--){
            y += k[i];
        }
        int z;
        try{
            z = stoi(y);
        }catch(std::out_of_range& e){
            return 0;
        }
        return z;
    }
};