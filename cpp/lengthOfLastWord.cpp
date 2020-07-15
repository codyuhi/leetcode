class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 0)
            return 0;
        int count = 0;
        string::reverse_iterator rit=s.rbegin();
        while(*rit == ' ')
            ++rit;
        for(; rit!=s.rend(); ++rit)
        {
            if(*rit == ' ')
                break;
            count++;
        }
        return count;    
    }
};