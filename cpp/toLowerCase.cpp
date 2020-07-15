class Solution {
public:
    char cc(char given){
        switch(given){
            case 'A':
                return 'a';
                break;
            case 'B':
                return 'b';
                break;
            case 'C':
                return 'c';
                break;
            case 'D':
                return 'd';
                break;
            case 'E':
                return 'e';
                break;
            case 'F':
                return 'f';
                break;
            case 'G':
                return 'g';
                break;
            case 'H':
                return 'h';
                break;
            case 'I':
                return 'i';
                break;
            case 'J':
                return 'j';
                break;
            case 'K':
                return 'k';
                break;
            case 'L':
                return 'l';
                break;
            case 'M':
                return 'm';
                break;
            case 'N':
                return 'n';
                break;
            case 'O':
                return 'o';
                break;
            case 'P':
                return 'p';
                break;
            case 'Q':
                return 'q';
                break;
            case 'R':
                return 'r';
                break;
            case 'S':
                return 's';
                break;
            case 'T':
                return 't';
                break;
            case 'U':
                return 'u';
                break;
            case 'V':
                return 'v';
                break;
            case 'W':
                return 'w';
                break;
            case 'X':
                return 'x';
                break;
            case 'Y':
                return 'y';
                break;
            case 'Z':
                return 'z';
                break;  
        }
        return '0';
    }
    string toLowerCase(string str) {
        for(int i = 0; i < str.length(); i++){
            if(isupper(str[i])){
                str[i] = cc(str[i]);
            }
        }
        return str;
    }
};