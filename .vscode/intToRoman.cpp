class Solution {
public:
    string intToRoman(int num) {
        string finalString = "";
        int m = num / 1000;
        for(int ii = 0; ii < m; ii++){
            finalString += "M";
        }
        num %= 1000;
        int d = num / 500;
        num %= 500;
        int c = num / 100;
        num %= 100;
        if (c == 4 && d == 1){
            finalString += "CM";
        }  else if (c == 4 && d == 0){
            finalString += "CD";
        } else {
            for(int ii = 0; ii < d; ii++){
                finalString += "D";
            }
            for(int ii = 0; ii < c; ii++){
                finalString += "C";
            }
        }
        int l = num / 50;
        num %= 50;
        int x = num / 10;
        num %= 10;
        if (x == 4 && l == 1){
            finalString += "XC";
        }  else if (x == 4 && l == 0){
            finalString += "XL";
        } else {  
            for(int ii = 0; ii < l; ii++){
                finalString += "L";
            }
            for(int ii = 0; ii < x; ii++){
                finalString += "X";
            }
        }
        int v = num / 5;
        num %= 5;
        int i = num;
        if (i == 4 && v == 1){
            finalString += "IX";
        } else if (i == 4 && v == 0){
            finalString += "IV";
        } else {
            for(int ii = 0; ii < v; ii++){
                finalString += "V";
            }
            for(int ii = 0; ii < i; ii++){
                finalString += "I";
            }
        }
        return finalString;
    }
};