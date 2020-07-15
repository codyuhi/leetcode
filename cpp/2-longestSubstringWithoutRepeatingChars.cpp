// Runtime: 4 ms, faster than 99.30% of C++ online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 9.3 MB, less than 86.07% of C++ online submissions for Longest Substring Without Repeating Characters.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alpha[128] = {0};
        for(int i = 0; i < 128; ++i)
            alpha[i] = -1;
        int max = 0, count = 0;
        int start = 0;
        for(size_t i = 0; i < s.size(); ++i) {
            if(alpha[s[i]] < 0) {
                ++count;
            }
            else {  //当前字符与前面有重复
                if(max < count) {
                    max = count;
                }
                if(start < alpha[s[i]]) {
                    start = alpha[s[i]];
                }
                count = i - start;
            }
            alpha[s[i]] = i;
        }
        if(max < count)
            max = count;
        
        return max;
    }
};