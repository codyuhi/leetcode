class Solution {
public:
    string addBinary(string a, string b) {
        //convert string to int form in order to work with it.
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if(a.length() < b.length()){
            string temp = a;
            a = b;
            b = temp;
        }
        bool carry = false;
        for(int i = 0; i < b.length(); i++){
            if(carry){
                if(b[i] == '1' || a[i] == '1'){
                    if(b[i] != '1' || a[i] != '1'){
                        a[i] = '0';
                    }
                }else{
                    a[i] = '1';
                    carry = false;
                }
            }else if(b[i] == '1' && a[i] == '1'){
                carry = true;
                a[i] = '0';
            }else if(b[i] == '1' || a[i] == '1'){
                a[i] = '1';
            }
        }
        if(carry){
            for(int i = b.length(); i < a.length(); i++){
                if(a[i] == '1'){
                    a[i] = '0';
                }else{
                    a[i] = '1';
                    carry = false;
                    break;
                }
            }
            if(carry){
                a += '1';
            }
        }
        reverse(a.begin(), a.end());
        return a;
    }
};

/*//this is another solution:
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s.insert(0,1,char(c % 2 + '0'));
            c /= 2;
        }
        
        return s;
    }
};
*/