class Solution {
public:
    string addBinary(string a, string b) {
        //convert string to int form in order to work with it.
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.length() < b.length()){
            for(int i = 0; i < a.length(); i++){
                if(a[i] == '1'){
                    if(b[i] == '1'){

                    }else{
                        b[i] = '1';
                    }
                }
            }
            reverse(b.begin(), b.end());
            return b;
        }else{
            for(int i = 0; i < b.length(); i++){
                if(b[i] == '1'){
                    if(a[i] == '1'){
                        if(i >= b.length()-1){
                            a[i] = '0';
                            a += '1';
                        }else{
                            
                        }
                    }else{
                        a[i] = '1';
                    }
                }
            }
            reverse(a.begin(), a.end());
            return a;
        }
    }
};